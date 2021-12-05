---
layout: home
title:  "Debugging Pi"
date:   2021-04-13
categories: pi Raspian linux debugging scron
regenerate: true
---
# Cron 
Scripts run by cron (crontab) do not inherit environment variables.

## Filtering Cron jobs from syslog
grep -i CRON /var/log/syslog

## Common error
Nov 29 06:00:01 farmpi CRON[17531]: (pi) CMD (/home/pi/getSensorData.sh)
Nov 29 06:00:01 farmpi CRON[17530]: (CRON) info (No MTA installed, discarding output)

In this instance there is no message interface so no errors were logged.
option 1 - install postfix
    sudo apt-get install postfix
    If you select local installation, the output from your cron jobs will be relayed to a local "mailbox" that you can easily tail:
    sudo tail -f /var/mail/<cron user>
option 2 - Add email to crontab
    MAILTO=""
    MAILTO="mymail.com"
   **NOTE:**  Never attempted mail.  This is tbd notes for later.

## Reloading cron
/etc/init.d/cron reload
sudo service cron restart 

env -i /home/pi/<yourScriptName>

bsh for cron
SHELL=/bin/bash

list cron
crontab -l

/etc/cron.allow
/etc/cron.deny

basics
- needs to be executable (chmod +x)
- will not have environment variables (test w/ env -i)
- every 5 minutes
    */5 * * * * /home/pi/getSensorData.sh

# Services
