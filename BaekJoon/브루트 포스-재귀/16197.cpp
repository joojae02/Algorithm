#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>
#include<cstdio>

#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX 2147483647
using namespace std;
//1000000001
int N, M;
char input[21][21];
int result = -1;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int ans = -1;
bool range(int x, int y){
	if(x<0 || x>=N || y<0 || y>=M){
		return true;
	}
	return false;
}
void func(int depth, pair<int,int> c1, pair<int,int> c2)
{
	if(depth > result)
		return;
	if(depth > 10){
		result = min(result, depth);
		return;
	}
	int check = 0;
	if(range(c1.first, c1.second)){
		check += 1;
	}
	if(range(c2.first, c2.second)){
		check += 1;
	}
	
	if(check == 1){
		if(result > depth)
			result = depth;
		return;
	}
	else if(check == 2){
		return; 
	int cnx1, cny1, cnx2, cny2;
	int check1=0, check2=0;
	for(int i=0; i<4; i++){
		cnx1 = c1.first + dx[i];
		cny1 = c1.second + dy[i];
		cnx2 = c2.first + dx[i];
		cny2 = c2.second + dy[i];

		if(cnx1<0 || cnx1>=N || cny1<0 || cny1>=M)
			check1=1;
		if(cnx2<0 || cnx2>=N || cny2<0 || cny2>=M)
			check2=1;

		if(check1 == 0){
			if(input[cnx1 + dx[i]][cny1 + dy[i]] == '#'){
				cnx1 = cnx1 - dx[i];
				cny1 = cny1 - dy[i];
			}
		}
		if(check2 == 0){
			if(input[cnx2 + dx[i]][cny2 + dy[i]] == '#'){
				cnx2 = cnx2 - dx[i];
				cny2 = cny2 - dy[i];
			}
		}
		func(depth+1, make_pair(cnx1, cny1),make_pair(cnx2, cny2));
	}
}	

int main(void){
    scanf("%d %d", &N, &M);
	vector<pair<int, int>> coin;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
        	cin >> input[i][j];
			if(input[i][j] == 'o'){
				coin.push_back({i, j});
			}
		}
    }

	//printf("%d %d %d %d\n", coin[0].first, coin[0].second, coin[1].first, coin[1].second );
	func(0, coin[0], coin[1]);
	printf("%d", result);

}