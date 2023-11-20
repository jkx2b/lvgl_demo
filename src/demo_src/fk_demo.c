#include "fk_demo.h"
#include "porting/lv_porting.h"
#include "lvgl.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



static void event_cb(lv_event_t * e)
{
     lv_obj_t *obj=lv_event_get_target(e);
    lv_obj_t *obj_ct=lv_event_get_current_target(e);

    lv_event_code_t code=lv_event_get_code(e);
    lv_obj_t *label= lv_event_get_user_data(e);

    switch (code)
    {
    case LV_EVENT_PRESSED:
        lv_label_set_text(label,"LV_EVENT_PRESSED");
        lv_obj_set_style_bg_color(obj,lv_color_hex(0x0ff0ff),0);
        lv_obj_set_style_bg_color(obj_ct,lv_color_hex(0x0000ff),0);
        printf("LV_EVENT_PRESSED\n");
        break;
    case LV_EVENT_CLICKED:
        lv_label_set_text(label,"LV_EVENT_CLICKED");
        lv_obj_set_style_bg_color(obj,lv_color_hex(0xffffff),0);
        lv_obj_set_style_bg_color(obj_ct,lv_color_hex(0xffffff),0);

        printf("LV_EVENT_CLICKED\n");
        break;
    default:
        break;
    }


}


void fk_demo(void)
{

    static lv_style_t style;
    lv_style_init(&style);

    /*Set a background color and a radius*/
    lv_style_set_radius(&style, 0);
    lv_style_set_bg_opa(&style, LV_OPA_COVER);
    lv_style_set_bg_color(&style, lv_color_hex(0xD3483D));

    lv_obj_t * my_obj= lv_obj_create(lv_scr_act());
    lv_obj_set_size(my_obj,800,480);
    lv_obj_add_style(my_obj, &style, LV_STATE_DEFAULT);
    lv_obj_align(my_obj,LV_ALIGN_CENTER,0,0);


    lv_obj_t *label = lv_label_create(my_obj);
    lv_label_set_text(label,"label");
    lv_obj_set_pos(label, 0, 0);

    lv_obj_t *button_obj=lv_btn_create(my_obj);
    lv_obj_set_size(button_obj,150,50);
    lv_obj_set_pos(button_obj,50,0);
    lv_obj_t *label_but = lv_label_create(button_obj);
    lv_label_set_text(label_but,"button");
    lv_obj_align(label_but,LV_ALIGN_CENTER,0,0);
    lv_obj_center(label_but);

    lv_obj_t *box_1=lv_obj_create(my_obj);
    lv_obj_set_size(box_1,400,200);
    lv_obj_center(box_1);
    lv_obj_add_flag(box_1,LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_t *box_2=lv_obj_create(box_1);
    lv_obj_set_size(box_2,350,150);
    lv_obj_center(box_2);
    lv_obj_add_flag(box_2,LV_OBJ_FLAG_EVENT_BUBBLE);

    lv_obj_t *box_3=lv_obj_create(box_2);
    lv_obj_set_size(box_3,300,100);
    lv_obj_center(box_3);
    lv_obj_add_flag(box_3,LV_OBJ_FLAG_EVENT_BUBBLE);

    lv_obj_t *box_4=lv_obj_create(box_3);
    lv_obj_set_size(box_4,250,50);
    lv_obj_center(box_4);
    lv_obj_add_flag(box_4,LV_OBJ_FLAG_EVENT_BUBBLE);

    lv_obj_add_event_cb(box_1,event_cb,LV_EVENT_ALL,label);
    lv_obj_add_event_cb(box_2,event_cb,LV_EVENT_ALL,label);
    lv_obj_add_event_cb(box_3,event_cb,LV_EVENT_ALL,label);
    lv_obj_add_event_cb(box_4,event_cb,LV_EVENT_ALL,label);

    lv_obj_t *box_lable=lv_label_create(box_4);
    lv_label_set_text(box_lable,"oh!!!!中文");
    lv_obj_set_style_bg_opa(box_lable,255,0);
    lv_obj_set_style_bg_color(box_lable,lv_color_hex(0xEF1566),0);
    // lv_obj_set_style_text_font(box_lable,&lv_font_simsun_16_cjk,0);
    
    

}

#if 0
void lv_example_style_1(void)
{
     static lv_style_t style;
     lv_style_init(&style);
     lv_style_set_radius(&style, 5);

     /*Make a gradient*/
     lv_style_set_width(&style, 150);
     lv_style_set_height(&style, LV_SIZE_CONTENT);

     lv_style_set_pad_ver(&style, 20);
     lv_style_set_pad_left(&style, 5);

     lv_style_set_x(&style, lv_pct(50));
     lv_style_set_y(&style, 80);

     /*Create an object with the new style*/
     lv_obj_t * obj = lv_obj_create(lv_scr_act());
     lv_obj_add_style(obj, &style, 0);

     lv_obj_t * label = lv_label_create(obj);
     lv_label_set_text(label, "Hello");
}

void lv_example_style_2(void)
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_radius(&style, 5);

    /*Make a gradient*/
    lv_style_set_bg_opa(&style, LV_OPA_COVER);
    lv_style_set_bg_color(&style, lv_palette_lighten(LV_PALETTE_GREY, 1));
    lv_style_set_bg_grad_color(&style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_bg_grad_dir(&style, LV_GRAD_DIR_VER);

    /*Shift the gradient to the bottom*/
    lv_style_set_bg_main_stop(&style, 128);
    lv_style_set_bg_grad_stop(&style, 192);

    /*Create an object with the new style*/
    lv_obj_t * obj = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj, &style, 0);
    lv_obj_center(obj);
}

void lv_example_style_3(void)
{
    static lv_style_t style;
    lv_style_init(&style);

    /*Set a background color and a radius*/
    lv_style_set_radius(&style, 10);
    lv_style_set_bg_opa(&style, LV_OPA_COVER);
    lv_style_set_bg_color(&style, lv_palette_lighten(LV_PALETTE_GREY, 1));

    /*Add border to the bottom+right*/
    lv_style_set_border_color(&style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_border_width(&style, 5);
    lv_style_set_border_opa(&style, LV_OPA_50);
    lv_style_set_border_side(&style, LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_RIGHT);

    /*Create an object with the new style*/
    lv_obj_t * obj = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj, &style, 0);
    lv_obj_center(obj);
}

void lv_example_style_10(void)
{
     /*A base style*/
    static lv_style_t style_base;
    lv_style_init(&style_base);
    lv_style_set_bg_color(&style_base, lv_palette_main(LV_PALETTE_LIGHT_BLUE));
    lv_style_set_border_color(&style_base, lv_palette_darken(LV_PALETTE_LIGHT_BLUE, 3));
    lv_style_set_border_width(&style_base, 2);
    lv_style_set_radius(&style_base, 10);
    lv_style_set_shadow_width(&style_base, 10);
    lv_style_set_shadow_ofs_y(&style_base, 5);
    lv_style_set_shadow_opa(&style_base, LV_OPA_50);
    lv_style_set_text_color(&style_base, lv_color_white());
    lv_style_set_width(&style_base, 100);
    lv_style_set_height(&style_base, LV_SIZE_CONTENT);

    /*Set only the properties that should be different*/
    static lv_style_t style_warning;
    lv_style_init(&style_warning);
    lv_style_set_bg_color(&style_warning, lv_palette_main(LV_PALETTE_YELLOW));
    lv_style_set_border_color(&style_warning, lv_palette_darken(LV_PALETTE_YELLOW, 3));
    lv_style_set_text_color(&style_warning, lv_palette_darken(LV_PALETTE_YELLOW, 4));

    /*Create an object with the base style only*/
    lv_obj_t * obj_base = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj_base, &style_base, 0);
    lv_obj_align(obj_base, LV_ALIGN_LEFT_MID, 20, 0);

    lv_obj_t * label = lv_label_create(obj_base);
    lv_label_set_text(label, "Base");
    lv_obj_center(label);

    /*Create an other object with the base style and earnings style too*/
    lv_obj_t * obj_warning = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj_warning, &style_base, 0);
    lv_obj_add_style(obj_warning, &style_warning, 0);
    lv_obj_align(obj_warning, LV_ALIGN_RIGHT_MID, -20, 0);

    label = lv_label_create(obj_warning);
    lv_label_set_text(label, "Warning");
    lv_obj_center(label);
}

#endif

void lv_example_slider_2(void)
{
    /*Create a transition*/
    static const lv_style_prop_t props[] = {LV_STYLE_BG_COLOR, 0};
    static lv_style_transition_dsc_t transition_dsc;
    lv_style_transition_dsc_init(&transition_dsc, props, lv_anim_path_linear, 300, 0, NULL);

    static lv_style_t style_main;
    static lv_style_t style_indicator;
    static lv_style_t style_knob;
    static lv_style_t style_pressed_color;
    lv_style_init(&style_main);
    lv_style_set_bg_opa(&style_main, LV_OPA_COVER);
    lv_style_set_bg_color(&style_main, lv_color_hex3(0xbbb));
    lv_style_set_radius(&style_main, LV_RADIUS_CIRCLE);
    lv_style_set_pad_ver(&style_main, -2); /*Makes the indicator larger*/

    lv_style_init(&style_indicator);
    lv_style_set_bg_opa(&style_indicator, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indicator, lv_palette_main(LV_PALETTE_CYAN));
    lv_style_set_radius(&style_indicator, LV_RADIUS_CIRCLE);
    lv_style_set_transition(&style_indicator, &transition_dsc);

    lv_style_init(&style_knob);
    lv_style_set_bg_opa(&style_knob, LV_OPA_COVER);
    lv_style_set_bg_color(&style_knob, lv_palette_main(LV_PALETTE_CYAN));
    lv_style_set_border_color(&style_knob, lv_palette_darken(LV_PALETTE_CYAN, 3));
    lv_style_set_border_width(&style_knob, 2);
    lv_style_set_radius(&style_knob, LV_RADIUS_CIRCLE);
    lv_style_set_pad_all(&style_knob, 6); /*Makes the knob larger*/
    lv_style_set_transition(&style_knob, &transition_dsc);

    lv_style_init(&style_pressed_color);
    lv_style_set_bg_color(&style_pressed_color, lv_palette_darken(LV_PALETTE_CYAN, 2));

    /*Create a slider and add the style*/
    lv_obj_t * slider = lv_slider_create(lv_scr_act());
    lv_obj_remove_style_all(slider);        /*Remove the styles coming from the theme*/

    lv_obj_add_style(slider, &style_main, LV_PART_MAIN);
    lv_obj_add_style(slider, &style_indicator, LV_PART_INDICATOR);
    lv_obj_add_style(slider, &style_pressed_color, LV_PART_INDICATOR | LV_STATE_PRESSED);
    lv_obj_add_style(slider, &style_knob, LV_PART_KNOB);
    lv_obj_add_style(slider, &style_pressed_color, LV_PART_KNOB | LV_STATE_PRESSED);

    lv_obj_center(slider);
}
