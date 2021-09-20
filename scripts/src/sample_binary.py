import image,camera,time
from machine import UART
import machine

camera.init(0, format=camera.GRAYSCALE)
pin = machine.Pin(14, machine.Pin.OUT)
pin.off()

uart = UART(1, 921600, tx=13, rx=4)
threshold =  [201, 255]
while True:
    img = camera.capture()
    img.binary([threshold])
    img.compress(50)
    size = img.size()

    img_size1 = (size& 0xFF0000)>>16
    img_size2 = (size& 0x00FF00)>>8
    img_size3 = (size& 0x0000FF)>>0
    data_packet = bytearray([0xFF,0xD8,0xEA,0x01,img_size1,img_size2,img_size3,0x00,0x00,0x00])

    uart.write(data_packet)
    uart.write(img.to_bytes())
    print(time.ticks_ms())