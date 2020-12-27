---
layout: page
title:  "Add ePaper display to Pi"
date:   2020-12-20
categories: pi Raspian ePaper dotnet
regenerate: true
---
 
## Enabling Waveshare epaper
Purchased a [2.7 inch WaveShare ePaper hat](https://www.waveshare.com/wiki/2.7inch_e-Paper_HAT) to display output from projects.
The setup is well documentation on the waveshare site.  The waveshare site contains a working sample.  I've opted to tweak the sample versus develop something new via super interesting iot extentions to [dotnet](https://docs.microsoft.com/en-us/dotnet/iot/intro).

 Here are the tweaks I made to the waveshare sample.

- Installed latest [BCM2835](http://www.airspayce.com/mikem/bcm2835/) driver (vs version described on WaveShare)
- Removed uneeded files from [Waveshare sample](https://github.com/waveshare/e-Paper).  Ex python, arduino, etc
- Trimmed makefile and added capability to build shared libary
- Added fonts (see tips on FontEdit below) 


## Getting your own fonts
[FontEdit](https://github.com/ayoy/fontedit/) made getting fonts as simple as cut and paste.
- Be sure the "reverse bits (MSB)" is checked.
![FontEdit Output Settingspvc cross]({{ site.imagePath | relative_url }}/piSetup/fontEditOutput.png){:height="289px" width="165px"}
- See font48.c and font36.c for fonts I used FontEdit to create.  Take a look at fonts.h for how the new font datastructures were added.


## Adding the "Custom" Library
The code I made creates a custom library from the Waveshare sample.  This libary needs to be built, copied to a known location, and add the location to the search path.

- Make clean && makefile libary
- Copy libepd.so to /home/pi/libs
- add path to sudo vi /etc/ld.so.conf
- sudo ldconfig to reload paths
- dotnet run test

## 