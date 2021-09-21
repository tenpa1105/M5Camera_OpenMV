# Set location of base MicroPython directory.
if(NOT MICROPY_DIR)
    get_filename_component(MICROPY_DIR ${PROJECT_DIR}/../micropython ABSOLUTE)
endif()

# Include core source components.
include(${MICROPY_DIR}/py/py.cmake)

if(NOT CMAKE_BUILD_EARLY_EXPANSION)
    include(${MICROPY_DIR}/py/usermod.cmake)
    include(${MICROPY_DIR}/extmod/extmod.cmake)
endif()

set(MICROPY_QSTRDEFS_PORT
    ${PROJECT_DIR}/qstrdefsport.h
)

set(MICROPY_SOURCE_SHARED
    ${MICROPY_DIR}/shared/readline/readline.c
    ${MICROPY_DIR}/shared/netutils/netutils.c
    ${MICROPY_DIR}/shared/timeutils/timeutils.c
    ${MICROPY_DIR}/shared/runtime/interrupt_char.c
    ${MICROPY_DIR}/shared/runtime/stdout_helpers.c
    ${MICROPY_DIR}/shared/runtime/sys_stdio_mphal.c
    ${MICROPY_DIR}/shared/runtime/pyexec.c
)

set(MICROPY_SOURCE_LIB
    ${MICROPY_DIR}/lib/littlefs/lfs1.c
    ${MICROPY_DIR}/lib/littlefs/lfs1_util.c
    ${MICROPY_DIR}/lib/littlefs/lfs2.c
    ${MICROPY_DIR}/lib/littlefs/lfs2_util.c
    ${MICROPY_DIR}/lib/mbedtls_errors/mp_mbedtls_errors.c
    ${MICROPY_DIR}/lib/oofatfs/ff.c
    ${MICROPY_DIR}/lib/oofatfs/ffunicode.c
)
if(IDF_TARGET STREQUAL "esp32c3")
    list(APPEND MICROPY_SOURCE_LIB ${MICROPY_DIR}/shared/runtime/gchelper_generic.c)
endif()

set(MICROPY_SOURCE_DRIVERS
    ${MICROPY_DIR}/drivers/bus/softspi.c
    ${MICROPY_DIR}/drivers/dht/dht.c
)

set(MICROPY_SOURCE_PORT
    ${PROJECT_DIR}/main.c
    ${PROJECT_DIR}/../micropython/ports/esp32/uart.c
    ${PROJECT_DIR}/../micropython/ports/esp32/usb.c
    ${PROJECT_DIR}/../micropython/ports/esp32/usb_serial_jtag.c
    ${PROJECT_DIR}/../micropython/ports/esp32/gccollect.c
    ${PROJECT_DIR}/../micropython/ports/esp32/mphalport.c
    ${PROJECT_DIR}/../micropython/ports/esp32/fatfs_port.c
    ${PROJECT_DIR}/../micropython/ports/esp32/help.c
    ${PROJECT_DIR}/../micropython/ports/esp32/modutime.c
    ${PROJECT_DIR}/../micropython/ports/esp32/moduos.c
    ${PROJECT_DIR}/../micropython/ports/esp32/machine_bitstream.c
    ${PROJECT_DIR}/../micropython/ports/esp32/machine_timer.c
    ${PROJECT_DIR}/../micropython/ports/esp32/machine_pin.c
    ${PROJECT_DIR}/../micropython/ports/esp32/machine_touchpad.c
    ${PROJECT_DIR}/../micropython/ports/esp32/machine_adc.c
    ${PROJECT_DIR}/../micropython/ports/esp32/machine_dac.c
    ${PROJECT_DIR}/../micropython/ports/esp32/machine_i2c.c
    ${PROJECT_DIR}/../micropython/ports/esp32/machine_i2s.c
    ${PROJECT_DIR}/../micropython/ports/esp32/machine_uart.c
    ${PROJECT_DIR}/../micropython/ports/esp32/modmachine.c
    ${PROJECT_DIR}/../micropython/ports/esp32/modnetwork.c
    ${PROJECT_DIR}/../micropython/ports/esp32/network_lan.c
    ${PROJECT_DIR}/../micropython/ports/esp32/network_ppp.c
    ${PROJECT_DIR}/../micropython/ports/esp32/mpnimbleport.c
    ${PROJECT_DIR}/../micropython/ports/esp32/modsocket.c
    ${PROJECT_DIR}/../micropython/ports/esp32/modesp.c
    ${PROJECT_DIR}/../micropython/ports/esp32/esp32_nvs.c
    ${PROJECT_DIR}/../micropython/ports/esp32/esp32_partition.c
    ${PROJECT_DIR}/../micropython/ports/esp32/esp32_rmt.c
    ${PROJECT_DIR}/../micropython/ports/esp32/esp32_ulp.c
    ${PROJECT_DIR}/../micropython/ports/esp32/modesp32.c
    ${PROJECT_DIR}/../micropython/ports/esp32/machine_hw_spi.c
    ${PROJECT_DIR}/../micropython/ports/esp32/machine_wdt.c
    ${PROJECT_DIR}/../micropython/ports/esp32/mpthreadport.c
    ${PROJECT_DIR}/../micropython/ports/esp32/machine_rtc.c
    ${PROJECT_DIR}/../micropython/ports/esp32/machine_sdcard.c
    ${PROJECT_DIR}/modcamera.c
)
set(OPENMV_SOURCE
    ${PROJECT_DIR}/../omv/array.c
    ${PROJECT_DIR}/../omv/fb_alloc.c
    ${PROJECT_DIR}/../omv/framebuffer.c
    ${PROJECT_DIR}/../omv/mutex.c
    ${PROJECT_DIR}/../omv/omv.c
    ${PROJECT_DIR}/../omv/umm_malloc.c
    ${PROJECT_DIR}/../omv/vfs_wrapper.c
    ${PROJECT_DIR}/../omv/xalloc.c
    ${PROJECT_DIR}/../omv/img/affine.c
    ${PROJECT_DIR}/../omv/img/agast.c
    ${PROJECT_DIR}/../omv/img/apriltag.c
    ${PROJECT_DIR}/../omv/img/binary.c
    ${PROJECT_DIR}/../omv/img/blob.c
#   ${PROJECT_DIR}/../omv/img/bmp.c
    ${PROJECT_DIR}/../omv/img/clahe.c
    ${PROJECT_DIR}/../omv/img/collections.c
    ${PROJECT_DIR}/../omv/img/conv.c
    ${PROJECT_DIR}/../omv/img/dmtx.c
    ${PROJECT_DIR}/../omv/img/draw.c
    ${PROJECT_DIR}/../omv/img/edge.c
    ${PROJECT_DIR}/../omv/img/eye.c
    ${PROJECT_DIR}/../omv/img/fast.c
    ${PROJECT_DIR}/../omv/img/fft.c
    ${PROJECT_DIR}/../omv/img/filter.c
    ${PROJECT_DIR}/../omv/img/fmath.c
    ${PROJECT_DIR}/../omv/img/font.c
    ${PROJECT_DIR}/../omv/img/fsort.c
    ${PROJECT_DIR}/../omv/img/gif.c
    ${PROJECT_DIR}/../omv/img/haar.c
    ${PROJECT_DIR}/../omv/img/hog.c
    ${PROJECT_DIR}/../omv/img/hough.c
    ${PROJECT_DIR}/../omv/img/imlib.c
    ${PROJECT_DIR}/../omv/img/integral.c
    ${PROJECT_DIR}/../omv/img/integral_mw.c
    ${PROJECT_DIR}/../omv/img/invariant_tab.c
    ${PROJECT_DIR}/../omv/img/jpeg.c
    ${PROJECT_DIR}/../omv/img/kmeans.c
    ${PROJECT_DIR}/../omv/img/lab_tab.c
    ${PROJECT_DIR}/../omv/img/lbp.c
    ${PROJECT_DIR}/../omv/img/line.c
    ${PROJECT_DIR}/../omv/img/lsd.c
    ${PROJECT_DIR}/../omv/img/mathop.c
    ${PROJECT_DIR}/../omv/img/mjpeg.c
    ${PROJECT_DIR}/../omv/img/orb.c
    ${PROJECT_DIR}/../omv/img/phasecorrelation.c
#   ${PROJECT_DIR}/../omv/img/picojpeg.c
#   ${PROJECT_DIR}/../omv/img/picojpeg_util.c
    ${PROJECT_DIR}/../omv/img/point.c
    ${PROJECT_DIR}/../omv/img/pool.c
#   ${PROJECT_DIR}/../omv/img/ppm.c
    ${PROJECT_DIR}/../omv/img/qrcode.c
    ${PROJECT_DIR}/../omv/img/qsort.c
    ${PROJECT_DIR}/../omv/img/rainbow_tab.c
    ${PROJECT_DIR}/../omv/img/rectangle.c
    ${PROJECT_DIR}/../omv/img/rgb2rgb_tab.c
    ${PROJECT_DIR}/../omv/img/selective_search.c
    ${PROJECT_DIR}/../omv/img/shadow_removal.c
    ${PROJECT_DIR}/../omv/img/sincos_tab.c
    ${PROJECT_DIR}/../omv/img/stats.c
    ${PROJECT_DIR}/../omv/img/template.c
    ${PROJECT_DIR}/../omv/img/xyz_tab.c
    ${PROJECT_DIR}/../omv/img/yuv_tab.c
    ${PROJECT_DIR}/../omv/img/zbar.c
    ${PROJECT_DIR}/../omv/py/image0.c
#   ${PROJECT_DIR}/../omv/py/py_gif.c
    ${PROJECT_DIR}/../omv/py/py_helper.c
    ${PROJECT_DIR}/../omv/py/py_image.c
#   ${PROJECT_DIR}/../omv/py/py_lcd.c
#   ${PROJECT_DIR}/../omv/py/py_mjpeg.c
    ${PROJECT_DIR}/../omv/py/py_omv.c
#   ${PROJECT_DIR}/../omv/py/py_sensor.c
)

set(MICROPY_ESP32_PORT_DIR 
    ${PROJECT_DIR}/../micropython/ports/esp32
)
set(OPENMV_DIR 
    ${PROJECT_DIR}/../omv
    ${PROJECT_DIR}/../omv/include
    ${PROJECT_DIR}/../omv/img/include
    ${PROJECT_DIR}/../omv/boards/MAIX
    ${PROJECT_DIR}/../omv/py
    ${PROJECT_DIR}/../omv/py/include
)

set(MICROPY_SOURCE_QSTR
    ${MICROPY_SOURCE_PY}
    ${MICROPY_SOURCE_EXTMOD}
    ${MICROPY_SOURCE_USERMOD}
    ${MICROPY_SOURCE_SHARED}
    ${MICROPY_SOURCE_LIB}
    ${MICROPY_SOURCE_PORT}
    ${OPENMV_SOURCE}
)

set(IDF_COMPONENTS
    app_update
    bootloader_support
    bt
    driver
    esp_common
    esp_eth
    esp_event
    esp_ringbuf
    esp_rom
    esp_wifi
    freertos
    heap
    log
    lwip
    mbedtls
    mdns
    newlib
    nvs_flash
    sdmmc
    soc
    spi_flash
    tcpip_adapter
    ulp
    vfs
    xtensa
    esp32-camera
)

if(IDF_VERSION_MINOR GREATER_EQUAL 1)
    list(APPEND IDF_COMPONENTS esp_netif)
endif()

if(IDF_VERSION_MINOR GREATER_EQUAL 2)
    list(APPEND IDF_COMPONENTS esp_system)
    list(APPEND IDF_COMPONENTS esp_timer)
endif()

if(IDF_VERSION_MINOR GREATER_EQUAL 3)
    list(APPEND IDF_COMPONENTS esp_hw_support)
    list(APPEND IDF_COMPONENTS esp_pm)
    list(APPEND IDF_COMPONENTS hal)
endif()

if(IDF_TARGET STREQUAL "esp32")
    list(APPEND IDF_COMPONENTS esp32)
elseif(IDF_TARGET STREQUAL "esp32c3")
    list(APPEND IDF_COMPONENTS esp32c3)
    list(APPEND IDF_COMPONENTS riscv)
elseif(IDF_TARGET STREQUAL "esp32s2")
    list(APPEND IDF_COMPONENTS esp32s2)
    list(APPEND IDF_COMPONENTS tinyusb)
elseif(IDF_TARGET STREQUAL "esp32s3")
    list(APPEND IDF_COMPONENTS esp32s3)
    list(APPEND IDF_COMPONENTS tinyusb)
endif()

# Register the main IDF component.
idf_component_register(
    SRCS
        ${MICROPY_SOURCE_PY}
        ${MICROPY_SOURCE_EXTMOD}
        ${MICROPY_SOURCE_SHARED}
        ${MICROPY_SOURCE_LIB}
        ${MICROPY_SOURCE_DRIVERS}
        ${MICROPY_SOURCE_PORT}
        ${OPENMV_SOURCE}
    INCLUDE_DIRS
        ${MICROPY_INC_CORE}
        ${MICROPY_INC_USERMOD}
        ${MICROPY_PORT_DIR}
        ${MICROPY_ESP32_PORT_DIR}
        ${MICROPY_BOARD_DIR}
        ${CMAKE_BINARY_DIR}
        ${OPENMV_DIR}
    REQUIRES
        ${IDF_COMPONENTS}
)

# Set the MicroPython target as the current (main) IDF component target.
set(MICROPY_TARGET ${COMPONENT_TARGET})

# Define mpy-cross flags, for use with frozen code.
set(MICROPY_CROSS_FLAGS -march=xtensawin)

# Set compile options for this port.
target_compile_definitions(${MICROPY_TARGET} PUBLIC
    ${MICROPY_DEF_CORE}
    MICROPY_ESP_IDF_4=1
    MICROPY_VFS_FAT=1
    MICROPY_VFS_LFS2=1
    FFCONF_H=\"${MICROPY_OOFATFS_DIR}/ffconf.h\"
    LFS1_NO_MALLOC LFS1_NO_DEBUG LFS1_NO_WARN LFS1_NO_ERROR LFS1_NO_ASSERT
    LFS2_NO_MALLOC LFS2_NO_DEBUG LFS2_NO_WARN LFS2_NO_ERROR LFS2_NO_ASSERT
)

# Disable some warnings to keep the build output clean.
target_compile_options(${MICROPY_TARGET} PUBLIC
    -Wno-clobbered
    -Wno-deprecated-declarations
    -Wno-missing-field-initializers
)

# Add additional extmod and usermod components.
target_link_libraries(${MICROPY_TARGET} micropy_extmod_btree)
target_link_libraries(${MICROPY_TARGET} usermod)


# Collect all of the include directories and compile definitions for the IDF components.
foreach(comp ${IDF_COMPONENTS})
    micropy_gather_target_properties(__idf_${comp})
endforeach()

if(IDF_VERSION_MINOR GREATER_EQUAL 2)
    # These paths cannot currently be found by the IDF_COMPONENTS search loop above,
    # so add them explicitly.
    list(APPEND MICROPY_CPP_INC_EXTRA ${IDF_PATH}/components/soc/soc/${IDF_TARGET}/include)
    list(APPEND MICROPY_CPP_INC_EXTRA ${IDF_PATH}/components/soc/soc/include)
    if(IDF_VERSION_MINOR GREATER_EQUAL 3)
        list(APPEND MICROPY_CPP_INC_EXTRA ${IDF_PATH}/components/tinyusb/additions/include)
        list(APPEND MICROPY_CPP_INC_EXTRA ${IDF_PATH}/components/tinyusb/tinyusb/src)
    endif()
endif()

# Include the main MicroPython cmake rules.
include(${MICROPY_DIR}/py/mkrules.cmake)
