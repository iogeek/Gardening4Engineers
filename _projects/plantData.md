---
layout: page
title:  "Plant Information"
date:   2020-09-01
categories: planning info
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

<input type="text" id="myInput" onkeyup="myTableFilter()" placeholder="Search for..">
<table id="myTable" class="hoverTable">
  <thead>
    <tr>
      <th>type</th>
      <th>commonName</th>
      <th>style</th>
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
    <td>{{ itm.type }} </td>
    <td>{{ itm.commonName }} </td>
    <td>{{ itm.style }} </td>
    <td>{{ itm.indoorSow }} </td>
    <td>{{ itm.hardenTime }} </td>
    <td>{{ itm.outdoorSow }} </td>
    <td>{{ itm.perSquare }} </td>
    <td>{{ itm.spacing }} </td>
    <td>{{ itm.spacingNotes }} </td>
    <td>{{ itm.exposure }} </td>
    <td>{{ itm.soilPH }} </td>
    <td>{{ itm.soilTemp }} </td>
    <td>{{ itm.soilType }} </td>
    <td>{{ itm.maturity }} </td>
    <td>{{ itm.harvestNotes }} </td>
    <td>{{ itm.notes }} </td>
  </tr>
{% endfor %}
</tbody>
</table>





