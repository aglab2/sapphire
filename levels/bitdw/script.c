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
#include "levels/bitdw/header.h"

const LevelScript level_bitdw_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bitdw_segment_7SegmentRomStart, _bitdw_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _ssl_skybox_mio0SegmentRomStart, _ssl_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _sky_mio0SegmentRomStart, _sky_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group11_mio0SegmentRomStart, _group11_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group11_geoSegmentRomStart, _group11_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group17_mio0SegmentRomStart, _group17_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_12), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, geo_bitdw_0003C0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, geo_bitdw_0003D8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, geo_bitdw_0003F0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, geo_bitdw_000408), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, geo_bitdw_000420), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08, geo_bitdw_000438), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_09, geo_bitdw_000450), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A, geo_bitdw_000468), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0B, geo_bitdw_000480), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C, geo_bitdw_000498), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0D, geo_bitdw_0004B0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E, geo_bitdw_0004C8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0F, geo_bitdw_0004E0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_10, geo_bitdw_0004F8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_11, geo_bitdw_000510), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_SQUARE_PLATFORM, geo_bitdw_000558), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_SEESAW_PLATFORM, geo_bitdw_000540), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_SLIDING_PLATFORM, geo_bitdw_000528), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_FERRIS_WHEEL_AXLE, geo_bitdw_000570), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_BLUE_PLATFORM, geo_bitdw_000588), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_STAIRCASE_FRAME4, geo_bitdw_0005A0), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_STAIRCASE_FRAME3, geo_bitdw_0005B8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_STAIRCASE_FRAME2, geo_bitdw_0005D0), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_STAIRCASE_FRAME1, geo_bitdw_0005E8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_STAIRCASE, geo_bitdw_000600), 

	AREA(1, bitdw_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 0x01, 0xDF, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0xeF, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_CCM, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BOWSER_3, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 5820, 5111, -3895, 0, -180, 0, 0x000B0000, bhvDeathWarp),
		OBJECT(MODEL_NONE, 5813, 2737, -7023, 0, -180, 0, 0x005B0000, bhvPoleGrabbing),
		OBJECT(MODEL_BITDW_STAIRCASE, 5815, 3781, -5072, 0, -90, 0, 0x00010000, bhvAnimatesOnFloorSwitchPress),
		OBJECT(0xCF, 5811, 3788, -6390, 0, -180, 0, 0x005B0000, bhvFloorSwitchAnimatesObject),
		OBJECT(0x12, 5815, 4948, -4305, 0, -180, 0, 0x000C0000, bhvWarpPipe),
		OBJECT(MODEL_CHUCKYA, 3221, 2737, -10289, 0, -180, 0, 0x00000000, bhvChuckya),
		OBJECT(0x89, 5924, 3037, -7800, 0, -180, 0, 0x00050000, bhvExclamationBox),
		OBJECT(MODEL_NONE, -527, -1753, 386, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(0x10, -541, -2285, -1280, 0, -180, 0, 0x000A0000, bhvStaticObject),
		OBJECT(MODEL_BITDW_SEESAW_PLATFORM, -541, -2244, -4199, 0, -180, 0, 0x00000000, bhvSeesawPlatform),
		OBJECT(MODEL_BITDW_SEESAW_PLATFORM, -4541, -1303, -10421, 0, -90, 0, 0x00000000, bhvSeesawPlatform),
		OBJECT(MODEL_BITDW_SQUARE_PLATFORM, -851, -2285, -1590, 0, -180, 0, 0x00000000, bhvSquarishPathMoving),
		OBJECT(MODEL_BITDW_FERRIS_WHEEL_AXLE, -7563, -679, -10695, 0, 0, 0, 0x00010000, bhvFerrisWheelAxle),
		OBJECT(MODEL_BITDW_SQUARE_PLATFORM, -231, -2285, -970, 0, -180, 0, 0x00020000, bhvSquarishPathMoving),
		OBJECT(0x10, -541, -1919, -7146, 0, -180, 0, 0x000A0000, bhvStaticObject),
		OBJECT(MODEL_BITDW_SQUARE_PLATFORM, -231, -1919, -6836, 0, -180, 0, 0x00020000, bhvSquarishPathMoving),
		OBJECT(MODEL_BITDW_SQUARE_PLATFORM, -851, -1919, -7456, 0, -180, 0, 0x00000000, bhvSquarishPathMoving),
		OBJECT(0, -538, -2285, -1280, 0, -180, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_AMP, -540, -2303, -2614, 0, -180, 0, 0x00000000, bhvCirclingAmp),
		OBJECT(MODEL_AMP, -546, -1938, -5793, 0, -180, 0, 0x00000000, bhvCirclingAmp),
		OBJECT(0, -542, -1919, -7142, 0, -180, 0, 0x00000000, bhvMrI),
		OBJECT(0, -863, -1988, -8817, 0, -139, 0, 0x00040000, bhvCoinFormation),
		OBJECT(MODEL_YELLOW_COIN, -6147, -938, -10438, 0, -139, 0, 0x00040000, bhvYellowCoin),
		OBJECT(MODEL_BLACK_BOBOMB, -2375, -1486, -10385, 0, -139, 0, 0x00040000, bhvBobomb),
		OBJECT(0, -2888, 462, -10407, 0, 90, 0, 0x00040000, bhvCoinFormation),
		OBJECT(MODEL_AMP, -4877, 283, -10415, 0, -180, 0, 0x00000000, bhvCirclingAmp),
		OBJECT(MODEL_BITDW_FERRIS_WHEEL_AXLE, 1250, 2441, -9942, 0, -180, 0, 0x00010000, bhvFerrisWheelAxle),
		OBJECT(MODEL_AMP, 4406, 2787, -8996, 0, -180, 0, 0x00000000, bhvCirclingAmp),
		TERRAIN(bitdw_area_1_collision),
		MACRO_OBJECTS(bitdw_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_KOOPA_ROAD),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
