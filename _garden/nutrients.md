---
layout: home
title:  "Nutrients"
date:   2020-09-02
categories: hydroponic nutrients 
regenerate: true
---
 

# Deficiencies 
Common symptoms and possible deficiencies to consider.
<table id="myTable" class="hoverTable">
  <thead>
    <tr>
      <th>nutrient</th>
      <th>symptom</th>
    </tr>
  </thead>
  <tbody> 
{% for itm in site.data.plantNutrientDeficiency %}
  <tr>
    <td>{{ itm.nutrient }} </td>
    <td>{{ itm.symptom }} </td>
  </tr>
{% endfor %}
</tbody>
</table>

Table sources from
- https://ext.vt.edu/content/pubs_ext_vt_edu/en/426/426-084/426-084.html
- https://www.pubs.ext.vt.edu/content/dam/pubs_ext_vt_edu/426/426-323/SPES-295.pdf
- https://extension.umn.edu/how/small-scale-hydroponics#fertilizing-2645213


