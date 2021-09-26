# M5Camera_OpenMV

このリポジトリは、M5Camera+OpenMVのMicroPython環境です。
以下リポジトリのソースコードをベースとして環境を構築しています。

This repository is a MicroPython for M5Camera and OpenMV. 
It is built based on the source code of the repository below.

+ https://github.com/sipeed/MaixPy
+ https://github.com/micropython/micropython
+ https://github.com/lemariva/micropython-camera-driver

# How to use

firmwareフォルダにビルド済みのbinファイルをおいています。以下コマンドで書き込んでください

I have a pre-built bin file in the firmware folder. Please write with the following command.

```
pip install esptool
esptool.py --port /dev/ttyUSB0 write_flash 0x8000 firmware/partition-table.bin 0x1000 firmware/bootloader.bin 0x10000 firmware/micropython.bin
```

# How to build

micropython、OpenMVのビルドを実行するには、ESP-IDFのインストールが必要です。
以下手順でインストールしてください。

ESP-IDF must be installed to execute the build of micropython and OpenMV.
Follow the steps below to install.

```
$ git clone -b v4.2 --recursive https://github.com/espressif/esp-idf.git
$ cd esp-idf
$ ./install.sh
$ source export.sh
```
ESP-IDF のインストール後、本リポジトリをクローンしてください

Clone this repository after installing ESP-IDF
```
git clone --recursive https://github.com/tenpa1105/M5Camera_OpenMV.git
```
クローン後、srcディレクトリに移動し、以下コマンドを入力してください
ビルドが実行されます

Move to *src* directory and enter the following command
```
cd src
make BOARD=GENERIC_CAM 
```

# How to flash

M5Camera にファームウェアを書き込む場合は以下コマンドを入力して下さい

Enter the following command to flash.
```
make BOARD=GENERIC_CAM deploy
```

# Sample script
グレイスケールで取得したQVGAサイズの画像を2値化、JPEGにエンコードし、UARTで送信するサンプルスクリプト

A sample script that binarizes a grayscle image, encodes it to JPEG, and sends it via UART.
```python
import image,camera,time
from machine import UART
import machine

camera.init(0, format=2)
pin = machine.Pin(14, machine.Pin.OUT)
pin.off()

uart = UART(1, 921600, tx=13, rx=4)
threshold =  [200, 255]
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
```

![sample](/img/sample_binary_m5stack.jpeg) 
