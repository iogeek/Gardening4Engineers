---
layout: page
title:  "Testing cron for the impatient"
date:   2021-04-13
categories: pi Raspian linux cron
regenerate: true
---
 
Running scripts under cron (crontab to be exact) is tricky.

env -i /home/pi/<yourScriptName>

basics
- needs to be executable (chmod +x)
- will not have environment variables (test w/ env -i)