#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>
#include<cstdio>

#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX 2147483647
using namespace std;
int k = -1;
int input[14] = {0,};
int visit[14] = {0,};
int result[7] = {0,};
void func(int cnt, int now){
    if(cnt == 6){
        for(int i=0; i<6; i++){
            printf("%d ", result[i]);
        }
        printf("\n");
    }
    for(int i=now; i<k; i++){
        result[cnt] = input[i];
        func(cnt+1, i+1);
    }
}
int main(void){
    while(k!=0){
        scanf("%d", &k);
        for(int i=0; i<k; i++){
            scanf("%d", &input[i]);
        }
        func(0, 0);
        printf("\n");
    }

}