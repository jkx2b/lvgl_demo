#include "porting/lv_porting.h"
#include "lvgl.h"
#include "meituan_lvgl.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

static time_t time_now; 
static struct tm *tm_now;
static char *tm_string;
static lv_point_t coords;

static lv_obj_t *menu;
static lv_obj_t *menu1;

#define  PICDIR "C:/picpic/"

static void login_screen(void);
static void idle_screen(void);


void time_flush(lv_timer_t *timer)
{
    time_now= time(NULL);
    tm_now= localtime(&time_now);
    sprintf(tm_string,"%d:%d:%d",tm_now->tm_hour,tm_now->tm_min,tm_now->tm_sec);
    lv_label_set_text(timer->user_data,tm_string);

}

void loop()
{
    
    lv_indev_t *indev = lv_indev_get_act(); // 获取当前活动的输入设备
    lv_indev_get_point(indev, &coords); // 获取坐标信息
    printf("X: %d, Y: %d\n", coords.x, coords.y);
}


static void scroll_event_cb(lv_event_t * e)
{
    lv_obj_t * cont = lv_event_get_target(e);
 
    lv_area_t cont_a;
     /*
     lv_obj_get_coords函数用于获取一个对象的坐标信息。
     */
    lv_indev_t* indev = lv_indev_get_act(); //获取输入设备
    if (indev == NULL)  return;
    lv_point_t   lv_point;
    lv_dir_t event= lv_indev_get_gesture_dir(indev);
        
    
    if(event==LV_DIR_RIGHT)
    {

        lv_indev_get_point(indev, &lv_point);
        printf("[%s]  lv_point.x = %d  lv_point.y = %d \n", __func__, lv_point.x, lv_point.y);
        // lv_obj_add_flag(menu, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_clear_flag(menu1, LV_OBJ_FLAG_HIDDEN);
        lv_obj_del(menu);
        login_screen();


    }
    else if (LV_DIR_LEFT)
    {
        lv_indev_get_point(indev, &lv_point);
        printf("[%s]  lv_point.x = %d  lv_point.y = %d \n", __func__, lv_point.x, lv_point.y);
        // lv_obj_add_flag(menu1, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_clear_flag(menu, LV_OBJ_FLAG_HIDDEN);
        lv_obj_del(menu1);
        idle_screen();

    }
    
    
    
   
}





static void main_screen(void)
{
    lv_obj_t *menu=lv_img_create(lv_scr_act());
    // lv_img_set_src(menu,"C:/picpic/menu1.bin");
    lv_obj_set_size(menu,lv_pct(100),lv_pct(100));
}


static void login_screen(void)
{
    menu1 =lv_img_create(lv_scr_act());
    lv_img_set_src(menu1,"C:/picpic/menu1.bin");
    lv_obj_set_size(menu1,lv_pct(100),lv_pct(100));
    // lv_obj_add_event_cb(lv_scr_act(), scroll_event_cb, LV_EVENT_GESTURE , NULL);

}


static void idle_screen(void)
{
    
    
    // static lv_style_t style_reset;
    // lv_style_reset(&style_reset); // 初始化一个空的样式
    menu =lv_img_create(lv_scr_act());
    lv_img_set_src(menu,"C:/picpic/menu1.bin");
    lv_obj_set_size(menu,lv_pct(100),lv_pct(100));

    
    // lv_timer_create(loop,50,time_label);
    
    // lv_obj_add_event_cb(lv_scr_act(), scroll_event_cb, LV_EVENT_GESTURE, NULL);
    // login_screen();
    // lv_obj_add_flag(menu1, LV_OBJ_FLAG_HIDDEN);
    

}

static timer_time()
{
    
}

int menu_main(void)
{
    lv_obj_add_event_cb(lv_scr_act(), scroll_event_cb, LV_EVENT_GESTURE , NULL);
    tm_string=malloc(16);
    time_now= time(NULL);
    tm_now= localtime(&time_now);
    sprintf(tm_string,"%d:%d:%d",tm_now->tm_hour,tm_now->tm_min,tm_now->tm_sec);

    lv_obj_t *time_obj=lv_obj_create(lv_scr_act());
    lv_obj_align(time_obj,LV_ALIGN_TOP_RIGHT,0,0);
    lv_obj_set_size(time_obj,70,30);
    lv_obj_clear_flag( time_obj, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    lv_obj_set_style_radius(time_obj, 20, LV_PART_MAIN| LV_STATE_DEFAULT);

    lv_obj_t *time_label=lv_label_create(time_obj);
    lv_obj_align(time_label,LV_ALIGN_CENTER,0,0);
    lv_label_set_text(time_label,tm_string);
    lv_timer_create(time_flush,1000,time_label);
    idle_screen();
    return 0;
}