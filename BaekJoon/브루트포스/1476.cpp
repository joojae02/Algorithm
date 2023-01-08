#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int E, S, M;
int E1 =1 , S1 = 1, M1= 1;

int check() {
    if(E == E1)
        if(S == S1)
            if(M == M1)
                return 1;
    return 0;
}
int main(void) {
    cin >> E >> S >> M;
    int i = 1;
    while(1){
        if(E1 == 16)
            E1 = 1;
        if(S1 == 29)
            S1 = 1;
        if(M1 == 20)
            M1 = 1;
        if(check()){
            printf("%d", i);
            break;
        }
        E1++;
        S1++;
        M1++;

        i++;
    }
}