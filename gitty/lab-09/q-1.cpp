#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int k, q;
        cin >> k >> q; // Read k and q

        // Read the sequence a
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
        }

        // Read the queries n_i
        vector<int> queries(q);
        for (int i = 0; i < q; i++) {
            cin >> queries[i];
        }

        // Process each query
        for (int i = 0; i < q; i++) {
            int n = queries[i]; // Initial number of players for this query

            // Initialize a set with players 1 to n
            set<int> players;
            for (int j = 1; j <= n; j++) {
                players.insert(j);
            }

            // Simulate the game for each round
            for (int j = 0; j < k; j++) {
                int pos = a[j]; // The position to remove (a_j-th player)

                // If the position is greater than the number of remaining players, stop
                if (pos > players.size()) {
                    break;
                }

                // Find the pos-th player
                auto it = players.begin();
                advance(it, pos - 1); // Move iterator to the (pos-1)-th element (0-based index)

                // Remove the player
                players.erase(it);
            }

            // Output the number of remaining players (winners)
            cout << players.size();
            if (i < q - 1) cout << " "; // Print space between outputs, but not after the last one
        }
        cout << endl; // New line after each test case
    }

    return 0;
}