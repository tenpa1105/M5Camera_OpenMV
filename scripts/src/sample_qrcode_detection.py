# QR Code Detection Sample
# This script detects QR codes and sends the processed image via UART

import image, camera, time
from machine import UART
import machine

# Initialize camera with RGB565 format for better QR code detection
camera.init(0, framesize=camera.FRAME_QVGA, format=camera.RGB565, xclk_freq=camera.XCLK_20MHz)

# Turn off the LED (Pin 14)
pin = machine.Pin(14, machine.Pin.OUT)
pin.off()

# Initialize UART for image transmission
uart = UART(1, 921600, tx=13, rx=4)

def sendJpeg(img):
    """Send JPEG image via UART with header"""
    size = img.size()
    img_size1 = (size & 0xFF0000) >> 16
    img_size2 = (size & 0x00FF00) >> 8
    img_size3 = (size & 0x0000FF) >> 0
    data_packet = bytearray([0xFF, 0xD8, 0xEA, 0x01, img_size1, img_size2, img_size3, 0x00, 0x00, 0x00])
    uart.write(data_packet)
    uart.write(img.to_bytes())

print("QR Code Detection Started")

while True:
    # Capture image from camera
    img = camera.capture()

    # Detect QR codes in the image
    # Returns a list of qrcode objects
    qrcodes = img.find_qrcodes()

    # Process detected QR codes
    for qrcode in qrcodes:
        # Draw rectangle around QR code
        img.draw_rectangle(qrcode.rect(), color=(255, 0, 0))

        # Print QR code data to console
        print("QR Code detected:")
        print("  Data: %s" % qrcode.payload())
        print("  Type: %s" % qrcode.type())
        print("  Position: (%d, %d, %d, %d)" % qrcode.rect())
        print("---")

    # If no QR code detected, print a message
    if not qrcodes:
        print("No QR code detected")

    # Compress image to JPEG format (quality: 60%)
    img.compress(60)

    # Send image via UART
    sendJpeg(img)

    # Small delay to control frame rate
    time.sleep_ms(100)
