#include "channel_control.h"
#include "constants.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_plus;
static GBitmap *s_res_minus;
static GFont s_res_gothic_28_bold;
static ActionBarLayer *s_actionbarlayer_1;
static TextLayer *s_textlayer_1;


void channel_up_click_handler(ClickRecognizerRef recognizer, void *context) {
	//APP_LOG(APP_LOG_LEVEL_DEBUG, "Channel up!");
	DictionaryIterator *iter;
	app_message_outbox_begin(&iter);
   dict_write_uint32(iter, 0, CHANNEL_UP);
   dict_write_end(iter);
   app_message_outbox_send();
}

void channel_down_click_handler(ClickRecognizerRef recognizer, void *context) {
	//APP_LOG(APP_LOG_LEVEL_DEBUG, "Channel down!");
	DictionaryIterator *iter;
	app_message_outbox_begin(&iter);
   dict_write_uint32(iter, 0, CHANNEL_DOWN);
   dict_write_end(iter);
   app_message_outbox_send();
}

void channel_config_provider(void *context) {
 // single click / repeat-on-hold config:
  window_single_click_subscribe(BUTTON_ID_UP, channel_up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, channel_down_click_handler);	
}

static void initialise_ui(void) {
  s_window = window_create();
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, 0);
  #endif
  
  s_res_plus = gbitmap_create_with_resource(RESOURCE_ID_plus);
  s_res_minus = gbitmap_create_with_resource(RESOURCE_ID_minus);
  s_res_gothic_28_bold = fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD);
  // s_actionbarlayer_1
  s_actionbarlayer_1 = action_bar_layer_create();
  action_bar_layer_add_to_window(s_actionbarlayer_1, s_window);
  action_bar_layer_set_background_color(s_actionbarlayer_1, GColorBlack);
  action_bar_layer_set_icon(s_actionbarlayer_1, BUTTON_ID_UP, s_res_plus);
  action_bar_layer_set_icon(s_actionbarlayer_1, BUTTON_ID_DOWN, s_res_minus);
  action_bar_layer_set_click_config_provider(s_actionbarlayer_1,channel_config_provider);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_actionbarlayer_1);
  
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(26, 54, 81, 28));
  text_layer_set_text(s_textlayer_1, "Channel");
  text_layer_set_font(s_textlayer_1, s_res_gothic_28_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  action_bar_layer_destroy(s_actionbarlayer_1);
  text_layer_destroy(s_textlayer_1);
  gbitmap_destroy(s_res_plus);
  gbitmap_destroy(s_res_minus);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}





void show_channel_control(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  //window_set_click_config_provider(s_window, (ClickConfigProvider) channel_config_provider);
  window_stack_push(s_window, true);
}

void hide_channel_control(void) {
  window_stack_remove(s_window, true);
}
