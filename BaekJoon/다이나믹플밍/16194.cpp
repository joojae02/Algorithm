#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int N;
int price[1001] = {0,};
int P[1001] = {0,};

int main(void){
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &price[i]);

    P[1] = price[1];
    int tmp;

    for(int i=2; i<=N; i++){
        P[i] = price[i];
        for(int j=1; j<=i-1; j++){
            tmp = P[j] + P[i-j];
            if(P[i] > tmp)
                P[i] = tmp;
        }
    }
    printf("%d", P[N] );
}