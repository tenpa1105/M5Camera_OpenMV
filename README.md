# M5Camera_OpenMV

このリポジトリは、M5Camera+OpenMVのMicroPython環境です。
以下リポジトリのソースコードをベースとして環境を構築しています。

+ https://github.com/sipeed/MaixPy
+ https://github.com/micropython/micropython
+ https://github.com/lemariva/micropython-camera-driver

# How to build

micropython、OpenMVのビルドを実行するには、ESP-IDFのインストールが必要です。
以下手順でインストールしてください。

```
$ git clone -b v4.2 --recursive https://github.com/espressif/esp-idf.git
$ cd esp-idf
$ ./install.sh
$ source export.sh
```
ESP-IDF のインストール後、本リポジトリをクローンしてください

```
git clone  https://github.com/tenpa1105/M5Camera_OpenMV.git
```
