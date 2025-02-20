---
layout: home
title:  "Plant Data"
date:   2020-09-01
categories: plant data
---
 
<style style="text/css">
  .hoverTable{
		width:80%; 
    position: relative;
    font-size:12pt; 
    border-collapse:collapse; 
	}
  .hoverTable thead {
		width:80%; 
    position: sticky;
  }
 .hoverTable tbody {
		width:80%; 
    overflow: scroll;
  }
	.hoverTable td{ 
		padding:7px; border:#4e95f4 1px solid;
	}
	/* Define the default color for all the table rows */
	.hoverTable tr{
		background: #b8d1f3;
	}
	/* Define the hover highlight color for the table row */
  .hoverTable tr:hover {
    background-color: #ffff99;
  }
</style>
<script>
  function myTableFilter() {
    // Declare variables
    var input, filter, table, tr, td, i, txtValue;
    input = document.getElementById("myInput");
    filter = input.value.toUpperCase();
    table = document.getElementById("myTable");
    tr = table.getElementsByTagName("tr");

    // Loop through all table rows, and hide those who don't match the search query
    for (i = 0; i < tr.length; i++) {
      td = tr[i].getElementsByTagName("td")[0];
      if (td) {
        txtValue = td.textContent || td.innerText;
        if (txtValue.toUpperCase().indexOf(filter) > -1) {
          tr[i].style.display = "";
        } else {
          tr[i].style.display = "none";
        }
      }
    }
  }
</script>
Plant data used in spreadsheets for planning.<br>
<input type="text" id="myInput" onkeyup="myTableFilter()" placeholder="Search for..">
<table id="myTable" class="hoverTable">
  <thead>
    <tr>
      <th>commonType</th>
      <th>commonName</th>
      <th>genus</th>
      <th>species</th>
      <th>indoorSow</th>
      <th>hardenTime</th>
      <th>outdoorSow</th>
      <th>perSquare</th>
      <th>spacing</th>
      <th>spacingNotes</th>
      <th>exposure</th>
      <th>soilPH</th>
      <th>soilTemp</th>
      <th>soilType</th>
      <th>maturity</th>
      <th>harvestNotes</th>
      <th>notes</th>
    </tr>
  </thead>
  <tbody> 
{% for itm in site.data.plantData %}
  <tr>
    <td>{{ itm.CommonType }} </td>
    <td>{{ itm.CommonName }} </td>
    <td>{{ itm.Genus }} </td>
    <td>{{ itm.Species }} </td>
    <td>{{ itm.IndoorSow }} </td>
    <td>{{ itm.HardenTime }} </td>
    <td>{{ itm.OutdoorSow }} </td>
    <td>{{ itm.PerSquare }} </td>
    <td>{{ itm.Spacing }} </td>
    <td>{{ itm.SpacingNotes }} </td>
    <td>{{ itm.Exposure }} </td>
    <td>{{ itm.SoilPH }} </td>
    <td>{{ itm.SoilTemp }} </td>
    <td>{{ itm.SoilType }} </td>
    <td>{{ itm.Maturity }} </td>
    <td>{{ itm.HarvestNotes }} </td>
    <td>{{ itm.Notes }} </td>
  </tr>
{% endfor %}
</tbody>
</table>

References
- Plant Temps
    - https://kenosha.extension.wisc.edu/files/2021/03/Soil-Temp-Planting-V2docx.pdf
    - https://extension.psu.edu/vegetable-planting-and-transplanting-guide
    - https://s3.wp.wsu.edu/uploads/sites/2073/2014/09/Home-Vegetable-Gardening-in-Washington.pdf






