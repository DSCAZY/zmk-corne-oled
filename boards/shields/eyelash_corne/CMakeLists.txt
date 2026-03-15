if (CONFIG_ZMK_DISPLAY)
    target_sources(app PRIVATE widgets/custom_status_screen.c widgets/zmk_logo.c)
endif()