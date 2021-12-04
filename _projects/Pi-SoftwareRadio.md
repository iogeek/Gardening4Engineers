---
layout: home
title:  "Wireless 433mhz sensors"
date:   2020-12-20
categories: pi Raspian SDR 433mhz
regenerate: true
---
# Capturing Data From Outdoor Sensors
I use outdoor wireless sensors to capture temperature, wind, and light intensity.  This projects uses the following...
- Raspberry pi for capturing and storing the sensor data.
- [rtl_433](https://github.com/merbanan/rtl_433/) - libary that reads and parses the wireless signals
- USB attached radio and antenna

 Adafruit has a great [tutorial](https://www.adafruit.com/product/1497) on signal capture and the hardware needed.  The radio I used is from [nooelec](https://www.nooelec.com/). 

## Building rtl-433 libaries
The following commands will setup and install the rtl-433 libaries on a pi.
<p class="codeBlock">sudo apt -y install git libtool libusb-dev librtlsdr-dev rtl-sdr build-essential autoconf cmake pkg-config
mkdir -p $HOME/git
cd $HOME/git
if [[ ! -d "$HOME/git/rtl_433" ]]; then git clone https://github.com/merbanan/rtl_433.git; fi
cd rtl_433 && git pull
if [[ ! -d "$HOME/git/rtl_433/build" ]]; then mkdir build; fi
if [[ -d "$HOME/git/rtl_433" ]]; then cd build && cmake ../ && make; fi
if [[ -d "$HOME/git/rtl_433" ]]; then sudo make install; fi</p>

Once the rtl_433 libaries are built and installed, typing 'rtl_433 -D' from a cmd shell  will start capture until ctrl-c.

## Automating capture

<p class="codeBlock">echo '#!/bin/bash' >  $HOME/getSensorData.sh
which rtl_433 | xargs -I {} echo 'APP='{} >>  $HOME/getSensorData.sh
echo '$APP -T 90 -F "mqtt://farmpi:1883"' >>  $HOME/getSensorData.sh
chmod +x $HOME/getSensorData.sh
(crontab -l; echo '0 * * * * /home/pi/getSensorData.sh';) | crontab</p>

Retart cron by **sudo /etc/init.d/crond restart status**
Edit crontab by **crontab -e**

## Links I found useful
https://github.com/merbanan/rtl_433/
https://www.adafruit.com/product/1497
https://triq.org/rtl_433
https://www.nooelec.com/
https://www.rtl-sdr.com/
https://raspberrypiandstuff.wordpress.com/2017/08/04/rtl_433-on-a-raspberry-pi-made-bulletproof/
