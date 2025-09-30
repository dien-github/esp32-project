<!-- TODO: Add CI badge here after workflow created -->

# MY PROJECT
ESP32 PROJECT

## YÊU CẦU
- ESP-IDF v5.5.1
- Python3, cmake, ninja

## Setup (Linux/WSL)
```bash
git clone https://github.com/dien-github/esp32-project.git
cd esp32-project
# Cài esp-idf (nếu chưa)
cd esp-idf && ./install.sh && . ./export.sh
```

# build + flash
```bash
idf.py set-target esp32
idf.py buill
idf.py -p /dev/ttyUSB0 flash
idf.py -p /dev/ttyUSB0 monitor 2>&1 | tee logs/serial_logs_day2.txt
```