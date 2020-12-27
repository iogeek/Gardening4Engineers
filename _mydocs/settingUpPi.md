---
layout: page
title:  "Setting up the Raspberry Pi"
date:   2020-11-28
categories: pi Raspian setup
regenerate: true
---
 
There are plenty of great setup tutorials.  Here are the ones I use.

- [Enable Pi to boot from USB.](https://www.raspberrypi.org/documentation/hardware/raspberrypi/bootmodes/msd.md)
- Pick the OS you plan to use from [raspberrypi site.](https://www.raspberrypi.org/software/operating-systems/)
- Drop the OS on a flash drive.  [Etcher](https://www.balena.io/etcher/) works for me (also on [Github](https://github.com/balena-io/etcher)).  If on Windows, pick the portable version.  Other options are [WinFlashTool](https://sysprogs.com/winflashtool/download/) and [Raspberry Pi Imager](https://www.raspberrypi.org/software/) which works with both USB and SD media.

# Headless tweaks
https://danidudas.medium.com/install-raspberry-os-configure-wi-fi-and-ssh-headless-without-a-keyboard-or-network-cable-3d4f9d383165

from WSL
Assuming the drive letter is e:\
sudo mkdir -p /mnt/e && sudo mount -t drvfs e: /mnt/e

touch /mnt/e/ssh

in /mnt/e/wpa_supplicant.conf add the following

country=US
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev 
update_config=1
network={
    ssid="YourNetworkSSID"
    psk="Your Network's Passphrase"
    key_mgmt=WPA-PSK
}

Remove USB drive and boot Pi


The defaults will be"
system name -> raspberrypi
username -> pi
password -> raspberry

<br>
NOTE: Once you boot, be sure to change your password and lock down ssh access.


## Setting up dev environment and .Net for Pi
sudo apt-get install git mono-complete
install (powershell)[https://docs.microsoft.com/en-us/powershell/scripting/install/installing-powershell-core-on-linux]

wget https://dist.nuget.org/win-x86-commandline/latest/nuget.exe
mono nuget.exe install

download .net core from https://dotnet.microsoft.com/download/dotnet-core.
   - Pick the latest version then downoad Arm32 versions of SDK and runtime. 

sudo mkdir /opt/dotnet
sudo tar -xvf dotnet-sdk-*-linux-arm.tar.gz -C /opt/dotnet/
sudo tar -xvf aspnetcore-runtime-*-linux-arm.tar.gz -C /opt/dotnet/
sudo ln -s /opt/dotnet/dotnet /usr/local/bin
echo 'export DOTNET_ROOT=/opt/dotnet' >> /home/pi/.bashrc
dotnet --info

note:  This adds msbuild and dotnet

dotnet msbuild to complile
dotnet new console -o <dir>  to create a new project
dotnet run to build and run csproj


# Assembling the box
#
