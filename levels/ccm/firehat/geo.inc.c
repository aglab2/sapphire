#include "src/game/envfx_snow.h"

const GeoLayout firehat_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, firehat_skinned_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, firehat_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
