#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <string.h>


using namespace std;

int N, M;
int totalCnt;
vector<int> know;
vector<int> graph[51];
int answer = 0;


 
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> totalCnt;

    int tmp;
    for (int i=0; i<totalCnt; i++)
    {
        cin >> tmp;
        know.push_back(tmp);
    }
    for (int i=0; i<M; i++)
    {
        cin >> totalCnt;

        int tmp;
        for (int j=0; j<totalCnt; j++)
        {
            cin >> tmp;
            graph[i].push_back(tmp);
        }
    }

}