#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>
#include<cstdio>

#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX 2147483647
using namespace std;

int T, K;
int input[1001][9] = {0,};
int k[1001][3] = {0,};
int visit[1001] = {0,};
void rotate(int t, int num){
    int tmp = 0;
    if(num == 1){
        tmp = input[t][7];
        input[t][7] = input[t][6];
        input[t][6] = input[t][5];
        input[t][5] = input[t][4];
        input[t][4] = input[t][3];
        input[t][3] = input[t][2];
        input[t][2] = input[t][1];
        input[t][1] = input[t][0];
        input[t][0] = tmp;
    }
    else if(num == -1){
        tmp = input[t][0];
        input[t][0] = input[t][1];
        input[t][1] = input[t][2];
        input[t][2] = input[t][3];
        input[t][3] = input[t][4];
        input[t][4] = input[t][5];
        input[t][5] = input[t][6];
        input[t][6] = input[t][7];
        input[t][7] = tmp;
    }
}
void func(int t, int num){
    if(0<=t&&t<T&&!visit[t]){
        visit[t] = 1;
        if(t<T-1){
            if(input[t][2] != input[t+1][6]){
                func(t+1, num*-1);
            }
        }
        if(t>0){
            if(input[t][6] != input[t-1][2]){
                func(t-1, num*-1);
            }
        }
        rotate(t, num);
    }
}


int main(void){
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        for(int j=0; j<8; j++){
            scanf("%1d", &input[i][j]);
        }
    }
    scanf("%d", &K);

    for(int i=0; i<K; i++){
        scanf("%d %d", &k[i][0], &k[i][1]);
    }

    for(int i=0; i<K; i++){
        int t = k[i][0];
        int num = k[i][1];
        func(t-1, num);
        fill_n(visit,T,0);

    }
    
    int sum = 0;
    for(int i=0; i<T; i++){
        sum += input[i][0];
    }
    printf("%d", sum);
}   