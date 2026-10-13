#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  vector<long long> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    long long x;
    cin >> x;
    int l = 0;
    int r = n - 1;
    if (a[l] + x >= b[l]) {
      cout << l + 1 << "\n";
    } else {
      while (r - l > 1) {
        int m;
        m = (l + r) / 2;
        if (a[m] + x >= b[m]) {
          r = m;
        } else {
          l = m;
        }
      }
      long long ans1 = max(a[l] + x, b[l]);
      long long ans2 = max(a[r] + x, b[r]);
      if (ans1 < ans2) {
        cout << l + 1 << "\n";
      } else {
        cout << r + 1 << "\n";
      }
    }
  }
  return 0;
}