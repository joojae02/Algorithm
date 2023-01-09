#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int N;
int P[1000001] = {0,};

int main(void){
    scanf("%d", &N);
    P[2] = 1;
    P[3] = 1;
    for(int i=4; i<=N; i++){
        int tmp = 0;
        P[i] = P[i - 1] + 1;
        if(i%2 == 0){
            tmp = P[i/2] + 1;
            if(tmp < P[i])
                P[i] = tmp;
        }
        if(i%3 == 0){
            tmp = P[i/3] + 1;
            if(tmp < P[i])
                P[i] = tmp;
        }
    }
    printf("%d", P[N]);
}