#include "porting/lv_porting.h"
#include "lvgl.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

static void updata_time(lv_timer_t * timer)
{
    lv_obj_t *time_label=timer->user_data;
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char buf[32];
    strftime(buf,sizeof(buf),"%H:%M:%S",timeinfo);
    lv_label_set_text(time_label,buf);
}

static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Clicked: %s", lv_list_get_btn_text(list1, obj));
    }
}

void alarm_create(lv_obj_t * win)
{

    lv_obj_t *win_obj = lv_obj_create(win);

    // win = lv_obj_create(lv_scr_act());
    lv_obj_set_size(win_obj, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_border_side(win_obj, LV_BORDER_SIDE_NONE, 0);
    lv_obj_set_scrollbar_mode(win_obj, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_dir(win_obj, LV_DIR_NONE);
    lv_obj_set_style_pad_all(win_obj, 0, 0);
    lv_obj_clear_flag(win_obj, LV_OBJ_FLAG_EVENT_BUBBLE);

    /*Create a list*/
    lv_obj_t *list1 = lv_list_create(lv_scr_act());
    lv_obj_set_size(list1, 128, 50);
    lv_obj_center(list1);

    /*Add buttons to the list*/
    lv_obj_t * btn;

    lv_list_add_text(list1, "File");
    btn = lv_list_add_btn(list1, LV_SYMBOL_FILE, "New");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(list1, LV_SYMBOL_DIRECTORY, "Open");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(list1, LV_SYMBOL_SAVE, "Save");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(list1, LV_SYMBOL_CLOSE, "Delete");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(list1, LV_SYMBOL_EDIT, "Edit");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);

    lv_list_add_text(list1, "Connectivity");
    btn = lv_list_add_btn(list1, LV_SYMBOL_BLUETOOTH, "Bluetooth");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(list1, LV_SYMBOL_GPS, "Navigation");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(list1, LV_SYMBOL_USB, "USB");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(list1, LV_SYMBOL_BATTERY_FULL, "Battery");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);

    lv_list_add_text(list1, "Exit");
    btn = lv_list_add_btn(list1, LV_SYMBOL_OK, "Apply");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(list1, LV_SYMBOL_CLOSE, "Close");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);

}


void big_shit(void)
{
    lv_obj_t *obj=lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj, 128, 128);
    lv_obj_center(obj);
    lv_obj_set_style_radius(obj,0,0);
    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, 0);
    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
    lv_obj_set_style_pad_all(obj, 0, 0);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);

    
    alarm_create(obj);
}


