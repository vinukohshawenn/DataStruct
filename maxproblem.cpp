#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void solve() {
    int test;
    cin >> test;

    while (test--) {
        int n;
        cin >> n;

        vector<int> s(n);
        int max1 = INT_MIN, max2 = INT_MIN;

        for (int i = 0; i < n; i++) {
            cin >> s[i];
            if (s[i] > max1) {
                max2 = max1;
                max1 = s[i];
            } else if (s[i] > max2) {
                max2 = s[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (n == 1) {
                cout << "0";  // If only one participant, difference is 0
            } else if (s[i] == max1) {
                cout << s[i] - max2;
            } else {
                cout << s[i] - max1;
            }

            if (i != n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
