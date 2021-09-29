---

layout: home
---
Home Page

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
</style>

A crude collection of tidbits i have picked up.
<table>
<tr>
<th> Projects </th>
<th> Garden </th>
</tr>
<tr>
<td width="30%">
{% for mdoc in site.mydocs %}
  <div class="mydocs" markdown="1">
  <a href="{{ mdoc.url | relative_url }}">{{ mdoc.title }}</a>
  </div>
{% endfor %}
</td>
<td>
{% for mposts in site.myposts %}
  <div class="myposts" markdown="1">
  <a href="{{ mposts.url | relative_url }}">{{ mposts.title }}</a>
  </div>
{% endfor %}
</td>
</tr>
</table>
