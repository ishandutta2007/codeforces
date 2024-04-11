#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector <int> a(n + 1);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    a[0] = 0;
    
    vector <int> b(n + 1);
    for(int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    b[0] = 0;
    
    set <int> s;
    vector < vector <int> > g(n + 1);
    
    for(int i = 0; i <= n; i++){
        if(i + b[i] != n)s.insert(i);
        g[i + b[i]].push_back(i);
    }
    
    vector <int> parent(n + 1, -1);
    vector <int> jump(n + 1, -1);
    queue <int> q;

    parent[n] = n;
    q.push(n);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(u == 0)break;

        while(true){
            auto d = s.lower_bound(u - a[u]);
            if(d == s.end() || (*d) > u)break;

            int x = (*d);
            int v = x + b[x];
            parent[v] = u;
            jump[v] = x;

            for(int z : g[v])
                if(s.count(z))s.erase(z);
            q.push(v);

            if(s.count(x))s.erase(x);
        }
    }

    if(parent[0] == -1){
        printf("-1\n");
        return 0;
    }

    vector <int> v;
    int u = 0, u_jump = 0;
    while(u != n){
        v.push_back(u_jump);
        u = parent[u];
        u_jump = jump[u];
    }

    printf("%d\n", (int)v.size());
    for(int i = (int)v.size() - 1; i >= 0; i--){
        if(i != (int)v.size() - 1)printf(" ");
        printf("%d", v[i]);
    }
    printf("\n");

    return 0;
}