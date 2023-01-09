#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
#define lli long long int

int N;
lli dp[91][2] = {0,};

int main(void){
    scanf("%d", &N);
    dp[1][0] = 0;
    dp[1][1] = 1;
    for(int i=2; i<=N; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    printf("%lld", dp[N][0] + dp[N][1]);
}