---
layout: page
title:  "Add SDR (Software Defined Radio)"
date:   2020-12-20
categories: pi Raspian SDR 433mhz
regenerate: true
---
 
## Web sites for info
https://www.nooelec.com/
https://www.rtl-sdr.com/
https://www.adafruit.com/product/1497
https://raspberrypiandstuff.wordpress.com/2017/08/04/rtl_433-on-a-raspberry-pi-made-bulletproof/
https://triq.org/rtl_433
https://github.com/merbanan/rtl_433/

## Building rtl-433
```
sudo apt-get install libtool libusb-dev librtlsdr-dev rtl-sdr build-essential autoconf cmake pkg-config

cd $HOME/git
git clone https://github.com/merbanan/rtl_433.git
cd rtl_433/ && mkdir build && cd build && cmake ../ && make
sudo make install
```
sudo reboot

rtl_433 -D

echo '#!/bin/bash' >>  $HOME/getWeatherSensorData.sh
echo 'rtl_433 -T 90 -F "mqtt://farmpi:1883"' >>  $HOME/getWeatherSensorData.sh
chmod +x $HOME/getWeatherSensorData.sh
(crontab -l; echo '0 * * * * $HOME/getWeatherSensorData.sh';) | crontab

#sudo /etc/init.d/crond resrtart status

Future usage
- rtl_fm to listen on other frequencies

