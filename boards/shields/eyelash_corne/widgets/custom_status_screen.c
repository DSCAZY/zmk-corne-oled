#include <zmk/display/widgets/output_status.h>
#include <zmk/display/status_screen.h>
#include <lvgl.h>
#include "zmk_logo.h"

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen;
    screen = lv_obj_create(NULL);

    // Создаем объект для картинки
    lv_obj_t * logo_icon;
    logo_icon = lv_img_create(screen);
    
    // Указываем источник — вашу структуру zmk_logo из zmk_logo.c
    lv_img_set_src(logo_icon, &zmk_logo);
    
    // Центрируем картинку
    lv_obj_align(logo_icon, LV_ALIGN_CENTER, 0, 0);

    return screen;
}