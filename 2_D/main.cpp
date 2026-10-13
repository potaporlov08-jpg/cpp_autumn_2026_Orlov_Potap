#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const uint64_t cBase = 10;

void SortPoRazradu(vector<uint64_t>& v, uint64_t razrad) {
  long long n = v.size();
  vector<uint64_t> res(n);
  vector<uint64_t> schet(cBase, 0);
  for (int i = 0; i < n; ++i) {
    uint64_t c = (v[i] / razrad) % cBase;
    schet[c] += 1;
  }
  for (uint64_t i = 1; i < cBase; i++) {
    schet[i] += schet[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    uint64_t c = (v[i] / razrad) % cBase;
    res[schet[c] - 1] = v[i];
    schet[c] -= 1;
  }
  for (int i = 0; i < n; i++) {
    v[i] = res[i];
  }
}

void SortLSD(vector<uint64_t>& v) {
  if (v.empty()) {
    return;
  }
  uint64_t maxel = v[0];
  for (size_t i = 1; i < v.size(); i++) {
    if (v[i] > maxel) {
      maxel = v[i];
    }
  }

  for (uint64_t razrad = 1; razrad <= maxel; razrad *= cBase) {
    SortPoRazradu(v, razrad);
    if (razrad > maxel / cBase) {
      break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n;
  cin >> n;
  vector<uint64_t> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  SortLSD(v);
  for (int i = 0; i < n; ++i) {
    cout << v[i] << (i + 1 < n ? " " : "\n");
  }

  return 0;
}