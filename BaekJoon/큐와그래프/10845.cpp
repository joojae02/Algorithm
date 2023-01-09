#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int N;
queue<int> q; 

int main(void){
    scanf("%d", &N);
    string input;
    int num;
    for(int i=0; i<N; i++){
        cin>>input;
        if(input == "push"){
            cin>>num;
            q.push(num);
        }
        else if(input == "pop"){
            if(q.empty())
                cout<<"-1"<<'\n';
            else{
                cout<<q.front()<<'\n';
                q.pop();
            }
        }
        else if(input == "size"){
            cout<<q.size()<<'\n';
        }
        else if(input == "empty"){
            cout<<q.empty()<<'\n';
        }
        else if(input == "front"){
            if(q.empty())
                cout<<"-1"<<'\n';
            else
                cout<<q.front()<<'\n';
        }
        else if(input == "back"){
            if(q.empty())
                cout<<"-1"<<'\n';
            else
                cout<<q.back()<<'\n';
        }
    }
}