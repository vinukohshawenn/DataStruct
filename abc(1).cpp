#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<vector<string>> players(3, vector<string>(n));
    map<string, int> word_counts;

    // Read words and count their occurrences
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> players[i][j];
        word_counts[players[i][j]]++;
      }
    }

    vector<int> player_points(3, 0);

    // Calculate points for each player
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < n; ++j) {
        int count = word_counts[players[i][j]];
        if (count == 1) {
          player_points[i] += 3;
        } else if (count == 2) {
          player_points[i] += 1;
        }
        // If count is 3, player_points[i] += 0, which doesn't change anything
      }
    }

    // Output the points
    for (int i = 0; i < 3; ++i) {
      cout << player_points[i] << (i == 2 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}