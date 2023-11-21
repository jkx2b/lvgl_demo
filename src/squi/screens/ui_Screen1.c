// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.3
// LVGL version: 8.3.6
// Project name: SquareLine_menu

#include "../ui.h"

void ui_Screen1_screen_init(void)
{
ui_Screen1 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x363636), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel1 = lv_obj_create(ui_Screen1);
lv_obj_set_height( ui_Panel1, 16);
lv_obj_set_width( ui_Panel1, lv_pct(100));
lv_obj_clear_flag( ui_Panel1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0x3480FF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_border_width(ui_Panel1, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_outline_width(ui_Panel1, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_outline_pad(ui_Panel1, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);

ui_Image6 = lv_img_create(ui_Panel1);
lv_img_set_src(ui_Image6, &ui_img_760006719);
lv_obj_set_width( ui_Image6, LV_SIZE_CONTENT);  /// 22
lv_obj_set_height( ui_Image6, LV_SIZE_CONTENT);   /// 16
lv_obj_set_x( ui_Image6, -12 );
lv_obj_set_y( ui_Image6, 0 );
lv_obj_set_align( ui_Image6, LV_ALIGN_LEFT_MID );
lv_obj_add_flag( ui_Image6, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image6, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Image7 = lv_img_create(ui_Panel1);
lv_img_set_src(ui_Image7, &ui_img_1187237374);
lv_obj_set_width( ui_Image7, LV_SIZE_CONTENT);  /// 9
lv_obj_set_height( ui_Image7, LV_SIZE_CONTENT);   /// 16
lv_obj_set_x( ui_Image7, 12 );
lv_obj_set_y( ui_Image7, 0 );
lv_obj_set_align( ui_Image7, LV_ALIGN_LEFT_MID );
lv_obj_add_flag( ui_Image7, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image7, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Image8 = lv_img_create(ui_Panel1);
lv_img_set_src(ui_Image8, &ui_img_26967346);
lv_obj_set_width( ui_Image8, LV_SIZE_CONTENT);  /// 24
lv_obj_set_height( ui_Image8, LV_SIZE_CONTENT);   /// 16
lv_obj_set_x( ui_Image8, 12 );
lv_obj_set_y( ui_Image8, 0 );
lv_obj_set_align( ui_Image8, LV_ALIGN_RIGHT_MID );
lv_obj_add_flag( ui_Image8, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image8, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Image9 = lv_img_create(ui_Panel1);
lv_img_set_src(ui_Image9, &ui_img_1088127317);
lv_obj_set_width( ui_Image9, LV_SIZE_CONTENT);  /// 12
lv_obj_set_height( ui_Image9, LV_SIZE_CONTENT);   /// 16
lv_obj_set_x( ui_Image9, -27 );
lv_obj_set_y( ui_Image9, 0 );
lv_obj_set_align( ui_Image9, LV_ALIGN_RIGHT_MID );
lv_obj_add_flag( ui_Image9, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image9, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Image10 = lv_img_create(ui_Panel1);
lv_img_set_src(ui_Image10, &ui_img_a_png);
lv_obj_set_width( ui_Image10, LV_SIZE_CONTENT);  /// 11
lv_obj_set_height( ui_Image10, LV_SIZE_CONTENT);   /// 16
lv_obj_set_x( ui_Image10, -14 );
lv_obj_set_y( ui_Image10, 0 );
lv_obj_set_align( ui_Image10, LV_ALIGN_RIGHT_MID );
lv_obj_add_flag( ui_Image10, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image10, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Panel2 = lv_obj_create(ui_Screen1);
lv_obj_set_height( ui_Panel2, 13);
lv_obj_set_width( ui_Panel2, lv_pct(100));
lv_obj_set_align( ui_Panel2, LV_ALIGN_BOTTOM_LEFT );
lv_obj_clear_flag( ui_Panel2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0x3480FF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel3 = lv_obj_create(ui_Screen1);
lv_obj_set_height( ui_Panel3, 45);
lv_obj_set_width( ui_Panel3, lv_pct(100));
lv_obj_set_x( ui_Panel3, 0 );
lv_obj_set_y( ui_Panel3, 16 );
lv_obj_clear_flag( ui_Panel3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel3, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel3, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel4 = lv_obj_create(ui_Screen1);
lv_obj_set_height( ui_Panel4, 53);
lv_obj_set_width( ui_Panel4, lv_pct(100));
lv_obj_set_x( ui_Panel4, 0 );
lv_obj_set_y( ui_Panel4, 62 );
lv_obj_clear_flag( ui_Panel4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image5 = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Image5, &ui_img_slec_png);
lv_obj_set_width( ui_Image5, LV_SIZE_CONTENT);  /// 44
lv_obj_set_height( ui_Image5, LV_SIZE_CONTENT);   /// 44
lv_obj_set_x( ui_Image5, 58 );
lv_obj_set_y( ui_Image5, 66 );
lv_obj_add_flag( ui_Image5, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image5, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Image2 = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Image2, &ui_img_1_png);
lv_obj_set_width( ui_Image2, LV_SIZE_CONTENT);  /// 36
lv_obj_set_height( ui_Image2, LV_SIZE_CONTENT);   /// 36
lv_obj_set_x( ui_Image2, 62 );
lv_obj_set_y( ui_Image2, 70 );
lv_obj_add_flag( ui_Image2, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Image3 = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Image3, &ui_img_2_png);
lv_obj_set_width( ui_Image3, LV_SIZE_CONTENT);  /// 30
lv_obj_set_height( ui_Image3, LV_SIZE_CONTENT);   /// 29
lv_obj_set_x( ui_Image3, 16 );
lv_obj_set_y( ui_Image3, 73 );
lv_obj_add_flag( ui_Image3, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Image4 = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Image4, &ui_img_3_png);
lv_obj_set_width( ui_Image4, LV_SIZE_CONTENT);  /// 30
lv_obj_set_height( ui_Image4, LV_SIZE_CONTENT);   /// 30
lv_obj_set_x( ui_Image4, 114 );
lv_obj_set_y( ui_Image4, 73 );
lv_obj_add_flag( ui_Image4, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

}
