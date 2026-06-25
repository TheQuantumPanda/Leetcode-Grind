import json
import urllib.parse
import subprocess

with open("stats.json", "r") as f:
    stats = json.load(f)

easy = stats["easy"]
medium = stats["medium"]
hard = stats["hard"]
total = stats["total"]

streak = stats["streak"]
max_streak = stats["max_streak"]

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

def get_last_problems(n=20):
    result = subprocess.check_output(
        ["git", "log", "-n", str(n), "--pretty=format:%s"]
    ).decode("utf-8")
    commits = result.split("\n")
    problems = []
    for c in commits:
        if "Question-" not in c:
            continue
        if "update stat.json" in c.lower():
            continue
        parts = c.split("Question-")
        if len(parts) > 1:
            after = parts[1]
            name = " ".join(after.split(" ")[1:]).strip()
            if name:
                problems.append(name)
    return problems[:5]

recent_problems = get_last_problems()
recent_block = "\n".join([f"- {p}" for p in recent_problems])

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

<div align="center">
<table>
<tr>

<td width="50%" align="center" valign="top">

### 📈 Solved Distribution

<img width="300" src="{chart_url}" />

</td>

<td width="50%" align="center" valign="top">

### 📊 LeetCode Coverage

**🟢 Easy — {easy}/{easy_total} ({easy_pct}%)**  

**🟡 Medium — {medium}/{medium_total} ({medium_pct}%)**  

**🔴 Hard — {hard}/{hard_total} ({hard_pct}%)**

</td>

</tr>
</table>
</div>

## 🔥 Streak Stats

**Current Streak:** 🔥 {streak} days  
**Max Streak:** 🏆 {max_streak} days  

## 🕒 Last 5 Problems

{recent}
"""

readme = template.format(
    total=total,
    easy=easy,
    medium=medium,
    hard=hard,
    streak=streak,
    max_streak=max_streak,
    chart_url=chart_url,

    easy_total=leetcode_totals["easy"],
    medium_total=leetcode_totals["medium"],
    hard_total=leetcode_totals["hard"],

    easy_pct=progress["easy"],
    medium_pct=progress["medium"],
    hard_pct=progress["hard"],

    recent=recent_block
)

with open("README.md", "w") as f:
    f.write(readme)

print("README updated successfully")
