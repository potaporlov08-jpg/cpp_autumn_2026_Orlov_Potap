#include <iostream>
#include <vector>

const int cMOD = 10000000 + 4321;
const int cI1 = 123;
const int cI2 = 45;
void ISort(std::vector<int>& a, int l, int r) {
  for (int i = l + 1; i <= r; ++i) {
    int v = a[i];
    int j = i - 1;
    while (j >= l && a[j] > v) {
      a[j + 1] = a[j];
      j -= 1;
    }
    a[j + 1] = v;
  }
}
void Part3Mas(std::vector<int>& a, int l, int r, int piv, int& le, int& rs) {
  int i = l;
  int j = l;
  int k = r;
  while (j <= k) {
    if (a[j] < piv) {
      std::swap(a[i], a[j]);
      i += 1;
      j += 1;
    } else if (a[j] > piv) {
      std::swap(a[j], a[k]);
      k -= 1;
    } else {
      j += 1;
    }
  }
  le = i - 1;
  rs = k + 1;
}
int QuickSelect(std::vector<int>& a, std::vector<int>& med, int l, int r,
                int k) {
  while (l <= r) {
    int n = r - l + 1;
    if (n <= 5) {
      ISort(a, l, r);
      return a[l + k - 1];
    }
    int ng = (n + 4) / 5;
    int mc = 0;
    for (int i = 0; i < ng; ++i) {
      int gl = l + i * 5;
      int gr = gl + 4;
      if (gr > r) {
        gr = r;
      }
      int gs = gr - gl + 1;
      ISort(a, gl, gr);
      med[mc] = a[gl + gs / 2];
      mc += 1;
    }
    int piv = QuickSelect(med, med, 0, mc - 1, (mc + 1) / 2);
    int le = 0;
    int rs = 0;
    Part3Mas(a, l, r, piv, le, rs);
    int ls = le - l + 1;
    int ms = rs - le - 1;
    if (k <= ls) {
      r = le;
    } else if (k <= ls + ms) {
      return piv;
    } else {
      k -= (ls + ms);
      l = rs;
    }
  }
  return a[l];
}
int main() {
  int n = 0;
  int k = 0;
  long long a0 = 0;
  long long a1 = 0;
  if (!(std::cin >> n >> k >> a0 >> a1)) {
    return 0;
  }
  std::vector<int> a(n);
  if (n > 0) {
    a[0] = a0;
  }
  if (n > 1) {
    a[1] = a1;
  }
  for (int i = 2; i < n; ++i) {
    a[i] = (a[i - 1] * cI1 + a[i - 2] * cI2) % cMOD;
  }
  std::vector<int> med(n / 5 + 1);
  std::cout << QuickSelect(a, med, 0, n - 1, k) << "\n";
  return 0;
}