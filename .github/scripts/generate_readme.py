import os
import re

def clean_display_name(text):
  # To remove extensions and replace hypens/underscores with clean spaces
  name, _ = os.path.splitext(text)
  return name.replace('-', ' ').replace('_',' ')

def generate_table():
  target_categories = {
    "Introductory-Problems",
    "Dynamic-Programming",
    "Sorting-and-Searching",
    "Graph-Algorithms"
  }
  '''
  if not os.path.exists(target_dir):
    return "<!-- Error: CSES-Algorithms directory not found -->"
  '''
  rows = []
  for category_folder in os.listdir('.'):
    if category_folder in target_categories and os.path.isdir(category_folder):
      category_name = clean_display_name(category_folder)
      category_path = category_folder
      for file in os.listdir(category_path):
        if file.endswith('cpp'):
          rel_path = os.path.join(category_path, file)
          url_path = rel_path.replace(' ', '%20').replace('\\', '/')
          problem_name = clean_display_name(file)
          rows.append((category_name, problem_name, url_path))

  if not rows:
    return "| Category | Problem | Solution Link |\n| --- | --- | --- |\n| *No solutions detected yet* | | |"
  rows.sort(key=lambda x: (x[0], x[1]))
  md_content = "| Category | Problem | Solution Link |\n| --- | --- | --- |\n"
  for cat,name,path in rows:
    md_content += f"| **{cat}** | {name} | [View Code]({path}) |\n"
  return md_content

def update_readme():
  with open("README.md", "r", encoding="utf-8") as f:
    content = f.read()
  table_md = generate_table()
  pattern = r"<!-- cses-start -->.*?<!-- cses-end -->"
  replacement = f"<!-- cses-start -->\n\n{table_md}\n<!-- cses-end -->"
  updated_content = re.sub(pattern, replacement, content, flags=re.DOTALL)
  with open("README.md", "w", encoding="utf-8") as f:
    f.write(updated_content)

if __name__ == "__main__":
  update_readme()
