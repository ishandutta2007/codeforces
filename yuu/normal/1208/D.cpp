#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
using ll=long long;
using ld=long double;
#define taskname "D"
int n;
ll s[200001];
class segment_tree{
public:
    using pointer=segment_tree*;
    int l, r, m;
    ll value, lazy;
    int best;
    pointer left, right;
    segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        lazy=0;
        if(l==r){
            best=l;
            value=s[l];
        }
        else{
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
            up();
        }
    }
    void up(){
        if(right->value<=left->value){
            value=right->value;
            best=right->best;
        }
        else{
            value=left->value;
            best=left->best;
        }
    }
    void down(){
        left->value+=lazy;
        right->value+=lazy;
        left->lazy+=lazy;
        right->lazy+=lazy;
        lazy=0;
    }
    void update(int u, int v, ll x){
        if(l>v||r<u) return;
        if(u<=l&&v>=r){
            lazy+=x;
            value+=x;
        }
        else{
            down();
            left->update(u, v, x);
            right->update(u, v, x);
            up();
        }
    }
};
segment_tree::pointer tree;
int p[200001];
int main(){
    #ifdef Aria
        freopen(taskname".in", "r", stdin);
    #endif // Aria
    cin>>n;
    for(int i=1; i<=n; i++) cin>>s[i];
    tree=new segment_tree(1, n);
    for(int i=1; i<=n; i++){
        int u=tree->best;
        p[u]=i;
        tree->update(u+1, n, -i);
        tree->update(u, u, 1e14);
    }
    for(int i=1; i<=n; i++) cout<<p[i]<<" \n"[i==n];
}