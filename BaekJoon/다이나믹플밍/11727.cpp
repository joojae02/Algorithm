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
    
    for(int i=2; i<=N; i++){
        if(i%2 == 0){
            P[i] =(P[i-1]*2+1)% 10007;

        }
        else{
            P[i] =(P[i-1]*2-1)% 10007;
        }
    }
    printf("%d", P[N]);
}