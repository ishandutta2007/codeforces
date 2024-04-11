#include <bits/stdc++.h>
using namespace std;

vector <int> par, sz, label, salary, supervisor, comp;
vector < vector <int> > g;
vector <bool> vis;

void dfs(int u){
    vis[u] = true;
    comp.push_back(u);

    for(int v : g[u]){
        if(vis[v])continue;
        dfs(v);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    vector < vector <int> > a(n, vector <int> (n));
    vector < pair <int, pair <int, int> > > v;
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
        scanf("%d", &a[i][j]);
        if(i == j){
            salary.push_back(a[i][i]);
        }
        if(i < j){
            v.push_back(make_pair(a[i][j], make_pair(i, j)));
        }
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        par.push_back(i);
        label.push_back(i);
        supervisor.push_back(-1);
        sz.push_back(1);
    }

    auto findr = [&](int u){
        while(par[u] != u)u = par[u];
        return u;
    };
    auto connect = [&](int u, int v){
        u = findr(u);
        v = findr(v);

        if(sz[u] > sz[v])swap(u, v);

        par[u] = v;
        sz[v] += sz[u];
    };

    for(int i = 0; i < (int)v.size(); ){
        g.clear();
        g.resize(n);
        vis.clear();
        vis.resize(n, false);

        int j = i;
        while(j < (int)v.size() && v[j].first == v[i].first){
            int ui = findr(v[j].second.first);
            int vi = findr(v[j].second.second);

            g[ui].push_back(vi);
            g[vi].push_back(ui);

            j++;
        }

        for(int k = 0; k < n; k++)if(par[k] == k && !g[k].empty() && !vis[k]){
            comp.clear();
            dfs(k);

            salary.push_back(v[i].first);
            supervisor.push_back(-1);

            for(int l = 0; l < (int)comp.size(); l++)
                supervisor[label[comp[l]]] = (int)salary.size() - 1;
                        
            for(int l = 1; l < (int)comp.size(); l++)
                connect(comp[0], comp[l]);

            label[findr(comp[0])] = (int)salary.size() - 1;
        }

        i = j;
    }

    printf("%d\n", (int)salary.size());
    for(int i = 0; i < (int)salary.size(); i++){
        if(i > 0)printf(" ");
        printf("%d", salary[i]);
    }
    printf("\n");

    printf("%d\n", (int)salary.size());

    for(int i = 0; i + 1 < (int)salary.size(); i++){
        printf("%d %d\n", i + 1, supervisor[i] + 1);
    }

    return 0;
}