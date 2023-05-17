#include <iostream> 
#include <vector> 
#include <queue>

using namespace std; 

int N; 
int result[100001]; 
bool visited[100001]; 
vector<int> graph[100001]; 

void bfs(){
    queue<int> q;
    visited[1] = true;
    q.push(1);
    
    while(!q.empty()){
        int p = q.front();
        q.pop();
        
        for(int i=0; i<graph[p].size(); i++){
            int c = graph[p][i];
            if(!visited[c]){
                result[c] = p;
                visited[c] = true;
                q.push(c);
            }
        }
    }
}

int main() {
    cin >> N; 
    for(int i=0; i<N; i++) { 
        int x, y; 
        cin >> x >> y; 
        graph[x].push_back(y); 
        graph[y].push_back(x); 
    } 
    
    bfs(); 
    
    for(int i=2; i<=N; i++) 
        cout << result[i] << "\n"; 
}