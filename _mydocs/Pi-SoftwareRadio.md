---
layout: page
title:  "Add SDR (Software Defined Radio)"
date:   2020-12-20
categories: pi Raspian SDR 433mhz
regenerate: true
---
 
## Enabling Waveshare epaper
https://www.nooelec.com/
https://www.rtl-sdr.com/
https://www.adafruit.com/product/1497
https://raspberrypiandstuff.wordpress.com/2017/08/04/rtl_433-on-a-raspberry-pi-made-bulletproof/
https://triq.org/rtl_433
https://github.com/merbanan/rtl_433/

## Building rtl-433
sudo apt-get install libtool libusb-dev librtlsdr-dev rtl-sdr build-essential autoconf cmake pkg-config
git clone https://github.com/merbanan/rtl_433.git
cd rtl_433/ && mkdir build && cd build && cmake ../ && make
sudo make install

build rtl_sdr
https://osmocom.org/projects/rtl-sdr/wiki/Rtl-sdr
git clone git://git.osmocom.org/rtl-sdr.git
cd rtl-sdr/ && mkdir build && cd build && cmake ../ -DINSTALL_UDEV_RULES=ON && make
sudo make install
sudo ldconfig
sudo usermod -a -G plugdev pi
reboot

rtl_433 -D

SUBSYSTEMS=="usb", ATTRS{idVendor}=="0ccd", ATTRS{idProduct}=="00d7", MODE:="0666"

Bus 001 Device 006: ID 0bda:2838 Realtek Semiconductor Corp. RTL2838 DVB-T
idvendor = 0bda
idProduct = 2828

SUBSYSTEMS=="usb", ATTRS{idVendor}=="0bda", ATTRS{idProduct}=="2838", MODE:="0666"

/etc/udev/rules.d/rtl-sdr.rules

sudo service udev restart