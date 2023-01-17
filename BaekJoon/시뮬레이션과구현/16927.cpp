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
void func1(){
    int x=1, y=1;

    int first = input[x][y];
    int x1=x, y1=y;
    for(int i=1; i<=min(N,M)/2; i++)
    {
        for(int j=0; j<R%(2*(M+N)-4-8*(i-1));j++){
            x = i; y = i;
            x1=x; y1=y;
            first = input[x][y];
            while(y!=M-y1+1){
                input[x][y] = input[x][y+1];
                y++;
            }
            while(x!=N-x1+1){
                input[x][y] = input[x+1][y];
                x++;
            }
            while(y!=y1){
                input[x][y] = input[x][y-1];
                y--;
            }
            while(x!=x1){
                input[x][y] = input[x-1][y];
                x--;
            }
            input[x1+1][y1] = first;}
    }
}


int main(void){
    scanf("%d %d %d", &N, &M, &R);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%d", &input[i][j]);
        }
    }

    func1();
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            printf("%d ", input[i][j]);
        }
        printf("\n");
    }

}   