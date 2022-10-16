#include <bits/stdc++.h>
using namespace std;
int a[100001];
int k[100001];
using ll=long long;
class segment_tree{
public:
    using pointer=segment_tree*;
    pointer left, right, parent;
    int l, r, m;
    int ne;
    ll sum, lazy;
    segment_tree(int l, int r, pointer parent=nullptr){
        this->l=l;
        this->r=r;
        this->parent=parent;
        m=(l+r)/2;
        lazy=0;
        if(l==r){
            sum=a[l];
            ne=(a[l]>a[l-1]+k[l-1]);
        }
        else{
            left=new segment_tree(l, m, this);
            right=new segment_tree(m+1, r, this);
            sum=left->sum+right->sum;
            ne=left->ne+right->ne;
        }
    }
    void down(){
        left->sum+=lazy*(m-l+1);
        right->sum+=lazy*(r-m);
        left->lazy+=lazy;
        right->lazy+=lazy;
        lazy=0;
    }
    void up(){
        ne=left->ne+right->ne;
        sum=left->sum+right->sum;
    }
    ll get(int u){
        if(u<l) return parent->get(u);
        if(l==r) return sum;
        else{
            down();
            if(u<=m) return left->get(u);
            else return right->get(u);
        }
    }
    ll fix(ll x){
        if(x<=0) return 0;
        if(ne==0){
            lazy+=x;
            sum+=x*(r-l+1);
            return x;
        }
        else if(l==r){
            ll pred=parent->get(l-1);
            ll res=pred+k[l-1]-sum;
            if(res>=0){
                sum+=res;
                ne=0;
            }
            return res;
        }
        else{
            down();
            ll res=right->fix(left->fix(x));
            up();
            return res;
        }
    }
    ll update(int u, ll x){///a[u]=a[u]+x
        if(l==r){
            sum+=x;
            ne=1;
            return x;
        }
        else{
            down();
            ll res;
            if(m>=u) res=right->fix(left->update(u, x));
            else res=right->update(u, x);
            up();
            return res;
        }
    }
    ll get(int u, int v){
        if(l>v||r<u) return 0;
        if(u<=l&&v>=r) return sum;
        else{
            down();
            return left->get(u, v)+right->get(u, v);
        }
    }
};
segment_tree::pointer tree;
int n, q;
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<n; i++) cin>>k[i];
    tree=new segment_tree(1, n);
    cin>>q;
    {
        char c;
        int a, b;
        while(q--){
            cin>>c>>a>>b;
            if(c=='+') tree->update(a, b);
            else cout<<tree->get(a, b)<<'\n';
        }
    }
}