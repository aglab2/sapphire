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
#include "levels/pss/header.h"

const LevelScript level_pss_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _pss_segment_7SegmentRomStart, _pss_segment_7SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _mountain_mio0SegmentRomStart, _mountain_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group8_mio0SegmentRomStart, _group8_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0xa, _wdw_skybox_mio0SegmentRomStart, _wdw_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x06, _group15_mio0SegmentRomStart, _group15_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_9), 
	JUMP_LINK(script_func_global_16), 

	AREA(1, pss_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 0x01, 0xDE, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0xee, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_CCM, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 1959, 4661, 10805, 0, 122, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 6843, 3246, 9564, 0, -147, 0, 0x00000000, bhvFlamethrower),
		OBJECT(MODEL_NONE, 2939, 1414, 4469, 0, -147, 0, 0x00000000, bhvFlamethrower),
		OBJECT(MODEL_NONE, 297, -399, -1207, 0, -147, 0, 0x00000000, bhvFlamethrower),
		OBJECT(MODEL_NONE, -3631, -2228, -6335, 0, -147, 0, 0x00000000, bhvFlamethrower),
		OBJECT(MODEL_CAP_SWITCH, -6003, -4049, -13235, 0, -57, 0, 0x00020000, bhvCapSwitch),
		OBJECT(MODEL_CAP_SWITCH, -6411, -4049, -13848, 0, -57, 0, 0x00000000, bhvCapSwitch),
		OBJECT(MODEL_CAP_SWITCH, -5591, -4049, -12564, 0, -57, 0, 0x00010000, bhvCapSwitch),
		OBJECT(MODEL_STAR, -5549, -3849, -13549, 0, -147, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_TOAD, 698, 4851, 11564, 0, 123, 0, 0x4c000000, bhvToadMessage),
		TERRAIN(pss_area_1_collision),
		MACRO_OBJECTS(pss_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x23),
		TERRAIN_TYPE(TERRAIN_SLIDE),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
