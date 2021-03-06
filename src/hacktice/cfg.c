#include "cfg.h"
#include "binary.h"
#include "array_size.h"
#include "string_conv.h"
#include "strings.h"

#include "types.h"
#include "game/ingame_menu.h"
#include "engine/math_util.h"

typedef enum Pages
{
    Pages_CHECKPOINTS,
    Pages_GENERAL,
    Pages_WARP,
    Pages_PagesCount,
} Pages;

static int sPage = Pages_GENERAL;
// poor man constexpr
#define sMaxAllowedPage (Pages_PagesCount - 1)
static u8* lPageNames[] = { uCHECKPOINTS, uGENERAL, uWARP };

Hacktice_Config sConfig = {
    .timerShow = true,
    .timerStyle = Config_TimerStyle_GRAB,
};

typedef struct ConfigDescriptor
{
    char* value;
    u8* name;
    u8** valueNames;
    char maxValueCount;
} ConfigDescriptor;

// Config_StickStyle
static u8* inputValueNames[] = { uOFF, uTEXT, uGRAPHICS };
static u8* onOffValueNames[] = { uOFF, uON };
static u8* timerValueNames[] = { uGRAB, uXCAM };
static u8* stateSaveNames[]  = { uBUTTON, uPAUSE };
static u8* deathActionNames[] = { uOFF, uACT_SELECT, uLEVEL_RESET, uLOAD_STATE };

// Config_ButtonAction
static u8* lActionNames[]    = { uOFF, uACT_SELECT, uLEVEL_RESET, uLEVEL_RESET_WARP, uLEVITATE, uLOAD_STATE };

static u8 lMusicNumber[] = { 0x00, 0x00, 0xff };
static u8* lMusicNumbers[] = { lMusicNumber, NULL };

u8 sOnDeathAction = 0;

#define VALUE_NAMES(x) x, ARRAY_SIZE(x)
#define INT_NAMES(x, cnt) x, cnt

// Checkpoints
static ConfigDescriptor sCheckpointsDescriptors[] =
{
    { &sConfig.checkpointBurning,     uBURNING,     VALUE_NAMES(onOffValueNames) },
    { &sConfig.checkpointCannon,      uCANNON,      VALUE_NAMES(onOffValueNames) },
    { &sConfig.checkpointCoin,        uCOIN,        VALUE_NAMES(onOffValueNames) },
    { &sConfig.checkpointDoor,        uDOOR,        VALUE_NAMES(onOffValueNames) },
    { &sConfig.checkpointGroundpound, uGROUNDPOUND, VALUE_NAMES(onOffValueNames) },
    { &sConfig.checkpointLava,        uLAVA,        VALUE_NAMES(onOffValueNames) },
    { &sConfig.checkpointObject,      uOBJECT,      VALUE_NAMES(onOffValueNames) },
    { &sConfig.checkpointPlatform,    uPLATFORM,    VALUE_NAMES(onOffValueNames) },
    { &sConfig.checkpointPole,        uPOLE,        VALUE_NAMES(onOffValueNames) },
    { &sConfig.checkpointRed,         uRED,         VALUE_NAMES(onOffValueNames) },
    { &sConfig.checkpointWallkick,    uWALLKICK,    VALUE_NAMES(onOffValueNames) },
    { &sConfig.checkpointWarp,        uWARP,        VALUE_NAMES(onOffValueNames) },
};
#define sCheckpointsMaxAllowedOption (sizeof(sCheckpointsDescriptors) / sizeof(*sCheckpointsDescriptors) - 1)

// General
static ConfigDescriptor sGeneralDescriptors[] = 
{
    { &sConfig.distanceFromClosestRed,    uDISTANCE_TO_RED, VALUE_NAMES(onOffValueNames) },
    { &sConfig.distanceFromClosestSecret, uDISTANCE_TO_SECRET, VALUE_NAMES(onOffValueNames) },
    
    { &sConfig.showButtons,   uBUTTONS,       VALUE_NAMES(onOffValueNames) },
    { &sConfig.stickStyle,    uSTICK,         VALUE_NAMES(inputValueNames) },

    { &sConfig.lAction,       uLACTION,           VALUE_NAMES(lActionNames) },
    { &sConfig.lRAction,      uLRACTION,          VALUE_NAMES(lActionNames) },
    { &sConfig.cButtonsAction,u4_CBUTTONS_ACTION, VALUE_NAMES(lActionNames) },
    { &sConfig.dpadDownAction,uDPAD_DOWN_ACTION,  VALUE_NAMES(lActionNames) },
    { &sConfig.muteMusic,     uMUTE_MUSIC,    VALUE_NAMES(onOffValueNames) },
    
    { &sConfig.deathAction,   uDEATH_ACTION,  VALUE_NAMES(deathActionNames) },

    { &sConfig.musicNumber,   uMUSIC_NUMBER,  lMusicNumbers, 64 },
    { &sConfig.stateSaveStyle, uSSAVESTYLE,   VALUE_NAMES(stateSaveNames) },
    { &sConfig.speed,         uSPEED,         VALUE_NAMES(onOffValueNames) },
    { &sConfig.timerShow,     uTIMER,         VALUE_NAMES(onOffValueNames) },
    { &sConfig.timerStyle,    uTIMERSTYLE,    VALUE_NAMES(timerValueNames) },
    { &sConfig.timerStopOnCoinStar, uTIMER100,VALUE_NAMES(onOffValueNames) },
    { &sConfig.wallkickFrame, uWALLKICKFRAME, VALUE_NAMES(onOffValueNames) },
};
#define sGeneralMaxAllowedOption (sizeof(sGeneralDescriptors) / sizeof(*sGeneralDescriptors) - 1)

// Warp
static ConfigDescriptor sWarpDescriptors[] = {
    { &sConfig.warp, uSELECT_WARP_TARGET, NULL, 25 },
};
#define sWarpMaxAllowedOption 0

// Common
static ConfigDescriptor* sDescriptors[] = 
{
    sCheckpointsDescriptors,
    sGeneralDescriptors,
    sWarpDescriptors,
};
static int sPickedOptions[3] = {
    sCheckpointsMaxAllowedOption / 2,
    sGeneralMaxAllowedOption     / 2,
    sWarpMaxAllowedOption        / 2,
};
static int sMaxAllowedOptions[3] = {
    sCheckpointsMaxAllowedOption,
    sGeneralMaxAllowedOption,
    sWarpMaxAllowedOption,
};

static void print_generic_string_centered(s16 x, s16 y, u8 *str)
{
    s16 newX = GET_STR_X_POS_FROM_CENTER(x, str, 10.f);
    print_generic_string(newX, y, str);
}

static void renderOptionAt(ConfigDescriptor* desc, int x, int y)
{
    int value = *desc->value;
    
    print_generic_string_centered(x, y,      desc->name);
    if (desc->name == uSELECT_WARP_TARGET)
    {
        u8* courseName = uOFF;
        if (0 != value)
        {
            u8** courseNameTbl = (u8**) segmented_to_virtual(sCourseNames);
            int id = value - 1;
            courseName = (u8*) segmented_to_virtual(courseNameTbl[id]);
        }
        print_generic_string_centered(x, y - 20, courseName);
    }
    else
    {
        if (NULL != desc->valueNames[1])
        {
            print_generic_string_centered(x, y - 20, desc->valueNames[(int) value]);
        }
        else
        {
            String_convert(value, desc->valueNames[0]);
            print_generic_string_centered(x, y - 20, desc->valueNames[0]);
        }
    }
}

static void render()
{
    int pickedOption = sPickedOptions[sPage];
    int maxAllowedOption = sMaxAllowedOptions[sPage]; 
    ConfigDescriptor* descriptors = sDescriptors[sPage];

    print_generic_string_centered(160, 210, lPageNames[(int) sPage]);

    const int height = 190;
    if (pickedOption >= 2)
    {
        renderOptionAt(&descriptors[pickedOption - 2], 0, height);
    }
    
    if (pickedOption >= 1)
    {
        renderOptionAt(&descriptors[pickedOption - 1], 80, height);
    }

    renderOptionAt(&descriptors[pickedOption], 160, height);

    if (pickedOption <= maxAllowedOption - 1)
    {
        renderOptionAt(&descriptors[pickedOption + 1], 240, height);
    }

    if (pickedOption <= maxAllowedOption - 2)
    {
        renderOptionAt(&descriptors[pickedOption + 2], 320, height);
    }
}

static void processInputs()
{
    int* pickedOption = &sPickedOptions[sPage];
    ConfigDescriptor* desc = &sDescriptors[sPage][*pickedOption];
    int maxAllowedOption = sMaxAllowedOptions[sPage]; 

    if (gControllers->buttonPressed & L_JPAD)
    {
        if (*pickedOption != 0)
        {
            (*pickedOption)--;
            return;
        }
    }
    if (gControllers->buttonPressed & R_JPAD)
    {
        if ((*pickedOption) != maxAllowedOption)
        {
            (*pickedOption)++;
            return;
        }
    }
    if (gControllers->buttonPressed & U_CBUTTONS)
    {
        if ((*desc->value) != desc->maxValueCount - 1)
        {
            (*desc->value)++;
            return;
        }
    }
    if (gControllers->buttonPressed & D_CBUTTONS)
    {
        if ((*desc->value) != 0)
        {
            (*desc->value)--;
            return;
        }
    }
    if (gControllers->buttonPressed & Z_TRIG)
    {
        if (sPage != 0)
        {
            sPage--;
            return;
        }
    }
    if (gControllers->buttonPressed & R_TRIG)
    {
        if (sPage != sMaxAllowedPage)
        {
            sPage++;
            return;
        }
    }

    if (desc->maxValueCount > 10)
    {
        int controllerDistance = (int)gControllers->rawStickX * (int)gControllers->rawStickX + (int)gControllers->rawStickY * (int)gControllers->rawStickY;
        if (controllerDistance > 1000)
        {
            u16 angle = atan2s(gControllers->rawStickY, gControllers->rawStickX);
            float normalizedAngle = (float) angle / (float) 0x10000;
            *desc->value = (int) (normalizedAngle * desc->maxValueCount);
        }
    }
}

void Config_onPause()
{
    render();
    processInputs();
}

LevelConv_PlainLevels Config_warpIdAndReset()
{
    int w = Config_warpId();
    sConfig.warp = 0;
    sPage = Pages_GENERAL;
    return w;
}   

#define BUTTONS_PRESSED(mask) (((gControllers->buttonDown) & (mask)) == (mask))

Config_ButtonAction Config_action()
{
    if (sOnDeathAction)
    {
        return (Config_ButtonAction) sOnDeathAction;
    }

    if (sConfig.lRAction && BUTTONS_PRESSED(L_TRIG | R_TRIG))
    {
        return (Config_ButtonAction) sConfig.lRAction;
    }
    else if (sConfig.lAction && BUTTONS_PRESSED(L_TRIG))
    {
        return (Config_ButtonAction) sConfig.lAction;
    }
    else if (sConfig.cButtonsAction && BUTTONS_PRESSED(U_CBUTTONS | D_CBUTTONS | R_CBUTTONS | L_CBUTTONS))
    {
        return (Config_ButtonAction) sConfig.cButtonsAction;
    }
    else if (sConfig.dpadDownAction && BUTTONS_PRESSED(D_JPAD))
    {
        return (Config_ButtonAction) sConfig.dpadDownAction;
    }

    return Config_ButtonAction_OFF;
}
