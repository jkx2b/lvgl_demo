#include "count_demo.h"

#include "porting/lv_porting.h"
#include "lvgl.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUM 10                 	// 设置文本框显示最大位数

static lv_obj_t* ta;				// 文本框对象
static lv_obj_t* btnm1;				// 按钮对象
static char result[MAX_NUM];		// 缓存结果



static double save_num(char* num)	// 将字符串保存成浮点数
{
    return atof(num);
}

static char judge_num(double num)	// 比较数字尾数有没有超过指定数目
{
    char n[100];
    sprintf(n,"%g", num);
    printf("%d",strlen(n));
    if (strlen(n)<MAX_NUM)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

static void calculate(double before, double now, char operate, char* num)	// 计算浮点数
{
    double result = now;
    switch (operate)
    {
    case '+':
        result = before + now;
        break;
    case '-':
        result = before - now;
        break;
    case '*':
        result = before * now;
        break;
    case '/':
        result = before / now;
        break;
    default:
        break;
    }
    printf("result:%llf\n",result);
    sprintf(num, "%g", result);
}

static void event_handler( lv_event_t *event)
{
    lv_obj_t* obj=lv_event_get_target(event);
    if (event->code == LV_EVENT_VALUE_CHANGED) {
        static char error = 0;
        static double before = 0;
        volatile double now = 0;
        static char operate = '\0';
        static char num[MAX_NUM];
        // const char* txt = lv_btnmatrix_get_active_btn_text(obj);	// 获取按键值  //弃用捏用个毛
        const char* txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));

        if (error == 0)
        {
            switch (txt[0])
            {
            case '=':
                if (judge_num(before) == 0)
                {
                    now = save_num(num);
                    calculate(before,now,operate,num);
                    operate = '\0';
                    before = save_num(num);
                }
                else
                {
                    error = 1;
                    lv_textarea_set_text(ta, "EOR");
                    printf("error\n");
                }
                break;
            case 'D':
                num[strlen(num) - 1] = '\0';
                break;
            case '+':
                now = save_num(num);
                if (operate != '\0')
                {
                    calculate(before, now, operate, num);
                    before = save_num(num);;
                }
                else
                {
                    before = now;
                }
                operate = '+';
                memset(num, 0, MAX_NUM);
                break;
            case '-':
                now = save_num(num);
                if (operate != '\0')
                {
                    calculate(before, now, operate, num);
                    before = save_num(num);;
                }
                else
                {
                    before = now;
                }
                operate = '-';
                memset(num, 0, MAX_NUM);
                break;
            case '*':
                now = save_num(num);
                if (operate != '\0')
                {
                    calculate(before, now, operate, num);
                    before = save_num(num);;
                }
                else
                {
                    before = now;
                }
                memset(num, 0, MAX_NUM);
                operate = '*';
                break;
            case '/':
                now = save_num(num);
                if (operate != '\0')
                {
                    calculate(before, now, operate, num);
                    before = save_num(num);;
                }
                else
                {
                    before = now;
                }
                memset(num, 0, MAX_NUM);
                operate = '/';
                break;
            case ' ':
                break;
            default:
                if (strlen(num) < MAX_NUM)
                {
                    num[strlen(num)] = txt[0];
                }
                break;
            }
        }
        if (txt[0] == 'C')
        {
            memset(num, 0, MAX_NUM);
            memset(result, 0, MAX_NUM);
            before = 0;
            now = 0;
            error = 0;
            operate = '\0';
        }
        lv_textarea_set_text(ta, num);
        printf("before:%llf,now:%llf\n", before, now);
    }
}

static void ta_event_cb( lv_event_t *event)
{
    lv_obj_t* ta=lv_event_get_target(event);
    if (event->code == LV_EVENT_VALUE_CHANGED) {
        const char* txt = lv_textarea_get_text(ta);
        
    }
}

static const char* btnm_map[] = { "C", "D", "/", "\n",
                                  "1", "2", "3", "+", "\n",
                                  "4", "5", "6", "-", "\n",
                                  "7", "8", "9", "*", "\n",
                                  ".", "0","=", "" };

static void lv_ex_btnmatrix_1(void)
{
    btnm1 = lv_btnmatrix_create(lv_scr_act());                    // 生成矩阵(默认5个)按钮
    lv_btnmatrix_set_map(btnm1, btnm_map);                              // 按照数组生成排列按钮
    lv_btnmatrix_set_btn_width(btnm1, 17, 2);                           // 设置第11个按钮的比重为2（默认为1）这将导致矩阵按键重绘
    lv_btnmatrix_set_btn_width(btnm1, 0, 3);
    lv_btnmatrix_set_btn_width(btnm1, 1, 3);
    lv_btnmatrix_set_btn_width(btnm1, 2, 2);
    lv_btnmatrix_set_btn_ctrl(btnm1, 17, LV_BTNMATRIX_CTRL_CHECKED);// 设置按钮矩阵的按钮属性（变成选中状态）
    // lv_obj_set_event_cb(btnm1, event_handler);                          // 设置按钮回调函数 //又是一个弃用的这版本变化真大
    lv_obj_add_event_cb(btnm1, event_handler,LV_EVENT_ALL,NULL);                          // 设置按钮回调函数
    lv_obj_set_size(btnm1, LV_HOR_RES, LV_VER_RES * 6 / 7);             // 先调整
    lv_obj_align(btnm1,  LV_ALIGN_OUT_BOTTOM_LEFT, 0, 68);           // 再移动
}

static void lv_ex_textarea_3(void)
{
    /* Create the text area */
    ta = lv_textarea_create(lv_scr_act());                        // 生成文本框控件
    // lv_obj_set_event_cb(ta, ta_event_cb);                               // 设置文本框回调函数 //改!
    lv_obj_add_event_cb(ta, ta_event_cb,LV_EVENT_ALL,NULL);                               // 设置文本框回调函数
    lv_textarea_set_accepted_chars(ta, "0123456789+-.*/EOR");           // 设置文本框允许被输入的数字
    lv_textarea_set_max_length(ta, MAX_NUM);                                 // 设置文本框允许最大储存的数字
    lv_textarea_set_one_line(ta, true);                                 // 设置文本框成单行
    lv_textarea_set_text(ta, "");                                       // 设置文本框文字
    // lv_textarea_set_cursor_flash(ta, true);                               // 设置溢出提示  //似乎用不了了
    lv_obj_set_size(ta, LV_HOR_RES, LV_VER_RES *18/ 100);                    // 先调整
    lv_obj_align(ta,  LV_ALIGN_OUT_TOP_LEFT, 0, 0);                 // 再移动
    static lv_style_t my_style;
    lv_style_init(&my_style);
    lv_style_set_text_color(&my_style,  lv_color_hex(0x000000));
    lv_style_set_text_font(&my_style,  &lv_font_montserrat_48);
    lv_obj_add_style(ta, &my_style, LV_PART_MAIN);
}



void fk_count(void)
{
    lv_ex_btnmatrix_1();
    lv_ex_textarea_3();
}