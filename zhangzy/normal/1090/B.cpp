#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<string> text;

const string str_begin = "\\begin{thebibliography}{99}",
  str_end = "\\end{thebibliography}",
  str_cite = "\\cite";

int main(void) {
  while (true) {
    string line;
    getline(cin, line);
    if (line == str_begin) break;
    text.push_back(line);
  }

  vector<string> order;
  for (auto &s : text) {
    for (int i = 0; i + 4 < s.length(); ++i) {
      if (s.substr(i, 5) == str_cite) {
        int l = s.find('{', i);
        int r = s.find('}', i);
        order.push_back(s.substr(l + 1, r - l - 1));
      }
    }
  }
  vector< pair<string, string> > item;
  map<string, string> item_map;
  while (true) {
    string line;
    getline(cin, line);
    if (line == str_end) break;
    int l = line.find('{');
    int r = line.find('}');
    item.push_back({line.substr(l + 1, r - l - 1), line});
  }
  bool correct = true;
  for (int i = 0; i < order.size(); ++i) {
    item_map[item[i].first] = item[i].second;
    if (order[i] != item[i].first) correct = false;
  }
  puts(correct ? "Correct" : "Incorrect");
  if (correct) return 0;
  puts(str_begin.c_str());
  for (int i = 0; i < order.size(); ++i) {
    puts(item_map[order[i]].c_str());
  }
  puts(str_end.c_str());

  return 0;
}