---
layout: home
title:  "DIY Hydroponic Nutrient Mixes"
date:   2020-09-02
categories: hydroponic nutrients 
regenerate: true
---
 

Nutrient Deficiencies 

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

from https://ext.vt.edu/content/pubs_ext_vt_edu/en/426/426-084/426-084.html