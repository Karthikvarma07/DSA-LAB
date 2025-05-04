#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> strengths(n);
        for (int i = 0; i < n; i++) {
            cin >> strengths[i];
        }

        // Create a sorted copy to find max and second max
        vector<int> sortedStrengths = strengths;
        sort(sortedStrengths.begin(), sortedStrengths.end());

        int max1 = sortedStrengths[n-1];
        int max2 = sortedStrengths[n-2];

        for (int i = 0; i < n; i++) {
            if (strengths[i] == max1) {
                cout << strengths[i] - max2 << " ";
            } else {
                cout << strengths[i] - max1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
