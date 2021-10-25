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
<table>
  <tr>
    <td width="10%">
  <div class="panel-note">
    {% for itm in site.data.sidebar %}
    <div class="navitm" id="{{ itm.title }}_nav">
          {{ itm.title }}
    </div>
    {% endfor %}
    </div>
    </td>
    <td>
      --<br>
      {% for itm in site.data.sidebar %}
      <div class="mainPage" id="{{ itm.title }}" style="display:none">
        {{ itm.title }}
        {% if itm.location and itm.location != "" %}
        {% elsif itm.message and itm.message != "" %}
        {% else %}
        {% endif %}
      </div>
      {% endfor %}
      <br>--<br>
    </td>
  </tr>
</table>
--
xx
--
{% for gdoc in site.garden %}
  <div class="garden" markdown="1">
  <a href="{{ gdoc.url | relative_url }}">{{ gdoc.title }}</a>
  </div>
{% endfor %}
--
yy
--
{% for mposts in site.garden %}
  <div class="myposts" markdown="1">
  <a href="{{ mposts.url | relative_url }}">{{ mposts.title }}</a>
  </div>
{% endfor %}

<script>
  var gVisible = "none";

  function ToggleDiv(id) {
    if (gVisible !== "none")
      document.getElementById(gVisible).style.display = "none";
    document.getElementById(id).style.display = "inline";
    gVisible = id;    
  }
  {% for itm in site.data.sidebar %}
    document.getElementById("{{ itm.title }}_nav").onclick = function() {
      ToggleDiv("{{ itm.title }}");
    }
  {% endfor %}
  ToggleDiv("{{ site.data.sidebar[0].title }}");
</script>
