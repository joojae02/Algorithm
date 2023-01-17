#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>
#include<cstdio>

#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX 2147483647
using namespace std;

int N,M,x,y, K;
int input[21][21] ={0,};
int k[1001] ={0,};
vector<int> ans;
int dice[7] = {0,};
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
void move(int num){
    int tmp;
    if(num == 1){
        tmp = dice[6];
        dice[6] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[3];
        dice[3] = tmp;
    }
    else if(num == 2){
        tmp = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = tmp;
    }
    else if(num == 3){
        tmp = dice[6];
        dice[6] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[2];
        dice[2] = tmp;
    }
    else if(num == 4){
        tmp = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = tmp;
    }
}
void func1(int num){
    int nx = x + dx[num-1];
    int ny = y + dy[num-1];
    if(0<=nx&&nx<N&&0<=ny&&ny<M){
        move(num);
        //printf("%d %d\n", nx, ny);
        if(input[nx][ny] == 0){
            input[nx][ny] = dice[1];
        }
        else{
            dice[1] = input[nx][ny];
            input[nx][ny] = 0;
        }
        printf("%d\n", dice[6]);
        x=nx;
        y=ny;
    }
}


int main(void){
    scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &input[i][j]);
        }
    }
    
    for(int i=0; i<K; i++){
        scanf("%d", &k[i]);
    }

    for(int i=0; i<K; i++){
        func1(k[i]);
    }


}   