#include "src/game/envfx_snow.h"

const GeoLayout hexring_geo[] = {
	GEO_CULLING_RADIUS(4000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hexring_skinned_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hexring_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
