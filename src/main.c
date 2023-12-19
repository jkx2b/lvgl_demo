#include "porting/lv_porting.h"
#include "lvgl.h"
#include "./demo_src/demo_src.h"
#include "./alarm_sq/ui.h"
#include "./demo_src/big_shit.h"
#include "./poc_src/poc.h"

int main(int argc, char const *argv[])
{
    lv_porting_init();

    // lv_obj_t *label = lv_label_create(lv_scr_act());
    // lv_label_set_text(label, "Hello world!!!!!!");
    // lv_obj_center(label);
    // test();
    // fk_demo();
    // fk_count();
    // lv_example_calendar_1();
    // lv_example_img_1();
    // ui_init();
    // menu_main();
    // big_shit();
    menu_init();
    while (1) {
        lv_timer_handler();
        lv_porting_delay();
    }
}
