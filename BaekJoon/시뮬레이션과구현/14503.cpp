#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>
#include<cstdio>

#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX 2147483647
using namespace std;

int N, M;
int r, c;
int dir;
int input[51][51] = {0,};
int visit[51][51] = {0,};
int dx[4] = {-1, 0, 1, 0};//0 1 2 3
int dy[4] = {0, 1, 0, -1};
int ans = 0;
int sum = 0;
bool check(int r, int x, int d){
    if(d == 0){
        for(int i=r; i >=0 ; i--){
            if(input[i][x] == 1)
                break;
            if(input[i][x] == 0 && !visit[i][x]){

                return true;
            }
        }
    }
    else if(d == 1){
        for(int i=x; i <M ; i++){
            if(input[r][i] == 1)
                break;
            if(input[r][i] == 0 && !visit[r][i]){
                return true;
            }
        }
    }
    else if(d == 2){
        for(int i=r; i <N ; i++){
            if(input[i][x] == 1)
                break;
            if(input[i][x] == 0 && !visit[i][x]){
                return true;
            }
        }
    }    
    else if(d == 3){
        for(int i=r; i >=0 ; i--){
            if(input[r][i] == 1)
                break;
            if(input[r][i] == 0 && !visit[x][i]){
                return true;
            }
        }
    }
    sum += 1;
    return false;
}

void func(int r, int c, int d){
    if(r<1&&r>=N&&c<1&&c>=M)
        return;
    int left = (d == 0) ? 3 : d-1;
    visit[r][c] = 1;
    if(input[r][c] == 0){
        input[r][c] = -1;
    }
    if(sum == 4){
        if()
    }
    if(check(r, c, left)){
        if(input[r][c])
    }
    else{

    }
}


int main(void){
    scanf("%d %d", &N, &M);

    scanf("%d %d %d", &r, &c, &dir);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &input[i][j]);
        }
    }
    func(r, c, dir)

}   