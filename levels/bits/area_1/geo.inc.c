#include "src/game/envfx_snow.h"

const GeoLayout bits_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -495, 1334, -8777, bits_dl_Shape_IndexedFaceSet_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3334, -1682, -5120, bits_dl_Shape_IndexedFaceSet_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -541, 72, 376, bits_dl_Shape_IndexedFaceSet_042_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bits_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND(BACKGROUND_PURPLE_SKY, geo_skybox_main),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -1, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, bits_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bits_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bits_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};