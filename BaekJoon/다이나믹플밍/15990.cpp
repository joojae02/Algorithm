#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int T;
long long ans, dp[100001][4];

int main(void){
    scanf("%d", &T);

    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 0;

    dp[2][1] = 0;
    dp[2][2] = 1;
    dp[2][3] = 0;

    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    int N;
    for(int j=1; j<=T; j++)
    {
        scanf("%d", &N);
		for (int i = 4; i <= N; i++)
		{
			dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
			dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
			dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
		}

		ans = (dp[N][1] + dp[N][2] + dp[N][3]) % 1000000009;
        printf("%lld\n", ans);
    }
}