#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>
#include<cstdio>


#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX 2147483647
using namespace std;

int S=0;
int visit[1001][1001] = {0,};
int result = INT_MAX;
queue<pair<int, int>> q; 

int main(void){
    scanf("%d",&S);
    q.push(make_pair(1,0));
    visit[1][0] = 0;
    int tmp;
    while(!q.empty()){
        int next = q.front().first;
        int clip = q.front().second;
        int time = visit[next][clip];
        q.pop();
        if (next == S) {
			result = min(result, time);
			continue;
		}
        if(visit[next][next]==0){
            visit[next][next] = time+1;
            q.push(make_pair(next, next));
        }
        if(next+clip <=S &&!visit[next+clip][clip]){
            visit[next+clip][clip] = time+1;
            q.push(make_pair(next+clip, clip));
        }
        if (next-1 >= 0 && !visit[next - 1][clip]) {
			visit[next - 1][clip] = time + 1;
			q.push(make_pair(next - 1,clip ));
		}         
    }
    
    printf("%d", result);
}