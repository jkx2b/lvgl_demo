SET(SOURCES components/ui_comp_switch1.c
    components/ui_comp.c
    screens/ui_Screen1.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    images/ui_img_760006719.c
    images/ui_img_1187237374.c
    images/ui_img_26967346.c
    images/ui_img_1088127317.c
    images/ui_img_a_png.c
    images/ui_img_slec_png.c
    images/ui_img_1_png.c
    images/ui_img_2_png.c
    images/ui_img_3_png.c
    images/ui_img_6_png.c
    images/ui_img_7_png.c)

add_library(ui ${SOURCES})
