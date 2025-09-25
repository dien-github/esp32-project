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