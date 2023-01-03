#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS
#define ll long long int

using namespace std;

ll N, M, K;
ll P[15];
ll ans;
void greedy(ll depth, ll m, ll stock, ll loan) {
    if(depth == N - 1){
        ans = max(ans, m + P[depth] * stock);
        return;
    }
    ans = max(ans, m + P[depth] * stock);
    greedy(depth + 1, m, stock, loan);
    if(P[depth] <= P[depth + 1]){
        ll mon = m + P[depth] * stock;
        if(((mon - loan) * (K+ 1)) / P[depth] > 0){
            mon = mon - loan;
            ll n_loan = mon * K;
            mon = mon + n_loan;
            ll n_stock = mon / P[depth];
            greedy(depth + 1, mon - (P[depth] * n_stock), n_stock, n_loan);
        } 
    }
    else {
        ll mon = m + P[depth] * stock;
        if(depth == N - 2){
            ll tmp = ((mon - loan) * (K+ 1)) / P[depth];
            if( tmp * P[depth + 1] > mon){
                mon = mon - loan;
                ll n_loan = mon * K;
                mon = mon + n_loan;
                ll n_stock = mon / P[depth];
                greedy(depth + 1, mon - (P[depth] * n_stock), n_stock, n_loan);
            }       
        }
        else
            greedy(depth + 1, mon, 0, loan);
    }

}
int main(void) {
    cin >> N >> M >> K;
    for(int i = 0; i<N; i++){
        cin >> P[i];
    }
    ans = M;
    greedy(0, M, 0, 0);
    cout << ans;
}