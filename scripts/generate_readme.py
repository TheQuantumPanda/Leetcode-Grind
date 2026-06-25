import json
import urllib.parse

with open("stats.json", "r") as f:
    stats = json.load(f)

easy = stats["easy"]
medium = stats["medium"]
hard = stats["hard"]
total = stats["total"]

leetcode_totals = {
    "easy": 951,
    "medium": 2074,
    "hard": 948
}

progress = {
    "easy": round((easy / leetcode_totals["easy"]) * 100, 2),
    "medium": round((medium / leetcode_totals["medium"]) * 100, 2),
    "hard": round((hard / leetcode_totals["hard"]) * 100, 2),
}

chart = {
    "type": "pie",
    "data": {
        "labels": ["Easy", "Medium", "Hard"],
        "datasets": [{
            "data": [easy, medium, hard],
            "backgroundColor": ["#2ecc71", "#f1c40f", "#e74c3c"]
        }]
    }
}

chart_url = "https://quickchart.io/chart?c=" + urllib.parse.quote(json.dumps(chart))

template = """
<h1 align="center">🚀 LeetCode Dashboard</h1>

<p align="center">
  Daily progress in Data Structures & Algorithms.
</p>

<p align="center">
  <b>{total} Problems Solved</b>
</p>

## 📊 Dashboard

<div align="center">

<table>
<tr>
<td align="center">
<h3>🎯 Total</h3>
<b>{total}</b>
</td>

<td align="center">
<h3>🟢 Easy</h3>
<b>{easy}</b>
</td>

<td align="center">
<h3>🟡 Medium</h3>
<b>{medium}</b>
</td>

<td align="center">
<h3>🔴 Hard</h3>
<b>{hard}</b>
</td>
</tr>
</table>

</div>

## 📈 Analytics

<table>
<tr>

<td width="50%" align="center" valign="top">

### 📈 Solved Distribution

<img width="300" src="{chart_url}" />

</td>

<td width="50%" align="left" valign="top">

### 📊 LeetCode Coverage

**🟢 Easy — {easy}/{easy_total} ({easy_pct}%)**  

**🟡 Medium — {medium}/{medium_total} ({medium_pct}%)**  

**🔴 Hard — {hard}/{hard_total} ({hard_pct}%)**  

</td>

</tr>
</table>
"""

readme = template.format(
    total=total,
    easy=easy,
    medium=medium,
    hard=hard,
    chart_url=chart_url,

    easy_total=leetcode_totals["easy"],
    medium_total=leetcode_totals["medium"],
    hard_total=leetcode_totals["hard"],

    easy_pct=progress["easy"],
    medium_pct=progress["medium"],
    hard_pct=progress["hard"]
)
with open("README.md", "w") as f:
    f.write(readme)

print("README updated successfully")
