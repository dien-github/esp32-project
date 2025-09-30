# Day 1
## Install ESP-IDF + toolchain + dependencies

### 1. Cài các package cần thiết (Ubuntu/Debian)
```bash
sudo apt update
sudo apt-get install git wget flex bison gperf python3 python3-pip python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0
```

### 2. Clone ESP-IDF (lấy toàn bộ submodule)

```bash
mkdir -p ~/esp
cd ~/esp
git clone -b v5.5.1 --recursive https://github.com/espressif/esp-idf.git
```

### 3. Cài toolchain & python packages được ESP-IDF yêu cầu
Xuất file log nếu cần
```bash
cd ~/esp/esp-idf
./install.sh esp32 2>&1 | tee install_esp_idf.txt
```

### 4. Source môi trường cho shell hiện tại
```bash
source ./export.sh
```

### 5. Kiểm tra idf.py
```bash
idf.py --version
```

# Day 2
## Run project Blink
Copy example
```bash
cp -r ~/esp/esp-idf/examples/get-started/hello-world ~/esp/.
```

## Set target/menuconfig for which the project is built.
`idf.py set-target` will clear the build directory and re-generate the `sdkconfig` file from scratch. The old sdkconfig file will be saved as `sdkconfig.old`.

Q: Why we must set target for project before build it?
```bash
idf.py set-target esp32
```


## Build
Use the blink example.
```bash
idf.py build
# idf.py build 2>&1 | tee build_blink.txt
```

## Wiring
Because we use ESP32-DevKitC-V4 and it just have 1 LED for power signal. So we need an external LED in this project.

Connect the (+) of LED to GPIO5. (-) of LED to a resistor ~220 Ohm connect to GND.

## Flash
Identify the port connect to chip. Here is /dev/ttyUSB0. You can identify it by using the statement `ls /dev/tty*` before and after plugging in your board, the thing appear is chip's port.
```bash
idf.py -p /dev/ttyUSB0 flash
```

Error: 
Port permission denied

Fix:
```bash
# Thêm user vào nhóm dialout (Ubuntu)
sudo usermod -a -G dialout $USER
# Sau đó logout/login lại
# Hoặc tạm thời:
sudo chmod a+rw /dev/ttyUSB0
```

I use WSL so I need `usbipd` to attach the USB port from the Windows to WSL.