#include <obs-module.h>
#include "split-screen.h"
#include "version.h"
#include "util/platform.h"

static const char *split_get_name(void *type_data)
{
	UNUSED_PARAMETER(type_data);
	return obs_module_text("SplitScreen");
}

static void *split_create(obs_data_t *settings, obs_source_t *source)
{
	return NULL;
}

static void split_destroy(void *data)
{

}

static void split_update(void *data, obs_data_t *settings)
{

}

static void split_video_render(void *data, gs_effect_t *effect)
{

}

static bool split_audio_render(void *data, uint64_t *ts_out,
				  struct obs_source_audio_mix *audio_output,
				  uint32_t mixers, size_t channels,
				  size_t sample_rate)
{

}

uint32_t split_get_width(void *data)
{
	return 0;
}

uint32_t split_get_height(void *data)
{
	return 0;
}

static struct obs_source_info split_screen = {
	.id = "split_screen",
	.type = OBS_SOURCE_TYPE_INPUT,
	.output_flags = OBS_OUTPUT_VIDEO | OBS_SOURCE_CUSTOM_DRAW |
			OBS_SOURCE_COMPOSITE | OBS_SOURCE_DO_NOT_DUPLICATE,
	.get_name = split_get_name,
	.create = split_create,
	.destroy = split_destroy,
	.update = split_update,
	.video_render = split_video_render,
	.audio_render = split_audio_render,
	.get_width = split_get_width,
	.get_height = split_get_height,
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
