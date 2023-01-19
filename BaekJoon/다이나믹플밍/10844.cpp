#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS
#define MOD 1000000000
#define lli long long int
using namespace std;
int N;
lli sum = 0;
lli dp[101][11];

int main(void){
    scanf("%d", &N);
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    dp[1][4] = 1;
    dp[1][5] = 1;
    dp[1][6] = 1;
    dp[1][7] = 1;
    dp[1][8] = 1;
    dp[1][9] = 1;
    dp[1][10] = 1;
    dp[1][11] = 0;

    for(int i=2; i<=N; i++){
        for(int j=1; j<=10; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%MOD;
        }
    }
    for(int j=2; j<=10; j++){
        sum += dp[N][j]% MOD;
    }

    printf("%lld", sum % MOD);
}