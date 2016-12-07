#include <linux/input.h>
#include <linux/input/ft5x06_ts_asus.h>

#define FT_GESTURE_DOUBLECLICK_ID	0x24
#define FT_GESTURE_C_ID			0x34
#define FT_GESTURE_E_ID			0x33
#define FT_GESTURE_S_ID			0x46
#define FT_GESTURE_V_ID			0x54
#define FT_GESTURE_W_ID			0x31
#define FT_GESTURE_Z_ID			0x65

#define KEY_GESTURE_C		265
#define KEY_GESTURE_E		266
#define KEY_GESTURE_S		267
#define KEY_GESTURE_V		263
#define KEY_GESTURE_W		268
#define KEY_GESTURE_Z		264

void ft5x06_report_gesture_key(struct input_dev *ip_dev, int gesture_id)
{
	switch (gesture_id) {
		case FT_GESTURE_DOUBLECLICK_ID:
			input_report_key(ip_dev, KEY_WAKEUP, 1);
			input_sync(ip_dev);
			input_report_key(ip_dev, KEY_WAKEUP, 0);
			input_sync(ip_dev);
			break;
		case FT_GESTURE_C_ID:
			input_report_key(ip_dev, KEY_GESTURE_C, 1);
			input_sync(ip_dev);
			input_report_key(ip_dev, KEY_GESTURE_C, 0);
			input_sync(ip_dev);
			break;
		case FT_GESTURE_E_ID:
			input_report_key(ip_dev, KEY_GESTURE_E, 1);
			input_sync(ip_dev);
			input_report_key(ip_dev, KEY_GESTURE_E, 0);
			input_sync(ip_dev);
			break;
		case FT_GESTURE_S_ID:
			input_report_key(ip_dev, KEY_GESTURE_S, 1);
			input_sync(ip_dev);
			input_report_key(ip_dev, KEY_GESTURE_S, 0);
			input_sync(ip_dev);
			break;
		case FT_GESTURE_V_ID:
			input_report_key(ip_dev, KEY_GESTURE_V, 1);
			input_sync(ip_dev);
			input_report_key(ip_dev, KEY_GESTURE_V, 0);
			input_sync(ip_dev);
			break;
		case FT_GESTURE_W_ID:
			input_report_key(ip_dev, KEY_GESTURE_W, 1);
			input_sync(ip_dev);
			input_report_key(ip_dev, KEY_GESTURE_W, 0);
			input_sync(ip_dev);
			break;
		case FT_GESTURE_Z_ID:
			input_report_key(ip_dev, KEY_GESTURE_Z, 1);
			input_sync(ip_dev);
			input_report_key(ip_dev, KEY_GESTURE_Z, 0);
			input_sync(ip_dev);
			break;
		default:
			break;
	}
}

void ft5x06_ts_probe_asus(struct input_dev *input_dev) {
	input_set_capability(input_dev, EV_KEY, KEY_WAKEUP);
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_C);
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_E);
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_S);
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_V);
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_W);
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_Z);

	__set_bit(KEY_WAKEUP, input_dev->keybit);
	__set_bit(KEY_GESTURE_C, input_dev->keybit);
	__set_bit(KEY_GESTURE_E, input_dev->keybit);
	__set_bit(KEY_GESTURE_S, input_dev->keybit);
	__set_bit(KEY_GESTURE_V, input_dev->keybit);
	__set_bit(KEY_GESTURE_W, input_dev->keybit);
	__set_bit(KEY_GESTURE_Z, input_dev->keybit);
}
