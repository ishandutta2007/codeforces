#include <bits/stdc++.h>
using namespace std;
int n, m1, m2;
class DSU{
public:
    set <pair <int, int>> order;
    vector <int> s[100001];
    int from[100001];
    void init(){
        order.clear();
        for(int i=1; i<=n; i++){
            s[i].clear();
            s[i].push_back(i);
            from[i]=i;
            order.insert({1, i});
        }
    }
    void unite(int u, int v){
        if(from[u]==from[v]) return;
        u=from[u];
        v=from[v];
        if(s[u].size()<s[v].size()) swap(u, v);
        order.erase({s[u].size(), u});
        order.erase({s[v].size(), v});
        for(auto &&x: s[v]){
            from[x]=u;
            s[u].push_back(x);
        }
        s[v].clear();
        order.insert({s[u].size(), u});
    }
} da, db;
vector <int> ans;
void solve(){
    cin>>n;
    da.init();
    db.init();
    cin>>m1>>m2;
    for(int i=1, u, v; i<=m1; i++){
        cin>>u>>v;
        da.unite(u, v);
    }
    for(int i=1, u, v; i<=m2; i++){
        cin>>u>>v;
        db.unite(u, v);
    }
    if(da.order.size()>db.order.size()) swap(da, db);
    cout<<da.order.size()-1<<'\n';
    while(da.order.size()>1){
        int X = da.order.begin()->second;
        vector <pair <int, int>> pos;
        for(auto &&x: da.s[X]){
            pos.emplace_back(db.from[x], x);
        }
        sort(pos.begin(), pos.end());
        if(pos[0].first==pos.back().first){
            //all in the same component in the other side
            int Y = 0;
            for(auto &&[size, comp]: db.order){
                if(comp==db.from[X]) continue;
                Y=comp;
                break;
            }
            assert(Y);
            da.unite(X, Y);
            db.unite(X, Y);
            cout<<X<<' '<<Y<<'\n';
            continue;
        }
        else{
            //different component in other side, check if there is something else
            int old_comp=-1;
            int Y = 0;
            for(auto &&[comp, ver]: pos) if(comp!=old_comp){
                for(auto &&y: db.s[comp]) if(da.from[y]!=X){
                    Y=y;
                    break;
                }
                if(Y) break;
                old_comp=comp;
            }
            if(Y){
                for(auto &&x: da.s[X]) if(db.from[x]!=db.from[Y]){
                    X=x;
                    break;
                }
                assert(da.from[X]!=da.from[Y]);
                assert(db.from[X]!=db.from[Y]);
                da.unite(X, Y);
                db.unite(X, Y);
                cout<<X<<' '<<Y<<'\n';
                continue;
            }
            else{
                //Different component but there exist no Y in the same component with any of Xs
                //->Find a different component that no X belong to
                //
                int Y=0;
                for(auto &&[size, comp]: db.order){
                    if(da.from[comp]==X) continue;
                    Y=comp;
                    break;
                }
                assert(Y);
                da.unite(X, Y);
                db.unite(X, Y);
                cout<<X<<' '<<Y<<'\n';
                continue;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();
}