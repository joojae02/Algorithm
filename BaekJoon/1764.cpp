#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;    

int N, M;

map<string, int> m;
vector<string> vec;
int cnt =0;
int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);	
    cin >> N >> M;
    
    string tmp;

    for(int i=0; i<N; i++)
    {
        cin >> tmp;
        m.insert(make_pair(tmp, i));
    }
    for(int i=0; i<M; i++)
    {
        cin >> tmp;
        if (m.find(tmp)!=m.end())
        {
            cnt++;
            vec.push_back(tmp);
        }
    }
    sort(vec.begin(), vec.end());
    cout << cnt << '\n';
    for(int i=0; i<vec.size(); i++)
        cout << vec[i] <<'\n';
}