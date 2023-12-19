#include "poc.h"


lv_style_t style;
lv_obj_t *label_return;
lv_obj_t *label_con;
lv_obj_t *return_obj;
lv_obj_t *bg;
lv_obj_t *bg_mnue3;


void set_all_pad(lv_obj_t *bg,lv_style_t * style, lv_coord_t value)
{
    lv_style_set_pad_bottom(style, 0);		//设置样式底部内边距
    lv_style_set_pad_left(style, 0);		//设置样式左边内边距
    lv_style_set_pad_right(style, 0);
    lv_style_set_pad_top(style, 0);
    lv_style_set_border_width(style,0);
    lv_obj_add_style(bg,style,0);
}


static lv_obj_t *shit_menu_main(void)
{
    lv_style_init(&style);
    
    bg=lv_obj_create(lv_scr_act());
    lv_obj_set_size(bg,lv_pct(100),128);
    lv_obj_align(bg,LV_ALIGN_CENTER,0,0);
    lv_obj_set_style_radius(bg,0,LV_PART_MAIN);
    lv_obj_clear_flag( bg, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    set_all_pad(bg,&style, 0);
    lv_obj_set_style_bg_color(bg, lv_color_hex(0x363636), LV_PART_MAIN | LV_STATE_DEFAULT );
    

    lv_obj_t *bg_head=lv_obj_create(bg);
    lv_obj_set_size(bg_head,lv_pct(100),16);
    lv_obj_set_style_radius(bg_head,0,LV_PART_MAIN);
    lv_obj_align(bg_head,LV_ALIGN_TOP_MID,0,0);
    lv_obj_clear_flag( bg_head, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    lv_obj_set_style_bg_color(bg_head, lv_color_hex(0x3480FF), LV_PART_MAIN | LV_STATE_DEFAULT );
    set_all_pad(bg_head,&style, 0);


    lv_obj_t *bg_buttom=lv_obj_create(bg);
    lv_obj_set_size(bg_buttom,lv_pct(100),13);
    lv_obj_set_style_radius(bg_buttom,0,LV_PART_MAIN);
    lv_obj_align(bg_buttom,LV_ALIGN_BOTTOM_MID,0,0);
    lv_obj_clear_flag( bg_buttom, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    lv_obj_set_style_bg_color(bg_buttom, lv_color_hex(0x3480FF), LV_PART_MAIN | LV_STATE_DEFAULT );
    set_all_pad(bg_buttom,&style, 0);

    lv_obj_t *bg_mnue1=lv_obj_create(bg);
    lv_obj_set_size(bg_mnue1,lv_pct(100),45);
    lv_obj_set_style_radius(bg_mnue1,0,LV_PART_MAIN);
    lv_obj_align(bg_mnue1,LV_ALIGN_TOP_MID,0,16);
    lv_obj_clear_flag( bg_mnue1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    lv_obj_set_style_bg_color(bg_mnue1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
    set_all_pad(bg_mnue1,&style, 0);

    lv_obj_t *bg_mnue2=lv_obj_create(bg);
    lv_obj_set_size(bg_mnue2,lv_pct(100),53);
    lv_obj_set_style_radius(bg_mnue2,0,LV_PART_MAIN);
    lv_obj_align(bg_mnue2,LV_ALIGN_TOP_MID,0,62);
    // lv_obj_clear_flag( bg_mnue2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    lv_obj_set_style_bg_color(bg_mnue2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
    set_all_pad(bg_mnue2,&style, 0);
    
    

    label_return=lv_label_create(bg);
    lv_obj_set_size(label_return,40,13);
    lv_obj_set_style_radius(label_return,0,LV_PART_MAIN);
    lv_obj_align(label_return,LV_ALIGN_BOTTOM_RIGHT,0,-2);

    lv_obj_set_style_text_font(label_return,&lv_font_simsun_16_siyuan,NULL);
    lv_obj_set_style_text_color(label_return,lv_color_hex(0xFFFFFF),NULL);
    lv_label_set_text(label_return,"返回");

    lv_obj_t *con_obj=lv_obj_create(bg);
    lv_obj_set_size(con_obj,40,13);
    lv_obj_set_style_radius(con_obj,0,LV_PART_MAIN);
    lv_obj_align(con_obj,LV_ALIGN_BOTTOM_LEFT,0,0);
    lv_obj_set_style_bg_color(con_obj, lv_color_hex(0x3480FF), LV_PART_MAIN | LV_STATE_DEFAULT );
    set_all_pad(con_obj,&style, 0);
    label_con=lv_label_create(con_obj);
    lv_obj_set_size(label_con,40,13);
    lv_obj_set_style_radius(label_con,0,LV_PART_MAIN);
    lv_obj_align(label_con,LV_ALIGN_BOTTOM_LEFT,4,-2);

    lv_obj_set_style_text_font(label_con,&lv_font_simsun_16_siyuan,NULL);
    lv_obj_set_style_text_color(label_con,lv_color_hex(0xFFFFFF),NULL);
    lv_label_set_text(label_con,"确定");
    lv_obj_clear_flag( label_con, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    // lv_obj_set_style_bg_color(label_return, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
    // set_all_pad(label_return,&style, 0);
    // lv_obj_add_event_cb(lv_scr_act(), scroll_event_cb, LV_EVENT_GESTURE , bg_mnue2);
    // lv_obj_add_event_cb(con_obj, clicked_event_cb, LV_EVENT_CLICKED , bg_mnue2);      //界面切换
    // lv_obj_add_event_cb(label_return, clicked_event_cb, LV_EVENT_CLICKED , NULL);
    return bg_mnue2;
}


int menu_init(void)
{
    lv_obj_t *m=shit_menu_main();

}