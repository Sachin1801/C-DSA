#include <iostream>
#include <vector>
#include <stack>

#define MOD 1000000007

using namespace std;

class Solution {
private:
    vector<int> next_smaller_element(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> nse(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            nse[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return nse;
    }

    vector<int> find_PSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            pse[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return pse;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = next_smaller_element(arr);
        vector<int> pse = find_PSEE(arr);
        int total = 0;

        for (int i = 0; i < arr.size(); i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total + ((right * left * (long long)(1) * arr[i]) % MOD)) % MOD;
        }

        return total % MOD;
    }
};

int main() {
    Solution solution;

    // Example usage:
    vector<int> arr;
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int result = solution.sumSubarrayMins(arr);
    cout << "The sum of subarray minimums is: " << result << endl;

    return 0;
}
