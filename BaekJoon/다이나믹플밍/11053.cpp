#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int N;
int dp[1001] = {0,};
int A[1001] = {0,};
vector<int> lis[1001];
int main(void){
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d", &A[i]);
    }

    for (int k = 1; k <=N; k++){
	    dp[k] = 1;
        lis[k].push_back(A[k]);
        for (int i = 1; i<=k; i++){
            if(A[i] < A[k]){
                if(dp[i] + 1 > dp[k]){
                    dp[k] = dp[i] + 1;
                    lis[k].clear();
                    lis[k] = lis[i];
                    lis[k].push_back(A[k]);
                }
            }
        }
    }
    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (result < dp[i]) result = dp[i];
    }

    printf("%d\n", result);
    for (int i = 1; i <= N; i++)
        printf("%d ", lis[i]);

    
}