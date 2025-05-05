#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  unordered_set<int> distinct;
  int distinct_count = 0;

  for (int i = n - 1; i >= 0; --i) {
    if (distinct.find(a[i]) == distinct.end()) {
      distinct.insert(a[i]);
      distinct_count++;
    } else {
      break;
    }
  }

  return n - distinct_count;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}