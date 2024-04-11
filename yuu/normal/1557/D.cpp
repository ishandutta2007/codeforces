#include <bits/stdc++.h>
using namespace std;
class SegmentTree{
public:
    using pointer=SegmentTree*;
    int l, r, m;
    pointer left, right;
    pair <int, int> best;
    pair <int, int> lazy;
    SegmentTree(int l, int r): l(l), r(r), m((l+r)/2), best(0, 0){
        if(l!=r){
            left=new SegmentTree(l, m);
            right=new SegmentTree(m+1, r);
        }
    }
    void down(){
        left->best=min(left->best, lazy);
        right->best=min(right->best, lazy);
        left->lazy=min(left->lazy, lazy);
        right->lazy=min(right->lazy, lazy);
        lazy={0, 0};
    }
    void up(){
        best=min(left->best, right->best);
    }
    void update(int u, int v, pair<int, int> p){
        if(l>v||r<u) return;
        if(u<=l&&v>=r){
            lazy=min(lazy, p);
            best=min(best, p);
        }
        else{
            down();
            left->update(u, v, p);
            right->update(u, v, p);
            up();
        }
    }
    pair <int, int> get(int u, int v){
        if(l>v||r<u) return {0, 0};
        if(u<=l&&v>=r) return best;
        else{
            down();
            return min(left->get(u, v), right->get(u, v));
        }
    }
};
SegmentTree::pointer tree;
int n, m;
vector <pair <int, int>> g[300001];
int trace[300001];
vector <int> arr;
map <int, int> M;
bool keep[300001];
int cnt=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1, x, l, r; i<=m; i++){
        cin>>x>>l>>r;
        g[x].emplace_back(l, r);
        arr.push_back(l);
        arr.push_back(r);
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for(auto &&x: arr) M[x]=++cnt;
    tree=new SegmentTree(1, cnt);
    for(int i=1, l, r; i<=n; i++){
        int val=0;
        for(auto &x: g[i]){
            x.first=l=M[x.first];
            x.second=r=M[x.second];
            auto p = tree->get(l, r);
            //f[i]=min(f[j]+i-j-1)
            if(p.first<val){
                val=p.first;
                trace[i]=p.second;
            }
        }
        val+=i-1;//f[i]
        val-=i;//f[i]-i
        pair<int, int> p={val, i};
        for(auto &x: g[i]){
            tree->update(x.first, x.second, p);
        }
    }
    int ans=n;
    auto p=tree->get(1, cnt).second;
    while(p){
        ans--;
        keep[p]=1;
        p=trace[p];
    }
    cout<<ans<<'\n';
    for(int i=1; i<=n; i++) if(!keep[i]) cout<<i<<" ";
}