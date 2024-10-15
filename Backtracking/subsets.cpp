// subsets.cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void subsets(string input, int i, string arr, vector<string> &ans)
{
    // base case
    if (input[i] == '\0')
    {
        for (int j = 0; arr[j] != '\0'; j++)
        {
            cout << arr[j] << ", ";
        }
        ans.push_back(arr);
        cout << endl;
        return;
    }

    // rec case
    subsets(input, i + 1, arr, ans);
    arr += input[i];
    subsets(input, i + 1, arr, ans);
    return;
}

bool compare(string a, string b)
{
    if(a.length()==b.length()){
        return a < b; 
    }
    return a.length() < b.length();
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string input;
    cin >> input;

    string arr;
    vector<string> ans;
    subsets(input, 0, arr, ans);
    cout << endl;

    // sort(ans.begin(),ans.end());
    sort(ans.begin(), ans.end(), compare);

    for (auto x : ans)
    {
        cout << x << ", ";
    }

    cout << endl;
    // subsets_1(input, 0, arr, ans);

    return 0;
}