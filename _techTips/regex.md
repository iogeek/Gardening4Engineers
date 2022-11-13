---
layout: home
title:  "Regular Expressions"
date:   2021-12-29
categories: regex text 
regenerate: true
---
# Common Regex
All examples below assume you doing this in vim

## Find the first lowercase after " and make it uppercase
  :%s/"\l/\U&/g

  %s        : Do substitute command on the entire buffer
  /"        : Find quote
  \l        : followed by lowercase char
  \U&       : then make it capitalize
  /g        " global

