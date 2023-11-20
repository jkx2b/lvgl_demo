#include "porting/lv_porting.h"
#include "lvgl.h"
#include "comp_demo.h"
#include <stdio.h>

void my_timer(lv_timer_t * timer)
{
	/*Use the user_data*/
	uint32_t * user_data = timer->user_data;
	printf("my_timer called with user data: %d\n", *user_data);
	printf("time=%d\n",lv_timer_get_idle());

	// /*Do something with LVGL*/
	// if(something_happened) 
	// {
	// 	something_happened = false;
	// 	lv_btn_create(lv_scr_act(), NULL);
	// }
}


void lv_example_img_1(void)
{
	static uint32_t data=100;
	lv_timer_t * timer=lv_timer_create(my_timer,500,&data);

	// lv_fs_stdio_init();

    // lv_bmp_init();
	// lv_png_init();
	// lv_split_jpeg_init();
	// LV_IMG_DECLARE(pic1);
    lv_obj_t * img = lv_img_create(lv_scr_act());
    // lv_img_set_src(img, "C:/picpic/pic1.bmp");
    // lv_img_set_src(img, "C:/picpic/pic1.png");
    // lv_img_set_src(img, "C:/picpic/code.png");
    // lv_img_set_src(img, "C:/picpic/code.bmp");
	// lv_img_set_src(img,"C:/picpic/pic1.jpg");
	// lv_img_set_src(img,"C:/picpic/pic2.bin");
	lv_img_set_src(img,"C:/picpic/pic1_bin.bin");
	// lv_img_set_src(img,&pic1);
	// lv_obj_t *gif_obj=lv_gif_create(lv_scr_act());
	// lv_img_set_src(gif_obj,"C:/picpic/pic1.gif");
    // lv_obj_center(gif_obj);

    lv_obj_center(img);
	lv_fs_file_t f;
	lv_fs_res_t res;
	res = lv_fs_open(&f, "C:/picpic/1.txt", LV_FS_MODE_RD);
	if(res != LV_FS_RES_OK) 
	{
		printf("open fail %d\n",res);
		return ;
	}

	uint32_t read_num;
	uint8_t buf[8];
	res = lv_fs_read(&f, buf, 8, &read_num);
	if(res != LV_FS_RES_OK || read_num != 8)
	{
	
		printf("read fail\n");
		return ;

	}
	printf("%s",buf);
	lv_fs_close(&f);

}