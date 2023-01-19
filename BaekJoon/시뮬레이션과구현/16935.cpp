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
int input[101][101] ={0,};
int tmp[101][101] ={0,};
void func1(){
    for(int i=1; i<=N/2; i++){
        for(int j=1; j<=M; j++){
            swap(input[i][j], input[N-i+1][j]);
        }
    }
}
void func2(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M/2; j++){
            swap(input[i][j], input[i][M-j+1]);
        }
    }
}
void func3(){
    copy(&input[0][0], &input[0][0]+101*101 , &tmp[0][0]);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            input[j][N-i+1] = tmp[i][j];
        }
    }
    swap(N, M);

}
void func4(){
    copy(&input[0][0], &input[0][0]+101*101 , &tmp[0][0]);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            input[M-j+1][i] = tmp[i][j];
        }
    }
    swap(N, M);
}
void func5(){
    copy(&input[0][0], &input[0][0]+101*101 , &tmp[0][0]);
    for(int i=1; i<=N/2; i++){
        for(int j=1; j<=M/2; j++){
            input[i][j+M/2] = tmp[i][j];
        }
    }
    for(int i=1; i<=N/2; i++){
        for(int j=M/2+1; j<=M; j++){
            input[i+N/2][j] = tmp[i][j];
        }
    }
    for(int i=N/2+1; i<=N; i++){
        for(int j=M/2+1; j<=M; j++){
            input[i][j-M/2] = tmp[i][j];
        }
    }
    for(int i=N/2+1; i<=N; i++){
        for(int j=1; j<=M/2; j++){
            input[i-N/2][j] = tmp[i][j];
        }
    }
}
void func6(){
    copy(&input[0][0], &input[0][0]+101*101 , &tmp[0][0]);
    for(int i=1; i<=N/2; i++){
        for(int j=1; j<=M/2; j++){
            input[i+N/2][j] = tmp[i][j];
        }
    }
    for(int i=1; i<=N/2; i++){
        for(int j=M/2+1; j<=M; j++){
            input[i][j-M/2] = tmp[i][j];
        }
    }
    for(int i=N/2+1; i<=N; i++){
        for(int j=M/2+1; j<=M; j++){
            input[i-N/2][j] = tmp[i][j];
        }
    }
    for(int i=N/2+1; i<=N; i++){
        for(int j=1; j<=M/2; j++){
            input[i][j+M/2] = tmp[i][j];
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
        scanf("%d", &in);
        if(in == 1){
            func1();
        }
        else if(in == 2){
            func2();
        }
        else if(in == 3){
            func3();
        }
        else if(in == 4){
            func4();
        }
        else if(in == 5){
            func5();
        }
        else if(in == 6){
            func6();
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            printf("%d ", input[i][j]);
        }
        printf("\n");
    }

}   