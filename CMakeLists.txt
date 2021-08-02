project(split-screen VERSION 0.1.0)
set(PROJECT_FULL_NAME "Split Screen")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/version.h)

set(split-screen_HEADERS
	split-screen.h)
set(split-screen_SOURCES
	split-screen.c)

if(WIN32)
	configure_file(resource.rc.in split-screen.rc)
	list(APPEND split-screen_SOURCES
		split-screen.rc)
endif()

add_library(split-screen MODULE
	${split-screen_HEADERS}
	${split-screen_SOURCES})
target_link_libraries(split-screen
	libobs)

set_target_properties(split-screen PROPERTIES FOLDER "plugins")
install_obs_plugin_with_data(split-screen data)
