#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <stack>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;

int n;

int h[300000];
vector<int> G[300000];

void add_edge(int i, int j){
    // cout << "add_edge(" << i << "," << j << ")" << endl;
    if(i < j) G[i].push_back(j);
    if(j < i) G[j].push_back(i);
}

bool used[300000];
int dist[300000];

void bfs(){
    queue<int> que;
    dist[0] = 0;
    que.push(0);
    used[0] = true;
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int to : G[v]){
            if(!used[to]){
                used[to] = true;
                dist[to] = dist[v]+1;
                que.push(to);
            }
        }
    }
}

void left_small(){
    stack<int> st;
    for(int i = 1; i < n; i++){
        if(h[i] >= h[i-1]){
            st.push(i-1);
        }else{
            while(!st.empty()){
                int top = st.top();
                if(h[top] <= h[i]) break;
                st.pop();
            }
        }
        if(!st.empty()){
            add_edge(st.top(), i);
        }
    }
}

void left_large(){
    stack<int> st;
    for(int i = 1; i < n; i++){
        if(h[i] <= h[i-1]){
            st.push(i-1);
        }else{
            while(!st.empty()){
                int top = st.top();
                if(h[top] >= h[i]) break;
                st.pop();
            }
        }
        if(!st.empty()){
            add_edge(st.top(), i);
        }
    }
}

void right_small(){
    stack<int> st;
    for(int i = n-2; i >= 0; i--){
        if(h[i] >= h[i+1]){
            st.push(i+1);
        }else{
            while(!st.empty()){
                int top = st.top();
                if(h[top] <= h[i]) break;
                st.pop();
            }
        }
        if(!st.empty()){
            add_edge(st.top(), i);
        }
    }
}

void right_large(){
    stack<int> st;
    for(int i = n-2; i >= 0; i--){
        if(h[i] <= h[i+1]){
            st.push(i+1);
        }else{
            while(!st.empty()){
                int top = st.top();
                if(h[top] >= h[i]) break;
                st.pop();
            }
        }
        if(!st.empty()){
            add_edge(st.top(), i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> h[i];
    left_small();
    left_large();
    right_small();
    right_large();
    for(int i = 0; i < n-1; i++) add_edge(i, i+1);
    bfs();
    cout << dist[n-1] << endl;
}