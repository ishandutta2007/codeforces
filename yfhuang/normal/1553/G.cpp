#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int n, q;
const int maxn = 1e6 + 5; 
int a[maxn];

vector<int> pdiv[maxn];
bool isprime[maxn];

void init(){
    isprime[1] = true;
    for(int i = 2;i < maxn;i++){
        if(!isprime[i]){
            for(int j = i;j < maxn;j += i){
                pdiv[j].push_back(i);
                if(j > i)
                    isprime[j] = true;
            }
        }
    }
}

int fa[maxn];

int Find(int x){
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

map<pi, int> edges;

void Union(int x, int y){
    int fx = Find(x);
    int fy = Find(y);
    if(fx == fy)
        return;
    fa[fx] = fy;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    cin >> n >> q;
    for(int i = 1;i < maxn;i++){
        fa[i] = i;
    }
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        for(auto p : pdiv[a[i]]){
            Union(p, a[i]);
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < pdiv[a[i]+1].size();j++){
            int p1 = pdiv[a[i]+1][j]; 
            int fx = Find(a[i]);
            int fy = Find(p1);
            edges[mp(fx, fy)] = 1;
            for(int k = j+1;k < pdiv[a[i]+1].size();k++){
                int p2 = pdiv[a[i]+1][k];
                int fz = Find(p2);
                edges[mp(fy, fz)] = 1;
            }
        }
    }
    for(int i = 1;i <= q;i++){
        int s, t;
        cin >> s >> t; 
        int fx = Find(a[s]);
        int fy = Find(a[t]);
        if(fx == fy){
            cout << 0 << '\n';
        }else{
            if(edges.count(mp(fx, fy)) or edges.count(mp(fy, fx)))
                cout << 1 << '\n';
            else
                cout << 2 << '\n';
        }
    }
    return 0;
}