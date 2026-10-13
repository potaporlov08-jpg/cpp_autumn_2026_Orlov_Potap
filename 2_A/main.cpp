#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<pair<long long, long long>>& v,
           vector<pair<long long, long long>>& a, long long l, long long m,
           long long r) {
  for (int i = l; i <= r; ++i) {
    a[i] = v[i];
  }
  long long i = l;
  long long j = m + 1;
  long long x = l;
  while (i <= m && j <= r) {
    if (a[i] <= a[j]) {
      v[x] = a[i];
      i += 1;
    } else {
      v[x] = a[j];
      j += 1;
    }
    x += 1;
  }
  while (i <= m) {
    v[x] = a[i];
    i += 1;
    x += 1;
  }
  while (j <= r) {
    v[x] = a[j];
    j += 1;
    x += 1;
  }
}

void MergeSort(vector<pair<long long, long long>>& v,
               vector<pair<long long, long long>>& a, long long l,
               long long r) {
  if (l >= r) {
    return;
  }
  long long m = (l + r) / 2;
  MergeSort(v, a, l, m);
  MergeSort(v, a, m + 1, r);
  Merge(v, a, l, m, r);
}

int main() {
  int n;
  cin >> n;
  vector<pair<long long, long long>> v(n);
  vector<pair<long long, long long>> a(n);
  for (int i = 0; i < n; ++i) {
    long long l;
    long long r;
    cin >> l >> r;
    v[i].first = l;
    v[i].second = r;
  }
  MergeSort(v, a, 0, n - 1);
  vector<pair<long long, long long>> ans;
  long long l = v[0].first;
  long long r = v[0].second;
  for (int i = 1; i < n; ++i) {
    if (v[i].first <= r && r < v[i].second) {
      r = v[i].second;
    } else if (r >= v[i].second) {
      continue;
    } else {
      ans.push_back({l, r});
      l = v[i].first;
      r = v[i].second;
    }
  }
  ans.push_back({l, r});
  int u = ans.size();
  cout << u << "\n";
  for (int i = 0; i < u; ++i) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }
  return 0;
}