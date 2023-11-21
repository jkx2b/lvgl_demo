#include "porting/lv_porting.h"
#include "lvgl.h"
#include "meituan_lvgl.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define true	1
#define false	0

static time_t time_now; 
static struct tm *tm_now;
static char *tm_string;
static lv_point_t coords;

static lv_obj_t *menu;
static lv_obj_t *menu1;
static lv_obj_t *time_label;

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

static void textarea_event_handler(lv_event_t * e)
{
    lv_obj_t * ta = lv_event_get_target(e);
    LV_LOG_USER("Enter was pressed. The current text is: %s", lv_textarea_get_text(ta));
}

static void btnm_event_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_t * ta = lv_event_get_user_data(e);
    const char * txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));

    if(strcmp(txt, LV_SYMBOL_BACKSPACE) == 0) lv_textarea_del_char(ta);
    else if(strcmp(txt, LV_SYMBOL_NEW_LINE) == 0) lv_event_send(ta, LV_EVENT_READY, NULL);
    else lv_textarea_add_text(ta, txt);

}

static void login_screen(void)
{
    menu1 =lv_img_create(lv_scr_act());
    lv_img_set_src(menu1,"C:/picpic/menu2.bin");
    lv_obj_set_size(menu1,lv_pct(100),lv_pct(100));
    // lv_obj_add_event_cb(lv_scr_act(), scroll_event_cb, LV_EVENT_GESTURE , NULL);

    lv_obj_t * ta = lv_textarea_create(lv_scr_act());
    lv_textarea_set_one_line(ta, true);
    lv_obj_align(ta, LV_ALIGN_TOP_MID, 0, 10);
    lv_obj_add_event_cb(ta, textarea_event_handler, LV_EVENT_READY, ta);
    lv_obj_add_state(ta, LV_STATE_FOCUSED); /*To be sure the cursor is visible*/

    static const char * btnm_map[] = {"1", "2", "3", "\n",
                               "4", "5", "6", "\n",
                               "7", "8", "9", "\n",
                               LV_SYMBOL_BACKSPACE, "0", LV_SYMBOL_NEW_LINE, ""};

    lv_obj_t * btnm = lv_btnmatrix_create(lv_scr_act());
    lv_obj_set_size(btnm, 200, 150);
    lv_obj_align(btnm, LV_ALIGN_BOTTOM_MID, 0, -10);
    lv_obj_add_event_cb(btnm, btnm_event_handler, LV_EVENT_VALUE_CHANGED, ta);
    lv_obj_clear_flag(btnm, LV_OBJ_FLAG_CLICK_FOCUSABLE); /*To keep the text area focused on button clicks*/
    lv_btnmatrix_set_map(btnm, btnm_map);

}


static void idle_screen(void)
{
    
    
    // static lv_style_t style_reset;
    // lv_style_reset(&style_reset); // 初始化一个空的样式
    menu =lv_img_create(lv_scr_act());
    lv_img_set_src(menu,"C:/picpic/menu1.bin");
    lv_obj_set_size(menu,lv_pct(100),lv_pct(100));

    lv_obj_t *time_obj=lv_obj_create(lv_scr_act());
    lv_obj_align(time_obj,LV_ALIGN_TOP_RIGHT,0,0);
    lv_obj_set_size(time_obj,70,30);
    lv_obj_clear_flag( time_obj, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    lv_obj_set_style_radius(time_obj, 20, LV_PART_MAIN| LV_STATE_DEFAULT);

    time_label=lv_label_create(time_obj);
    lv_obj_align(time_label,LV_ALIGN_CENTER,0,0);
    lv_label_set_text(time_label,tm_string);
    lv_timer_create(time_flush,1000,time_label);

    // lv_timer_create(loop,50,time_label);
    
    // lv_obj_add_event_cb(lv_scr_act(), scroll_event_cb, LV_EVENT_GESTURE, NULL);
    // login_screen();
    // lv_obj_add_flag(menu1, LV_OBJ_FLAG_HIDDEN);
    

}

static void set_all_pad(lv_obj_t *bg,lv_style_t * style, lv_coord_t value)
{
    lv_style_set_pad_bottom(style, 0);		//设置样式底部内边距
    lv_style_set_pad_left(style, 0);		//设置样式左边内边距
    lv_style_set_pad_right(style, 0);
    lv_style_set_pad_top(style, 0);
    lv_style_set_border_width(style,0);
    lv_obj_add_style(bg,style,0);
}

static void shit_menu()
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_png_init();
    lv_obj_t *bg=lv_obj_create(lv_scr_act());
    lv_obj_set_size(bg,160,128);
    lv_obj_align(bg,LV_ALIGN_CENTER,0,0);
    lv_obj_set_style_radius(bg,0,LV_PART_MAIN);
    lv_obj_clear_flag( bg, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    set_all_pad(bg,&style, 0);

    



    lv_obj_t *bg_head=lv_obj_create(bg);
    lv_obj_set_size(bg_head,160,15);
    lv_obj_set_style_radius(bg_head,0,LV_PART_MAIN);
    lv_obj_align(bg_head,LV_ALIGN_TOP_MID,0,0);
    lv_obj_clear_flag( bg_head, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    lv_obj_set_style_bg_color(bg_head, lv_color_hex(0x3480FF), LV_PART_MAIN | LV_STATE_DEFAULT );
    set_all_pad(bg_head,&style, 0);


    lv_obj_t *bg_buttom=lv_obj_create(bg);
    lv_obj_set_size(bg_buttom,160,16);
    lv_obj_set_style_radius(bg_buttom,0,LV_PART_MAIN);
    lv_obj_align(bg_buttom,LV_ALIGN_BOTTOM_MID,0,0);
    lv_obj_clear_flag( bg_buttom, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    lv_obj_set_style_bg_color(bg_buttom, lv_color_hex(0x3480FF), LV_PART_MAIN | LV_STATE_DEFAULT );
    set_all_pad(bg_buttom,&style, 0);

    lv_obj_t *bg_mnue1=lv_obj_create(bg);
    lv_obj_set_size(bg_mnue1,160,45);
    lv_obj_set_style_radius(bg_mnue1,0,LV_PART_MAIN);
    lv_obj_align(bg_mnue1,LV_ALIGN_TOP_MID,0,15);
    lv_obj_clear_flag( bg_mnue1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    lv_obj_set_style_bg_color(bg_mnue1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
    set_all_pad(bg_mnue1,&style, 0);

    lv_obj_t *bg_mnue2=lv_obj_create(bg);
    lv_obj_set_size(bg_mnue2,160,53);
    lv_obj_set_style_radius(bg_mnue2,0,LV_PART_MAIN);
    lv_obj_align(bg_mnue2,LV_ALIGN_TOP_MID,0,61);
    lv_obj_clear_flag( bg_mnue2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    lv_obj_set_style_bg_color(bg_mnue2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
    set_all_pad(bg_mnue2,&style, 0);
    
    lv_obj_t *img_1=lv_img_create(bg_mnue2);
    lv_img_set_src(img_1,"C:/picpic/1.png");
    lv_obj_align(img_1,LV_ALIGN_CENTER,0,0);

    lv_obj_t *img=lv_img_create(lv_scr_act());
    lv_img_set_src(img,"C:/picpic/5.png");
    lv_obj_align(img,LV_ALIGN_LEFT_MID,0,0);



}

int menu_main(void)
{
    // lv_obj_add_event_cb(lv_scr_act(), scroll_event_cb, LV_EVENT_GESTURE , NULL);
    // tm_string=malloc(16);
    // time_now= time(NULL);
    // tm_now= localtime(&time_now);
    // sprintf(tm_string,"%d:%d:%d",tm_now->tm_hour,tm_now->tm_min,tm_now->tm_sec);

    
    // idle_screen();
    shit_menu();


    return 0;
}