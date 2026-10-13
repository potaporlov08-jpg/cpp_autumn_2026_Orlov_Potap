#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

const int cA = 6;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<double> massiv(n);
  vector<double> logorifmy(n);
  vector<double> sum_log(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> massiv[i];
    logorifmy[i] = log(massiv[i]);
  }
  double k;
  k = 0;
  sum_log[0] = 0;
  for (int i = 0; i < n; ++i) {
    k += logorifmy[i];
    sum_log[i + 1] = k;
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int l;
    int r;
    cin >> l >> r;
    double ans = exp((sum_log[r + 1] - sum_log[l]) / (r - l + 1));
    cout << fixed << setprecision(cA) << ans << "\n";
  }
  return 0;
}