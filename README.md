# M5Camera_OpenMV

このリポジトリは、M5Camera+OpenMVのMicroPython環境です。
以下リポジトリのソースコードをベースとして環境を構築しています。

This repository is a MicroPython for M5Camera and OpenMV. 
It is built based on the source code of the repository below.

+ https://github.com/sipeed/MaixPy
+ https://github.com/micropython/micropython
+ https://github.com/lemariva/micropython-camera-driver



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
git clone  https://github.com/tenpa1105/M5Camera_OpenMV.git
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
make BOARD=GENERIC_CAM 
```
