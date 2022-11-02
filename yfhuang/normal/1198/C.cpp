#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
int T;

const int maxn = 5e5 + 5;
bool vis[maxn];
int n, m;
int u[maxn], v[maxn];
typedef pair<int, int> pii;

set<int> s;

vector<int> G[maxn];
int main(){
    cin >> T;
    while(T--){
        s.clear();
        cin >> n >> m;
        for(int i = 1;i <= m;i++){
            scanf("%d%d", &u[i], &v[i]);
            G[u[i]].push_back(i);
            G[v[i]].push_back(i);
            s.insert(i);
        }
        for(int i = 1;i <= 3 * n;i++){
            vis[i] = false;
        }
        vector<int> matching;
        while(!s.empty() and matching.size() < n){
            int id = *s.begin();
            s.erase(id); 
            matching.push_back(id);
            vis[u[id]] = true;
            vis[v[id]] = true;
            for(auto i : G[u[id]]){
                if(s.find(i) != s.end()){
                    s.erase(i);
                }
            }
            for(auto i : G[v[id]]){
                if(s.find(i) != s.end()){
                    s.erase(i);
                }
            }
        }
        vector<int> Iset;
        if(matching.size() < n){
            for(int i = 1;i <= 3 * n;i++){
                if(!vis[i]){
                    Iset.push_back(i);
                }
            }
            cout << "IndSet" << endl;
            for(int i = 0;i < n;i++){
                printf("%d%c", Iset[i], i == n - 1 ? '\n' : ' '); 
            }
        }else{
            cout << "Matching" << endl;
            for(int i = 0;i < n;i++){
                printf("%d%c", matching[i], i == n - 1 ? '\n' : ' ');
            }
        }
        for(int i = 1;i <= 3 * n;i++){
            G[i].clear();
        }
    }
    return 0;
}