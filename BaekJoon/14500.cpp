#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int N, M;

int P[501][501];

int main(void){
    cin >> N >> M;
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
        {
            int tmp;
            cin >> tmp;
            P[i][j] = tmp;
        }
    int result = 0;
    //case1
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M-3; j++){
            int tmp = P[i][j]+P[i][j+1]+P[i][j+2]+P[i][j+3];
            if(result < tmp)
                result = tmp;
        }   
    }
    for(int i = 0; i<N-3; i++){
        for(int j = 0; j<M; j++){
            int tmp = P[i][j]+P[i+1][j]+P[i+2][j]+P[i+3][j];
            if(result < tmp)
                result = tmp;
        }   
    }

    //case2
    for(int i = 0; i<N-1; i++){
        for(int j = 0; j<M-1; j++){
            int tmp = P[i][j]+P[i][j+1]+P[i+1][j]+P[i+1][j+1];
            if(result < tmp)
                result = tmp;
        }   
    }

    //case3
    for(int i = 0; i<N-1; i++){
        for(int j = 0; j<M-2; j++){
            int tmp = P[i][j]+P[i][j+1]+P[i][j+2]+P[i+1][j+2];
            if(result < tmp)
                result = tmp;
            tmp = P[i][j]+P[i][j+1]+P[i][j+2]+P[i+1][j];
            if(result < tmp)
                result = tmp;
            tmp = P[i+1][j]+P[i+1][j+1]+P[i+1][j+2]+P[i][j+2];
            if(result < tmp)
                result = tmp;
            tmp = P[i+1][j]+P[i+1][j+1]+P[i+1][j+2]+P[i][j];
            if(result < tmp)
                result = tmp;
        }   
    }
    for(int i = 0; i<N-2; i++){
        for(int j = 0; j<M-1; j++){
            int tmp = P[i][j]+P[i][j+1]+P[i+1][j+1]+P[i+2][j+1];
            if(result < tmp)
                result = tmp;
            tmp = P[i][j]+P[i][j+1]+P[i+1][j]+P[i+2][j];
            if(result < tmp)
                result = tmp;
            tmp = P[i][j]+P[i+1][j]+P[i+2][j]+P[i+2][j+1];
            if(result < tmp)
                result = tmp;
            tmp = P[i][j+1]+P[i+1][j+1]+P[i+2][j+1]+P[i+2][j];
            if(result < tmp)
                result = tmp;
        }   
    }

    //case4

    for(int i = 0; i<N-1; i++){
        for(int j = 0; j<M-2; j++){
            int tmp = P[i][j]+P[i][j+1]+P[i+1][j+1]+P[i+1][j+2];
            if(result < tmp)
                result = tmp;
            tmp = P[i+1][j]+P[i][j+1]+P[i][j+2]+P[i+1][j+1];
            if(result < tmp)
                result = tmp;
        }   
    }
    for(int i = 0; i<N-2; i++){
        for(int j = 0; j<M-1; j++){
            int tmp = P[i][j]+P[i+1][j]+P[i+1][j+1]+P[i+2][j+1];
            if(result < tmp)
                result = tmp;
            tmp = P[i][j+1]+P[i+1][j]+P[i+1][j+1]+P[i+2][j];
            if(result < tmp)
                result = tmp;
        }   
    }

    //case5
    for(int i = 0; i<N-1; i++){
        for(int j = 0; j<M-2; j++){
            int tmp = P[i][j+1]+P[i+1][j]+P[i+1][j+1]+P[i+1][j+2];
            if(result < tmp)
                result = tmp;
            tmp = P[i][j]+P[i][j+1]+P[i][j+2]+P[i+1][j+1];
            if(result < tmp)
                result = tmp;
        }   
    }
    for(int i = 0; i<N-2; i++){
        for(int j = 0; j<M-1; j++){
            int tmp = P[i][j]+P[i+1][j]+P[i+2][j]+P[i+1][j+1];
            if(result < tmp)
                result = tmp;
            tmp = P[i][j+1]+P[i+1][j+1]+P[i+2][j+1]+P[i+1][j];
            if(result < tmp)
                result = tmp;
        }   
    }
    printf("%d", result);
}