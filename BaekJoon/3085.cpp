#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int ans = 0;
int N;
char P[51][51];
void check() {
    int cnt;
    for (int i = 0; i < N; i++) {
        cnt = 1;
        for (int j = 0; j < N - 1; j++) { 
            if(P[i][j] == P[i][j+1]){ // 행 검사
                cnt++;
            }
            else{
                if(cnt > ans)
                    ans = cnt;
                cnt = 1;
            }
            
        }
        if(cnt > ans)
            ans = cnt;
    }
    for (int i = 0; i < N; i++) {
        cnt = 1;
        for (int j = 0; j < N - 1; j++) { 
            if(P[j][i] == P[j+1][i]){
                cnt++;
            }
            else{
                if(cnt > ans)
                    ans = cnt;
                cnt = 1;
            }
        }
        if(cnt > ans)
            ans = cnt;
    }
}
int main(void)
{
    cin >> N;
    string t;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) { 
            cin >> P[i][j];
        }
    }
    check();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) { 
            swap(P[i][j], P[i][j+1]);
            check();
            swap(P[i][j], P[i][j+1]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) { 
            swap(P[j][i], P[j+1][i]);
            check();
            swap(P[j][i], P[j+1][i]);
        }
    }
    printf("%d\n", ans);
}