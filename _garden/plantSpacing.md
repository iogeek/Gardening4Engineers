---
layout: home
title:  "Spacing"
date:   2022-02-12
categories: garden planning 
regenerate: true
sfgTemplate:
  - name: spacing3inch.png
    column: 1
    text: 3 inch spacing  = 16 per square
  - name: spacing3inchWTrellis.png
    column: 2
    text: 3 inch with trellis = 8 per square
  - name: spacing4inch.png
    column: 3
    text: 4 inch spacing = 9 per square
  - name: spacing6inch.png
    column: 4
    text: 6 inch = 4 per square
  - name: spacing12inch.png
    column: 5
    text: 12 inch spacing = 1 per square
  - name: spacing18inch.png
    column: 6
    text: 18 inch spacing
  - name: spacing24inch.png
    column: 7
    text: 24 inch spacing = 2 squares
  - name: spacing24inchWCage.png
    column: 8
    text: 24 inch pacing with cage = 4 squares
---

The following visualization loosely follows the techniques from "square foot gardening" books.  The premise is to think of your garden in 12 inch by 12 inch sqaures. 

This is just a guide and not a rule.
## Plant spacing diagram

<table>
{% for sfgItem in page.sfgTemplate %}
    <tr>
    <th width="15%">
    <img src="{{ site.imagePath | relative_url }}/sqFtGarden/{{ sfgItem.name }}">
    </th><th>{{ sfgItem.text }}</th>
    </tr>
{% endfor %}
</table>


## Additional information
- Square foot gardening website - https://squarefootgardening.org/
- Square foot gardening books are likely availble in both paper and digital formats from your local library.

