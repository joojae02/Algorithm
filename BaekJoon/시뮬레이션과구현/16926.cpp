#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>
#include<cstdio>

#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX 2147483647
using namespace std;

int N,M,R;
int input[301][301] ={0,};
int tmp[301][301] ={0,};
void func1(){
    copy(&input[0][0], &input[0][0]+301*301 , &tmp[0][0]);
    for(int i=1; i<=N/2; i++){ 
        for(int j=i; j<=M-i; j++){
            input[i][j] = tmp[i][j+1];
            input[N-i+1][M-j+1] = tmp[N-i+1][M-j];
        }
    }

    for(int i=1; i<=M/2; i++){ 
        for(int j=i; j<=N-i; j++){
            input[N-j+1][i] = tmp[N-j][i];
            input[j][M-i+1] = tmp[j+1][M-i+1];
        }
    }

}


int main(void){
    scanf("%d %d %d", &N, &M, &R);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%d", &input[i][j]);
        }
    }
    int in =0;
    for(int i=1; i<=R; i++){
        func1();
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            printf("%d ", input[i][j]);
        }
        printf("\n");
    }

}   