#include <zmk/display/status_screen.h>
#include <zmk/display/widgets/layer_status.h>
#include <zmk/display/widgets/battery_status.h>
#include <zmk/display/widgets/output_status.h>
#include <lvgl.h>
#include "zmk_logo.h"

// Объявляем структуры для стандартных виджетов
static struct zmk_widget_layer_status layer_status_widget;
static struct zmk_widget_battery_status battery_status_widget;
static struct zmk_widget_output_status output_status_widget;

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen;
    screen = lv_obj_create(NULL);

    // ПРОВЕРКА: Если это ПРАВАЯ сторона (Peripheral)
#if !IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
    
    // Рисуем ваше лого 32x128
    lv_obj_t * logo_icon;
    logo_icon = lv_img_create(screen);
    lv_img_set_src(logo_icon, &zmk_logo);
    lv_obj_align(logo_icon, LV_ALIGN_CENTER, 0, 0);

#else
    // ЛЕВАЯ сторона (Central) - Стандартные виджеты
    
    // Статус Bluetooth / USB (сверху)
    zmk_widget_output_status_init(&output_status_widget, screen);
    lv_obj_align(zmk_widget_output_status_obj(&output_status_widget), LV_ALIGN_TOP_LEFT, 0, 5);

    // Батарея (сверху справа)
    zmk_widget_battery_status_init(&battery_status_widget, screen);
    lv_obj_align(zmk_widget_battery_status_obj(&battery_status_widget), LV_ALIGN_TOP_RIGHT, 0, 5);

    // Текущий слой (по центру или снизу)
    zmk_widget_layer_status_init(&layer_status_widget, screen);
    lv_obj_align(zmk_widget_layer_status_obj(&layer_status_widget), LV_ALIGN_BOTTOM_MID, 0, -10);

#endif

    return screen;
}