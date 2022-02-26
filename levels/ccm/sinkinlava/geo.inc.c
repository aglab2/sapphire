#include "src/game/envfx_snow.h"

const GeoLayout sinkinlava_geo[] = {
	GEO_CULLING_RADIUS(2500),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sinkinlava_skinned_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sinkinlava_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
