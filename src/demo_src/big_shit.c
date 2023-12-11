#include "porting/lv_porting.h"
#include "lvgl.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "big_shit.h"

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


    lv_obj_t *img_img_background1=lv_img_create(win_obj);
    lv_img_set_src(img_img_background1,&img_background1);
    // win = lv_obj_create(lv_scr_act());
    lv_obj_set_size(win_obj, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_border_side(win_obj, LV_BORDER_SIDE_NONE, 0);
    lv_obj_set_scrollbar_mode(win_obj, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_dir(win_obj, LV_DIR_NONE);
    lv_obj_set_style_pad_all(win_obj, 0, 0);
    lv_obj_clear_flag(win_obj, LV_OBJ_FLAG_EVENT_BUBBLE);

    /*Create a chart*/
    lv_obj_t * chart;
    chart = lv_chart_create(lv_scr_act());
    lv_obj_set_size(chart, 200, 150);
    lv_obj_center(chart);
    lv_chart_set_type(chart, LV_CHART_TYPE_LINE);   /*Show lines and points too*/

    /*Add two data series*/
    lv_chart_series_t * ser1 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_series_t * ser2 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_SECONDARY_Y);

    /*Set the next points on 'ser1'*/
    lv_chart_set_next_value(chart, ser1, 10);
    lv_chart_set_next_value(chart, ser1, 10);
    lv_chart_set_next_value(chart, ser1, 10);
    lv_chart_set_next_value(chart, ser1, 10);
    lv_chart_set_next_value(chart, ser1, 10);
    lv_chart_set_next_value(chart, ser1, 10);
    lv_chart_set_next_value(chart, ser1, 10);
    lv_chart_set_next_value(chart, ser1, 30);
    lv_chart_set_next_value(chart, ser1, 70);
    lv_chart_set_next_value(chart, ser1, 90);

    /*Directly set points on 'ser2'*/
    ser2->y_points[0] = 90;
    ser2->y_points[1] = 70;
    ser2->y_points[2] = 65;
    ser2->y_points[3] = 65;
    ser2->y_points[4] = 65;
    ser2->y_points[5] = 65;
    ser2->y_points[6] = 65;
    ser2->y_points[7] = 65;
    ser2->y_points[8] = 65;
    ser2->y_points[9] = 65;

    lv_chart_refresh(chart); /*Required after direct set*/

}

static void alarm_off_event(lv_event_t * e)
{
   lv_event_code_t code = lv_event_get_code(e);
   lv_obj_t * target = lv_event_get_target(e);
//    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
//        lv_indev_wait_release(lv_indev_get_act());

//    }
        

    if(LV_EVENT_CLICKED==code  &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
	{
        lv_obj_del(target);
		free(target);
	}
    else if(LV_EVENT_KEY==code)
	{
        lv_obj_del(target);
		free(target);
		
	}
	

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

    lv_obj_t *gif=lv_gif_create(obj);
    lv_gif_set_src(gif,&anim_alarm);
    lv_obj_add_event_cb(obj,alarm_off_event,LV_EVENT_ALL,NULL);
    // alarm_create(obj);
}


