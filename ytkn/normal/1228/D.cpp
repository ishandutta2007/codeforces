#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> P;

vector<int> G[100000];
set<P> st;
int N, M;

bool used[100000];
int type[100000];
void clear(){
    for(int i = 0; i < N; i++) used[i] = false;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a > b) swap(a, b);
        st.insert(P(a, b));
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < N; i++){
        type[i] = 1;
    }
    for(int i = 0; i < G[0].size(); i++){
        int to = G[0][i];
        type[to] = 0;
    }
    int c;
    for(int i = 0; i < N; i++){
        if(type[i] == 0){
            c = i;
            break;
        }
    }
    for(int i = 0; i < N; i++){
        if(type[i] == 0) type[i] = 2;
    }
    for(int i = 0; i < G[c].size(); i++){
        int to = G[c][i];
        if(type[to] == 2) type[to] = 0;
    }
    int cnt[3];
    for(int i = 0; i < 3; i++) cnt[i] = 0;
    for(int i = 0; i < N; i++){
        cnt[type[i]]++;
    }
    for(int i = 0; i < 3; i++) {
        if(cnt[i] == 0){
            cout << -1 << endl;
            return 0;
        }
    }
    for(auto iter = st.begin(); iter != st.end(); iter++){
        int a = iter->first;
        int b = iter->second;
        if(type[a] == type[b]){
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i = 0; i < N; i++){
        int t = type[i];
        if(G[i].size()+cnt[t] != N){
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i = 0; i < N-1; i++){
        cout << type[i]+1 << ' ';
    }
    cout << type[N-1]+1 << endl;
}