#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp;
        dp[0] = 0; 

        for (int rod : rods) {
            unordered_map<int, int> curr(dp);

            for (const auto& [diff, height] : curr) {
                dp[diff + rod] = max(dp[diff + rod], height);

                int new_diff = abs(diff - rod);
                dp[new_diff] = max(dp[new_diff], height + min(diff, rod));
            }
        }

        return dp[0];
    }
};

int main() {
    Solution solution;

    vector<int> rods1 = { 1, 2, 3, 6 };
    cout << "Max height for rods {1, 2, 3, 6}: " << solution.tallestBillboard(rods1) << endl;

    vector<int> rods2 = { 1, 2, 3, 4, 5, 6 };
    cout << "Max height for rods {1, 2, 3, 4, 5, 6}: " << solution.tallestBillboard(rods2) << endl;

    vector<int> rods3 = { 1, 2 };
    cout << "Max height for rods {1, 2}: " << solution.tallestBillboard(rods3) << endl;

    vector<int> rods4 = { 2, 3, 5, 1, 5, 3, 5, 100, 403, 3204, 234, 23, 4, 5, 1, 4, 2801 };
    cout << "Max height for rods {2, 3, 5, 1, 5, 3, 5, 100, 403, 3204, 234, 23, 4, 5, 1, 4, 2801}: " << solution.tallestBillboard(rods4) << endl;

    return 0;
}