#include "custom_url.h"

char s_custom_data[33] = "--";

void request_custom_url_update() {
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Requesting custom URL update");

  DictionaryIterator *iter;
  app_message_outbox_begin(&iter);

  if (iter == NULL) {
    APP_LOG(APP_LOG_LEVEL_ERROR, "Failed to create message iterator");
    return;
  }

  dict_write_uint8(iter, MESSAGE_KEY_CUSTOM_URL_REQUEST, 1);
  app_message_outbox_send();
}

void draw_custom_url_info(InfoLayer* info_layer) {
  GRect bounds = info_layer->bounds;
  Layer* layer = info_layer->layer;

  info_layer->text_layer1 = text_layer_create(GRect(0, 0, bounds.size.w, bounds.size.h));
  text_layer_set_background_color(info_layer->text_layer1, GColorClear);
  text_layer_set_text_color(info_layer->text_layer1, get_text_color());
  text_layer_set_text(info_layer->text_layer1, s_custom_data);
#if defined(PBL_PLATFORM_EMERY)
  text_layer_set_font(info_layer->text_layer1, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
#else
  text_layer_set_font(info_layer->text_layer1, fonts_get_system_font(FONT_KEY_GOTHIC_14_MEDIUM));
#endif
  text_layer_set_text_alignment(info_layer->text_layer1, GTextAlignmentCenter);
  text_layer_set_overflow_mode(info_layer->text_layer1, GTextOverflowModeWordWrap);

  layer_add_child(layer, text_layer_get_layer(info_layer->text_layer1));
}
