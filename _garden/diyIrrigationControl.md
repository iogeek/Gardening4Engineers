---
layout: home
title:  "Sprinkler Control"
date:   2020-09-02
categories: irrigation arduino
regenerate: true
---
This covers my v1 setup.  V2 is better...  way better.  Documentation to come.
 
This project controls watering through a microcontroller/relay in a waterproof box with a  soleniod to regulate water.

I could not find a waterproof box in the configuration I needed so I modified and existing waterproof box.

<br>

# Assembling the box
### Supplies
* 1/2" paddle bit ![paddle bit]({{ site.imagePath | relative_url }}/irrigationControl/paddleBit.jpg){:height="30px" width="126px"}
* Waterproof project box large enough for electronics.
* IP 67 Cable glands ![cable glands bit]({{ site.imagePath | relative_url }}/irrigationControl/cableGland2.jpg){:height="48px" width="48px"}
* solenoid ![water soleoid]({{ site.imagePath | relative_url }}/irrigationControl/soleoid.jpg){:height="50px" width="50px"}
* low voltage outdoor wire
* MCU and relay of your choice.  I used an 12v ESP8266 with built in relay. ![esp Relay]({{ site.imagePath | relative_url }}/irrigationControl/espRelay.jpg){:height="50px" width="50px"}
* silicone caulk

<br>
### Assembling the box
* Drill holes into box
![drilled box]({{ site.imagePath | relative_url }}/irrigationControl/drilledHoleInBox.jpg){:height="120px" width="120px"}
* Pop one end of cable gland through drilled hole
* Thread wire through glands
![drilled box]({{ site.imagePath | relative_url }}/irrigationControl/wiresInBox.jpg){:height="120px" width="120px"}
* Tighten cable gland
* Use wires to assemble electronics
* Add silicone to all seals
* Close box and tighten

### Code for it all
coming :)

