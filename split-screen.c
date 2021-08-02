#include <obs-module.h>
#include "split-screen.h"
#include "version.h"
#include "util/platform.h"

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
	//obs_register_source(&split_screen);
	return true;
}
