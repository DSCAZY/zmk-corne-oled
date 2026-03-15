# Проверяем, включен ли дисплей в конфиге
if (CONFIG_ZMK_DISPLAY)
    # Добавляем папку widgets в пути поиска заголовочных файлов (.h)
    zephyr_include_directories(widgets)

    # Указываем файлы для компиляции
    target_sources(app PRIVATE 
        widgets/custom_status_screen.c 
        widgets/zmk_logo.c
    )
endif()
