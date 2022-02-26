#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/jrb/header.h"

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _water_mio0SegmentRomStart, _water_mio0SegmentRomEnd), 
	LOAD_MIO0(0x0A, _cloud_floor_skybox_mio0SegmentRomStart, _cloud_floor_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group4_mio0SegmentRomStart, _group4_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group17_mio0SegmentRomStart, _group17_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PALM_TREE, palm_tree_geo), 
	LOAD_MODEL_FROM_GEO(0x37, newspindel_geo), 
	LOAD_MODEL_FROM_GEO(0x38, updownthing_geo), 

	AREA(1, jrb_area_1),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0xD3, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0xE3, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1C, LEVEL_BOB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(0x89, -4563, 775, 3985, 0, 0, 0, 0x00010000, bhvExclamationBox),
		OBJECT(0x81, 2798, 89, 4414, 0, 20, 0, 0x00000000, bhvHiddenObject),
		OBJECT(0x81, 3258, 395, 4243, 0, 20, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_STAR, 3707, 970, 3774, 0, 20, 0, 0x00000000, bhvStar),
		OBJECT(0x89, 2853, 76, -1021, 0, 0, 0, 0x00060000, bhvExclamationBox),
		OBJECT(0xC3, -1562, 1079, -2423, 0, 0, 0, 0x00000000, bhvBobombBuddyOpensCannon),
		OBJECT(0x37, -5448, 1001, -1432, 0, 0, 0, 0x00000000, bhvSpindel),
		OBJECT(0, -1149, -415, 1562, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(0x37, -5448, 1870, -1432, 0, 0, 0, 0x00000000, bhvSpindel),
		OBJECT(0x37, -5448, 2738, -1432, 0, 0, 0, 0x00000000, bhvSpindel),
		OBJECT(0, -5460, 132, -1897, 0, 0, 0, 0x00570000, bhvPoleGrabbing),
		OBJECT(0, -5460, 1001, 1701, 0, 0, 0, 0x00570000, bhvPoleGrabbing),
		OBJECT(0, -5460, 1870, -1896, 0, 0, 0, 0x00570000, bhvPoleGrabbing),
		OBJECT(MODEL_STAR, -5488, 2938, 1772, 0, 20, 0, 0x04000000, bhvStar),
		OBJECT(0, -5438, 41, 17, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(0, -1254, 24, -2361, 0, 0, 0, 0x03000000, bhvHiddenRedCoinStar),
		OBJECT(0xC9, -36, 97, -2427, 0, 0, 0, 0x00000000, bhvCannonClosed),
		OBJECT(MODEL_STAR, 11966, 203, 972, 0, 20, 0, 0x01000000, bhvStar),
		OBJECT(0, 1711, 132, 1127, 0, 0, 0, 0x00020000, bhvCoinFormation),
		OBJECT(0x38, 3344, 1383, -2408, 0, 0, 0, 0x00010000, bhvSslMovingPyramidWall),
		OBJECT(0x38, 3344, 2298, -2424, 0, 0, 0, 0x00010000, bhvSslMovingPyramidWall),
		OBJECT(MODEL_STAR, 3871, 1583, -2398, 0, 20, 0, 0x02000000, bhvStar),
		OBJECT(0, 2169, -232, -2434, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(0, -1159, -96, -6285, 0, 0, 0, 0x00020000, bhvCoinFormation),
		OBJECT(MODEL_AMP, -3471, -242, -10726, 0, 0, 0, 0x00020000, bhvCirclingAmp),
		OBJECT(MODEL_AMP, 389, -242, -10885, 0, 0, 0, 0x00020000, bhvCirclingAmp),
		OBJECT(0, -5449, -50, -3241, 0, -12, 0, 0x00000000, bhvCoinFormation),
		OBJECT(0xCF, -1265, -598, 3988, 0, 5, 0, 0x00000000, bhvFloorSwitchHiddenObjects),
		OBJECT(0x81, 2067, -145, 4502, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(0x89, -2081, 124, -2352, 0, 0, 0, 0x00060000, bhvExclamationBox),
		OBJECT(0, -1189, 889, 7402, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_SSL_PALM_TREE, 362, -232, 5290, 0, -180, 0, 0x000A0000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -3546, -234, 4331, 0, -180, 0, 0x000A0000, bhvTree),
		OBJECT(MODEL_SCUTTLEBUG, -2737, -232, 4762, 0, -71, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, 653, -232, 4517, 0, -180, 0, 0x00000000, bhvScuttlebug),
		OBJECT(0x58, 2477, -1269, 7773, 0, 30, 0, 0x000A0000, bhvClamShell),
		OBJECT(MODEL_SSL_PALM_TREE, 811, -232, 3557, 0, -180, 0, 0x000A0000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -3072, -232, 5425, 0, -180, 0, 0x000A0000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -3167, -232, 284, 0, -180, 0, 0x000A0000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -5518, 132, 1706, 0, -180, 0, 0x000A0000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -5567, 41, -450, 0, -180, 0, 0x000A0000, bhvTree),
		OBJECT(MODEL_SCUTTLEBUG, -3952, 132, 1348, 0, -94, 0, 0x00000000, bhvScuttlebug),
		OBJECT(0x58, -3411, -1269, 8304, 0, 120, 0, 0x000A0000, bhvClamShell),
		OBJECT(0x58, -6101, -1269, 5551, 0, -174, 0, 0x000A0000, bhvClamShell),
		OBJECT(0xD7, -5398, -1269, 6994, 0, -174, 0, 0x000A0000, bhvRedCoin),
		OBJECT(MODEL_GOOMBA, 5232, 32, 1263, 0, -174, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 6762, 32, 1432, 0, -174, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 8279, 32, 1252, 0, -174, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 9804, 32, 1075, 0, -174, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_SSL_PALM_TREE, 1836, 132, 2058, 0, -180, 0, 0x000A0000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 2722, -232, -25, 0, -180, 0, 0x000A0000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 587, -232, 278, 0, -180, 0, 0x000A0000, bhvTree),
		OBJECT(MODEL_SCUTTLEBUG, 1949, -232, -305, 0, -180, 0, 0x00000000, bhvScuttlebug),
		OBJECT(0xD7, -613, -1268, 8869, 0, -174, 0, 0x000A0000, bhvRedCoin),
		OBJECT(0xD7, 3739, -1267, 6654, 0, -174, 0, 0x000A0000, bhvRedCoin),
		OBJECT(0x58, 4115, -1269, 5233, 0, -88, 0, 0x000A0000, bhvClamShell),
		OBJECT(0xD7, -482, -962, -1700, 0, -174, 0, 0x000A0000, bhvRedCoin),
		OBJECT(0xD7, -1792, -961, -3224, 0, -174, 0, 0x000A0000, bhvRedCoin),
		OBJECT(0x58, -2006, -964, -1662, 0, -138, 0, 0x000A0000, bhvClamShell),
		OBJECT(0x58, -251, -964, -3034, 0, 115, 0, 0x000A0000, bhvClamShell),
		OBJECT(MODEL_SSL_PALM_TREE, 3005, -324, -3309, 0, -180, 0, 0x000A0000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 1556, -232, -5261, 0, -180, 0, 0x000A0000, bhvTree),
		OBJECT(0x8C, -1166, -96, -6269, 0, 140, 0, 0x00000000, bhvBlueCoinSwitch),
		OBJECT(MODEL_BLUE_COIN, -892, -282, -9633, 0, 140, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1595, -282, -9642, 0, 140, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -2116, -282, -9632, 0, 140, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_SCUTTLEBUG, 1528, -232, -4461, 0, -51, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SSL_PALM_TREE, -1266, -247, -5102, 0, -180, 0, 0x000A0000, bhvTree),
		OBJECT(0xD7, -5452, -1262, -9259, 0, -174, 0, 0x000A0000, bhvRedCoin),
		OBJECT(0xD7, -1143, -1239, -11064, 0, -174, 0, 0x000A0000, bhvRedCoin),
		OBJECT(0xD7, 3050, -1265, -9288, 0, -174, 0, 0x000A0000, bhvRedCoin),
		OBJECT(0x58, -6085, -1269, -7791, 0, 145, 0, 0x000A0000, bhvClamShell),
		OBJECT(0x58, -3958, -1269, -11307, 0, 9, 0, 0x000A0000, bhvClamShell),
		OBJECT(0x58, 1370, -1269, -10710, 0, -152, 0, 0x000A0000, bhvClamShell),
		OBJECT(0x58, 3903, -1269, -7987, 0, -61, 0, 0x000A0000, bhvClamShell),
		OBJECT(MODEL_SSL_PALM_TREE, 83, -232, -6633, 0, -180, 0, 0x000A0000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -2558, -232, -6995, 0, -180, 0, 0x000A0000, bhvTree),
		OBJECT(MODEL_SCUTTLEBUG, -3317, -232, -4893, 0, -51, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SSL_PALM_TREE, -3139, -232, -6021, 0, -180, 0, 0x000A0000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -4257, -232, -2480, 0, -180, 0, 0x000A0000, bhvTree),
		OBJECT(MODEL_YELLOW_COIN, -4740, -282, -9519, 0, 27, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -3455, -282, -10714, 0, 27, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 397, -282, -10862, 0, 27, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1627, -282, -9253, 0, 27, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1566, -82, -11903, 0, 27, 0, 0x00000000, bhvYellowCoin),
		OBJECT(0, -4740, -282, -9519, 0, 27, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(0, -3455, -282, -10714, 0, 27, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(0, 397, -282, -10862, 0, 27, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(0, 1627, -282, -9253, 0, 27, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(0, -1566, -82, -11903, 0, 27, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(0, -1167, 104, -6298, 0, 27, 0, 0x05000000, bhvHiddenStar),
		OBJECT(MODEL_CHUCKYA, -1557, -282, -11918, 0, 27, 0, 0x05000000, bhvChuckya),
		TERRAIN(jrb_area_1_collision),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x26),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};