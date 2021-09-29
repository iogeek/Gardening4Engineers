---

layout: home
---

<style style="text/css">
  table {
    border-left: 0;
    border-right: 0;
    border-top: 0;
    border-bottom: 0;
  }

  table tr td {
    border-left: 0;
    border-right: 0;
    border-top: 0;
    border-bottom: 0;
  }

  table th {
    border-left: 0;
    border-right: 0;
    border-top: 0;
    border-bottom:1pt solid black;
  }
  
  .panel-note {
  -moz-border-radius: 6px;
  -webkit-border-radius: 6px;
  background-color: #f0f7fb;
  background-position: 5px 15px;
  background-repeat: no-repeat;
  border: solid 1px #3498db;
  border-radius: 6px;
  overflow: hidden;
  padding: 13px 20px 15px 65px;
  min-height: 80px;
}

.panel-note.top-padding {
  padding-top: 25px;
}
</style>

A crude collection of tidbits i have picked up.
<table>
<tr>
<th> Projects </th>
<th> Garden </th>
<th> Recipes </th>
</tr>
<tr>
  <td width="10%">
  <div class="panel-note" markdown="1">
  Projects
  Garden
  Recipes
  </div>

</td>
<td width="30%">
{% for mdoc in site.projects %}
  <div class="mydocs" markdown="1">
  <a href="{{ mdoc.url | relative_url }}">{{ mdoc.title }}</a>
  </div>
{% endfor %}
</td>
<td>
{% for mposts in site.garden %}
  <div class="myposts" markdown="1">
  <a href="{{ mposts.url | relative_url }}">{{ mposts.title }}</a>
  </div>
{% endfor %}
</td>
</tr>
</table>
