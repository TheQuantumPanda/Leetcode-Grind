import json
import urllib.parse

with open("stats.json", "r") as f:
    stats = json.load(f)

easy = stats["easy"]
medium = stats["medium"]
hard = stats["hard"]
total = stats["total"]

chart = {
    "type": "pie",
    "data": {
        "labels": ["Easy", "Medium", "Hard"],
        "datasets": [{
            "data": [easy, medium, hard],
            "backgroundColor": ["#2ecc71", "#f1c40f", "#e74c3c"]
        }]
    },
    "options": {
        "plugins": {
            "legend": {
                "labels": {
                    "color": "#ffffff"
                }
            },
            "tooltip": {
                "titleColor": "#ffffff",
                "bodyColor": "#ffffff"
            },
            "color": "#ffffff"
        }
    }
}

chart_url = (
    "https://quickchart.io/chart?c=" +
    urllib.parse.quote(json.dumps(chart))
)

# README template
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

## 📈 Solved Distribution

<img width="300" src="{chart_url}" />
"""

readme = template.format(
    total=total,
    easy=easy,
    medium=medium,
    hard=hard,
    chart_url=chart_url
)

with open("README.md", "w") as f:
    f.write(readme)

print("README updated successfully")
