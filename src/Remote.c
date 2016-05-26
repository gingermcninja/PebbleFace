#include <pebble.h>
#include "main_control.h"
#include "volume_control.h"
#include "channel_control.h"

static void init(void) {
	app_message_open(256, 256);
	show_main_control();
}

int main() {
	init();
	app_event_loop();
}