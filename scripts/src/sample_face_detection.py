# This script is based on 
#    https://github.com/openmv/openmv/blob/master/scripts/examples/OpenMV/07-Face-Detection/face_detection.py 
# OepnMV is licenced under the MIT Licence

import image,camera,time
from machine import UART
import machine

# camera.init(0, framesize=camera.FRAME_QVGA, format=camera.GRAYSCALE, xclk_freq=camera.XCLK_20MHz)
camera.init(0, framesize=camera.FRAME_QVGA, format=camera.RGB565, xclk_freq=camera.XCLK_20MHz)
pin = machine.Pin(14, machine.Pin.OUT)
pin.off()

# Load Haar Cascade
# By default this will use all stages, lower satges is faster but less accurate.
face_cascade = image.HaarCascade("frontalface", stages=25)
print(face_cascade)

uart = UART(1, 921600, tx=13, rx=4)

def sendJpeg(img):
    size = img.size()
    img_size1 = (size& 0xFF0000)>>16
    img_size2 = (size& 0x00FF00)>>8
    img_size3 = (size& 0x0000FF)>>0
    data_packet = bytearray([0xFF,0xD8,0xEA,0x01,img_size1,img_size2,img_size3,0x00,0x00,0x00])
    uart.write(data_packet)
    uart.write(img.to_bytes())

while True:
    img = camera.capture()
    objects = img.find_features(face_cascade, threshold=0.75, scale_factor=1.25)

    # Draw objects
    for r in objects:
        img.draw_rectangle(r)

    img.compress(60)
    sendJpeg(img)
    
