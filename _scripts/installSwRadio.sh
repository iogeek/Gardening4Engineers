#! /bin/bash

sudo apt -y install libtool libusb-dev librtlsdr-dev rtl-sdr build-essential autoconf cmake pkg-config

mkdir -p $HOME/git
cd $HOME/git
git clone https://github.com/merbanan/rtl_433.git
cd rtl_433/ && mkdir build && cd build && cmake ../ && make
sudo make install