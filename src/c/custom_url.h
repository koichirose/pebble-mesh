#ifndef CUSTOM_URL_H
#define CUSTOM_URL_H

#include <pebble.h>
#include "config.h"

// Buffer holding the last value fetched from the user-configured URL.
// Max 32 displayable characters (plus null terminator).
extern char s_custom_data[33];

void draw_custom_url_info(InfoLayer* info_layer);
void request_custom_url_update();

#endif // CUSTOM_URL_H
