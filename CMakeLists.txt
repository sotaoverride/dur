if (TARGET tinyusb_device)
    add_executable(motor
            motor.c
            )

    # pull in common dependencies
    target_link_libraries(motor pico_stdlib hardware_pwm)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(motor 1)
    pico_enable_stdio_uart(motor 0)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(motor)

    # add url via pico_set_program_url
    example_auto_set_url(motor)
elseif(PICO_ON_DEVICE)
    message(WARNING "not building switch because TinyUSB submodule is not initialized in the SDK")
endif()

