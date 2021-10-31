---
layout: home
---

{% assign homePage = site.collections 
    | where_exp:"firstCollectionPage", "firstCollectionPage.sequence == 1" 
    | first %}
{{ homePage.message }}
