#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
using ll=long long;
using ld=long double;
#define taskname "E"
int n, w;
int a[1000001];
class segment_tree{
public:
    using pointer=segment_tree*;
    int l, r, m;
    ll value;
    pointer left, right;
    segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        value=0;
        if(l==r){

        }
        else{
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
        }
    }
    void update(int u, int v, ll x){
        if(l>v||r<u) return;
        if(u<=l&&v>=r){
            value+=x;
        }
        else{
            left->update(u, v, x);
            right->update(u, v, x);
        }
    }
    void get_tree(ll now){
        now+=value;
        if(l==r) cout<<now<<" \n"[r==w];
        else{
            left->get_tree(now);
            right->get_tree(now);
        }
    }
};
segment_tree::pointer tree;
class segment_tree_max{
public:
    using pointer=segment_tree_max*;
    int l, r, m;
    ll value;
    pointer left, right;
    segment_tree_max(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        value=-1e18;
        if(l==r){

        }
        else{
            left=new segment_tree_max(l, m);
            right=new segment_tree_max(m+1, r);
        }
    }
    void reset(){
        value=-1e18;
        if(l!=r){
            left->reset();
            right->reset();
        }
    }
    void update(int u, int v, ll x){
        if(l>v||r<u) return;
        if(u<=l&&v>=r){
            value=max(value, x);
        }
        else{
            left->update(u, v, x);
            right->update(u, v, x);
        }
    }
    void get_tree(ll now){
        now=max(now, value);
        if(l==r){
            tree->update(l, l, now);
//            cerr<<l<<' '<<now<<"\n";
        }
        else{
            left->get_tree(now);
            right->get_tree(now);
        }
    }
};
segment_tree_max::pointer treemax;
int main(){
    #ifdef Aria
        freopen(taskname".in", "r", stdin);
    #endif // Aria
    cin>>n>>w;
    tree=new segment_tree(1, w);
    treemax=new segment_tree_max(1, w);
    for(int r=1; r<=n; r++){
        int m;
        cin>>m;
        for(int i=1; i<=m; i++) cin>>a[i];
        if(m==w){///can't slide
            for(int i=1; i<=m; i++) tree->update(i, i, a[i]);
        }
        else{
            if(m+m<w){
                int mx=0;
                for(int i=1; i<=m; i++){
                    mx=max(mx, a[i]);
                    tree->update(i, i, mx);
                }
                mx=0;
                for(int i=1; i<=m; i++){
                    mx=max(mx, a[m-i+1]);
                    tree->update(w-i+1, w-i+1, mx);
                }
                tree->update(m+1, w-m, mx);
            }
            else{
                treemax->reset();
                for(int i=1; i<=m; i++){
                    treemax->update(i, i+w-m, a[i]);
                }
                treemax->update(1, w-m, 0);
                treemax->update(m+1, w, 0);
                treemax->get_tree(-1e18);
            }
        }
    }
    tree->get_tree(0);
}