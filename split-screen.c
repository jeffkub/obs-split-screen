#include <obs-module.h>
#include "split-screen.h"
#include "version.h"
#include "util/platform.h"

struct split_screen {
	obs_source_t *source;
};

static void split_screen_update(void *data, obs_data_t *settings);

static const char *split_screen_get_name(void *type_data)
{
	return obs_module_text("SplitScreen");
}

static void *split_screen_create(obs_data_t *settings, obs_source_t *source)
{
	struct split_screen *context = bzalloc(sizeof(struct split_screen));
	context->source = source;

	split_screen_update(context, settings);

	return context;
}

static void split_screen_destroy(void *data)
{
	struct split_screen *context = data;

	bfree(context);
}

static void split_screen_update(void *data, obs_data_t *settings)
{

}

static void split_screen_video_render(void *data, gs_effect_t *effect)
{

}

static bool split_screen_audio_render(void *data, uint64_t *ts_out,
				      struct obs_source_audio_mix *audio_output,
				      uint32_t mixers, size_t channels,
				      size_t sample_rate)
{
	return false;
}

static obs_properties_t *split_screen_properties(void *data)
{
	obs_properties_t *ppts = obs_properties_create();

	obs_properties_add_editable_list(ppts, S_SOURCES,
					 obs_module_text("Sources"),
					 OBS_EDITABLE_LIST_TYPE_STRINGS, NULL,
					 NULL);

	obs_properties_t *layout_group = obs_properties_create();
	obs_properties_add_int(layout_group, S_LAYOUT_ROWS,
			       obs_module_text("Rows"), 0, 100, 1);
	obs_properties_add_int(layout_group, S_LAYOUT_COLUMNS,
			       obs_module_text("Columns"), 0, 100, 1);
	obs_properties_add_group(ppts, S_LAYOUT_GROUP,
				 obs_module_text("Layout"), OBS_GROUP_NORMAL,
				 layout_group);

	return ppts;
}

static void split_screen_defaults(obs_data_t *settings)
{

}

uint32_t split_screen_get_width(void *data)
{
	return 0;
}

uint32_t split_screen_get_height(void *data)
{
	return 0;
}

static struct obs_source_info split_screen = {
	.id = "split_screen",
	.type = OBS_SOURCE_TYPE_INPUT,
	.output_flags = OBS_OUTPUT_VIDEO | OBS_SOURCE_CUSTOM_DRAW |
			OBS_SOURCE_COMPOSITE | OBS_SOURCE_DO_NOT_DUPLICATE,
	.get_name = split_screen_get_name,
	.create = split_screen_create,
	.destroy = split_screen_destroy,
	.update = split_screen_update,
	.video_render = split_screen_video_render,
	.audio_render = split_screen_audio_render,
	.get_properties = split_screen_properties,
	.get_defaults = split_screen_defaults,
	.get_width = split_screen_get_width,
	.get_height = split_screen_get_height,
	.icon_type = OBS_ICON_TYPE_SLIDESHOW,
};

OBS_DECLARE_MODULE()
OBS_MODULE_AUTHOR("Jeff Kubascik");
OBS_MODULE_USE_DEFAULT_LOCALE("split-screen", "en-US")

MODULE_EXPORT const char *obs_module_description(void)
{
	return obs_module_text("Description");
}

MODULE_EXPORT const char *obs_module_name(void)
{
	return obs_module_text("SplitScreen");
}

bool obs_module_load(void)
{
	blog(LOG_INFO, "[Split Screen] loaded version %s", PROJECT_VERSION);
	obs_register_source(&split_screen);
	return true;
}
