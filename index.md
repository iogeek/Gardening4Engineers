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
{% assign sortedCollection = site.collections | sort: 'sequence' %}
<table>
  <tr>
    <td width="10%">
  <div class="panel-note">
    {% for itm in sortedCollection %}
    {% if itm.title and itm.title != "" %}
    <div class="navitm" id="{{ itm.title }}_nav">
    {{ itm.title }}
    </div>
    {% endif %}
    {% endfor %}
    </div>
    </td>
    <td>
      {% for itm in sortedCollection %}
      {% if itm.title and itm.title != "" %}
      <div class="mainPage" id="{{ itm.title }}" style="display:none">
        {{ itm.title }}
        {% if itm.message and itm.message != "" %}
          <br>
          {{ itm.message }}
        {% else %}
          {% for gdoc in site[itm.label] %}
          <br>
          <a href="{{ gdoc.url | relative_url }}">{{ gdoc.title }}</a>
          {% endfor %}
        {% endif %}
      </div>
      {% endif %}
      {% endfor %}
    </td>
  </tr>
</table>
<!--
{% for item in site[collection.label] %}
  <li><a href="{{ item.url }}">{{ item.title }}</a></li>
{% endfor %}
-->

<script>
  var gVisible = "none";

  function ToggleDiv(id) {
    if (gVisible !== "none")
      document.getElementById(gVisible).style.display = "none";
    document.getElementById(id).style.display = "inline";
    gVisible = id;    
  }
  {% for itm in sortedCollection %}
  {% if itm.title and itm.title != "" %}
    document.getElementById("{{ itm.title }}_nav").onclick = function() {
      ToggleDiv("{{ itm.title }}");
    }
  {% endif %}
  {% endfor %}

  {% assign homePage = site.collections 
      | where_exp:"firstCollectionPage", "firstCollectionPage.sequence == 1" 
      | first %}
  ToggleDiv("{{ homePage.title }}");
</script>
