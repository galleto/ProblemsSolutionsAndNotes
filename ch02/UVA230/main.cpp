#include <bits/stdc++.h>
#include <string>
#include <utility>

using namespace std;

int main() {
  string s;
  // author, title
  set<pair<string, string>> shelve;
  // title, author
  map<string, string> info;

  while(getline(cin, s) && s != "END") {
    int indexUntilTitle = s.find("\"", 1);
    string title =  s.substr(0, indexUntilTitle+1);
    string author = s.substr(indexUntilTitle+5);
    info[title] = author;
    shelve.emplace(author, title);
  }

  set<pair<string, string>> desk;

  while(getline(cin, s) && s != "END") {
    if (s[0] == 'B') {
      int indexBeforeTitle = s.find("\"", 1);
      string title = s.substr(indexBeforeTitle);
      shelve.erase({info[title], title});
    } else if (s[0] == 'R') {
      int indexBeforeTitle = s.find("\"", 1);
      string title = s.substr(indexBeforeTitle);
      desk.emplace(info[title], title);
    } else {
      for(const auto& book : desk) {
        auto it = shelve.lower_bound(book);

        if (it == shelve.begin()) {
          cout << "Put " << book.second << " first\n";
        } else {
          it = prev(it);
          cout << "Put " << book.second << " after " << it->second << '\n';
        }

        shelve.insert(book);
      }
      desk.clear();
      cout << "END\n";
    }
  }

  return 0;
}
