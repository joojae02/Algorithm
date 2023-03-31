#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input[1001][3] ={0,};
int N;
int dp[1001][3] = {0,};

int main(void)
{
    cin >> N;
    for (int i=1; i<= N;i++)
    {
        cin >> input[i][0] >>  input[i][1] >>  input[i][2];
        dp[i][0] = min(dp[i - 1][1],dp[i - 1][2]) + input[i][0];
        dp[i][1] = min(dp[i - 1][0],dp[i - 1][2]) + input[i][1];
        dp[i][2] = min(dp[i - 1][0],dp[i - 1][1]) + input[i][2];
    }

    cout << min(min(dp[N][0],dp[N][1]),dp[N][2]);
}