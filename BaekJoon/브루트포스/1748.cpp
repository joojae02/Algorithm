#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main(void){
    int N;
    scanf("%d",&N);
    int digit = 0;
    int n = N;
    while(n>0){ 
        n/=10;
        digit += 1;
    }
    int sum = 0;
    for(int i=0; i<digit-1; i++){
        sum += (9 * pow(10, i)) * (i+1);
    } 
    sum += (N - pow(10, digit-1) + 1) * (digit);
    printf("%d", sum);
}