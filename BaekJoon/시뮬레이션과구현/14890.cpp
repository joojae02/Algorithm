#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>
#include<cstdio>

#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX 2147483647
using namespace std;

int N, L;
int input[101][101] ={0,};
vector<int> ans;
int func(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N-1; j++){
            if(input[i][j] == input[i][j+1]+1){
                for(int k=j+1;k<N;k++){

                }
            }
        }
    }
}


int main(void){
    scanf("%d %d", &N, &L);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &input[i][j]);
        }
    }
    

}   