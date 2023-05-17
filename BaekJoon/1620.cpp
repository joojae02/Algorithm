#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;    

int N, M;

map<string, int> m;
string name[100001];

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);	
    cin >> N >> M;
    
    string tmp;

    for(int i=1; i<=N; i++)
    {
        cin >> tmp;
        name[i] = tmp;
        m.insert(make_pair(tmp, i));
    }
    cout << "\n\n";
    for(int i=1; i<=M; i++)
    {
        cin >> tmp;
        if (m.find(tmp)!=m.end())
        {
            cout << m.find(tmp)->second << '\n';
        }
        else
        {
            cout << name[stoi(tmp)] << '\n';
        }
    }
}