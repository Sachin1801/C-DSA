// n_queen.cpp
#include <iostream>
using namespace std;

void printboard(int arr[][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool canplace(int arr[][20], int n, int i, int j)
{
    // column
    for (int row = 0; row < i; row++)
    {
        if (arr[row][j] == 1)
            return false;
    }

    // diagonal left
    int row = i, col = j;
    while (row >= 0 and col >= 0)
    {
        if (arr[row--][col--] == 1)
            return false;
    }

    // diagonal right
    row = i, col = j;
    while (row >= 0 and col < n)
    {
        if (arr[row--][col++] == 1)
            return false;
    }

    return true;
}
int nqueen(int arr[][20], int i, int n)
{
    // base case
    if (i == n)
    {
        // printboard(arr, n);
        // cout << endl;
        return 1;
    }

    // rec case

    // try to place queen in every row
    int ans = 0;
    for (int j = 0; j < n; j++)
    {
        if (canplace(arr, n, i, j))
        {
            arr[i][j] = 1;
            ans += nqueen(arr, i + 1, n);
            arr[i][j] = 0;
        }
    }
    return ans;
}

int main()
{

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    int arr[20][20] = {0};
    
    int ans = nqueen(arr, 0, n);
    cout<<ans<<endl;

    return 0;
}