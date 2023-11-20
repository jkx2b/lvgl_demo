#include "new_demo.h"

#include "porting/lv_porting.h"
#include "lvgl.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


// #if LV_USE_CALENDAR && LV_BUILD_EXAMPLES

static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_current_target(e);

    if(code == LV_EVENT_VALUE_CHANGED) {
        lv_calendar_date_t date;
        if(lv_calendar_get_pressed_date(obj, &date)) {
            // LV_LOG_USER("Clicked date: %02d.%02d.%d", date.day, date.month, date.year);
            printf("Clicked date: %02d.%02d.%d\n", date.day, date.month, date.year);
        }
    }
}

void lv_example_calendar_1(void)
{
    time_t time_now_t=time(NULL);
    struct tm *time_now=localtime(&time_now_t);
    
    const char* daysname[7] = { "日", "一", "二",  "三", "四", "五", "六" };
    lv_obj_t  * calendar = lv_calendar_create(lv_scr_act());
    lv_obj_set_style_text_font(calendar, &lv_font_simsun_16_cjk, LV_PART_MAIN);

    lv_obj_set_size(calendar, 800, 480);
    lv_obj_align(calendar, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_event_cb(calendar, event_handler, LV_EVENT_ALL, NULL);
    lv_calendar_set_today_date(calendar, time_now->tm_year, time_now->tm_mon, time_now->tm_mday);
    lv_calendar_set_showed_date(calendar, time_now->tm_year,  time_now->tm_mon);
    lv_calendar_set_day_names(calendar, daysname);
    /*Highlight a few days*/
    static lv_calendar_date_t highlighted_days[3];       /*Only its pointer will be saved so should be static*/
    highlighted_days[0].year = 2002;
    highlighted_days[0].month = 01;
    highlighted_days[0].day = 21;

    highlighted_days[1].year = 2023;
    highlighted_days[1].month = 01;
    highlighted_days[1].day = 21;

    highlighted_days[2].year = 2023;
    highlighted_days[2].month = 11;
    highlighted_days[2].day = 22;

    lv_calendar_set_highlighted_dates(calendar, highlighted_days, 3);
    // lv_calendar_header_arrow_create(calendar);
    lv_calendar_header_dropdown_create(calendar);


#if LV_USE_CALENDAR_HEADER_DROPDOWN
    // lv_calendar_header_dropdown_create(calendar);
#elif LV_USE_CALENDAR_HEADER_ARROW
    // lv_calendar_header_arrow_create(calendar);
#endif
    lv_calendar_set_showed_date(calendar, 2023, 11);
}

// #endif