#include "main_control.h"
#include "channel_control.h"
#include "volume_control.h"
#include "constants.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_channel;
static GBitmap *s_res_volume;
static GFont s_res_gothic_24_bold;
static ActionBarLayer *s_actionbarlayer_1;
static TextLayer *s_textlayer_1;
static TextLayer *s_textlayer_2;

static void initialise_ui(void) {
  s_window = window_create();
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, 0);
  #endif
  
  s_res_channel = gbitmap_create_with_resource(RESOURCE_ID_channel);
  s_res_volume = gbitmap_create_with_resource(RESOURCE_ID_volume);
  s_res_gothic_24_bold = fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD);
  // s_actionbarlayer_1
  s_actionbarlayer_1 = action_bar_layer_create();
  action_bar_layer_add_to_window(s_actionbarlayer_1, s_window);
  action_bar_layer_set_background_color(s_actionbarlayer_1, GColorWhite);
  action_bar_layer_set_icon(s_actionbarlayer_1, BUTTON_ID_UP, s_res_channel);
  action_bar_layer_set_icon(s_actionbarlayer_1, BUTTON_ID_DOWN, s_res_volume);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_actionbarlayer_1);
  
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(10, 13, 100, 24));
  text_layer_set_text(s_textlayer_1, "Channel");
  text_layer_set_font(s_textlayer_1, s_res_gothic_24_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
  
  // s_textlayer_2
  s_textlayer_2 = text_layer_create(GRect(10, 109, 100, 24));
  text_layer_set_text(s_textlayer_2, "Volume");
  text_layer_set_font(s_textlayer_2, s_res_gothic_24_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_2);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  action_bar_layer_destroy(s_actionbarlayer_1);
  text_layer_destroy(s_textlayer_1);
  text_layer_destroy(s_textlayer_2);
  gbitmap_destroy(s_res_channel);
  gbitmap_destroy(s_res_volume);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void up_click_handler(ClickRecognizerRef recognizer, void *context) {
	show_channel_control();
}

void down_click_handler(ClickRecognizerRef recognizer, void *context) {
	show_volume_control();
}

void config_provider(Window *window) {
 // single click / repeat-on-hold config:
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);	
}

void show_main_control(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_set_click_config_provider(s_window, (ClickConfigProvider) config_provider);

  window_stack_push(s_window, true);
}



void hide_main_control(void) {
  window_stack_remove(s_window, true);
}

