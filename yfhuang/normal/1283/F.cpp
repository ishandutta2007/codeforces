#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int n;
const int maxn = 2e5 + 5;
int a[maxn];
vector<int> G[maxn];
set<int> s, s1;

void dfs(int u, int fa){
    for(auto v : G[u]){
        if(v != fa){
            printf("%d %d\n", u, v);
            dfs(v, u);
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        scanf("%d", &a[i]);
    }
    a[n] = a[1];
    int root = a[1];
    s.insert(root);
    int i = 1;
    for(int i = 1;i <= n;i++){
        if(i != root)
            s1.insert(i);
    }
    while(!s1.empty()){
        int now = *s1.rbegin();
        s.insert(now);
        s1.erase(now);
        int j = i + 1;
        while(s.find(a[j]) == s.end()){
            int u = a[j - 1];
            int v = a[j];
            G[u].push_back(v);
            G[v].push_back(u);
            s1.erase(v);
            s.insert(v);
            j++;
        }
        int u = a[j - 1];
        int v = now;
        G[u].push_back(v);
        G[v].push_back(u);
        s1.erase(v);
        s.insert(v);
        i = j;
    }
    cout << root << endl;
    //for(int u = 1;u <= n;u++){
    //    cout << "node " << u << endl;
    //    for(auto v : G[u]){
    //        cout << v << " ";
    //    }
    //    cout << endl;
    //}
    dfs(root, root);
    return 0;
}