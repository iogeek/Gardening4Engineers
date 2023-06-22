---
layout: home
title:  "Bitlocker notice on boot"
date:   2021-12-29
categories: bitlocker windows 
regenerate: true
---
Are you still having problems with the bit locker screen popping up every time you booted.

I came across something similar and found a work around and curious if it will work for you.

Each of these commands will need to be entered from an “administrator prompt / terminal”.  You can get to this after you’ve gotten to the familiar windows screen  Use your keyboard and press the windows key and the letter ‘x’ simultaneously.  This should being up a menu where you can choose “terminal(admin)” or something very similar.

The first command to enter is 


manage-bde -unlock c: -RecoveryPassword Recovery-Code 


This will disable the Windows checking for oddities and asking for the recovery key validation.  This will command is instant.

The second command is


manage-bde -off c: 


This will disable bitlocker for your boot drive.   This will take about 30 minutes to complete and run in the background...  which means your free to do other things while it is completing.  There is not a great way to determine when it is done.  Just give it about 30 minutes and it should be more than plenty.


After all this, reboot...  that will be the real test if this worked.

