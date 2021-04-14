---
layout: page
title:  "Setting up the Raspberry Pi"
date:   2020-11-28
categories: pi Raspian setup
regenerate: true
---
 
There are plenty of great setup tutorials.  Here are the ones I use to setup the pi.

- [Enable Pi to boot from USB.](https://www.raspberrypi.org/documentation/hardware/raspberrypi/bootmodes/msd.md)
- Pick the OS you plan to use from [raspberrypi site.](https://www.raspberrypi.org/software/operating-systems/).  
  - If you prefer [headless](https://en.wikipedia.org/wiki/Headless_computer) for iot settings pick "Raspberry Pi OS Lite".
- Drop the OS on a flash drive.  Several options for Windows.  I started with [Etcher](https://www.balena.io/etcher/)  (src on [Github](https://github.com/balena-io/etcher)) but moved to [Raspberry Pi Imager](https://www.raspberrypi.org/software/) which works with both USB and SD media.  Another option is [WinFlashTool](https://sysprogs.com/winflashtool/download/).


# Headless tweaks
 Poached from [here](https://danidudas.medium.com/install-raspberry-os-configure-wi-fi-and-ssh-headless-without-a-keyboard-or-network-cable-3d4f9d383165)

 - Step 1: Enable ssh
from WSL
Assuming the drive letter is e:\
sudo mkdir -p /mnt/e && sudo mount -t drvfs e: /mnt/e

touch /mnt/e/ssh

- Step 2: Setup Wifi SSID and keys
in /mnt/e/wpa_supplicant.conf add the following

```
    country=US
    ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev 
    update_config=1
    network={
        ssid="YourNetworkSSID"
        psk="Your Network's Passphrase"
        key_mgmt=WPA-PSK
    }
```

Remove USB drive and boot Pi


The defaults will be"
system name -> raspberrypi
username -> pi
password -> raspberry

<br>
NOTE: Once you boot, be sure to change your password and lock down ssh access.


## Setting up dev environment and .Net for Pi
- sudo apt-get install git
- timedatectl list-timezones
sudo timedatectl set-timezone <your_time_zone>
America/Los_Angeles

sudo timedatectl set-timezone America/Los_Angeles
- [powershell](https://docs.microsoft.com/en-us/powershell/scripting/install/installing-powershell-core-on-linux)

```
wget $(curl -s https://api.github.com/repos/PowerShell/PowerShell/releases/latest | grep "browser_download_url.*linux-arm32.tar.gz" | cut -d '"' -f 4)
mkdir ~/powershell
tar -xvf ./powershell*.tar.gz -C ~/powershell
sudo ln -s ~/powershell/pwsh /usr/bin/pwsh
```

deprecated -> wget https://dist.nuget.org/win-x86-commandline/latest/nuget.exe
mono nuget.exe install

- [.net core](https://dotnet.microsoft.com/download/dotnet-core)
    - helpful scripts https://github.com/pjgpetecodes/
```
  wget -O - https://raw.githubusercontent.com/pjgpetecodes/dotnet5pi/master/install.sh | sudo bash
```


# Assembling the box
#


linux maintenence
        sudo apt update
        sudo apt full-upgrade

creating the autoststart script - https://www.raspberrypi.org/documentation/linux/usage/systemd.md
