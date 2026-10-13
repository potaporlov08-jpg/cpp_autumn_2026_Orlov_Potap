#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  string t;
  cin >> t;
  int n = s.size();
  int posl = t.size();
  vector<long long> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  int l = 0;
  int r = n;
  while (r - l > 1) {
    int m = (r + l) / 2;
    int metka = 0;
    string x;
    x = s;
    for (int j = 0; j < m; ++j) {
      x[p[j] - 1] = ' ';
    }
    for (int j = 0; j < n; ++j) {
      if (x[j] == t[metka]) {
        metka = min(metka + 1, posl);
      }
    }
    if (metka == posl) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l;
  return 0;
}