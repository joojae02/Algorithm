#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int N;
int P[1001] = {0,};

int main(void){
    scanf("%d", &N);
    P[1] = 1;
    P[2] = 2;
    for(int i=3; i<=N; i++){
        P[i] =(P[i-1] + P[i-2])% 10007;
    }
    printf("%d", P[N] );
}