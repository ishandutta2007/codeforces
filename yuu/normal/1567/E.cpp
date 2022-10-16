#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[200002];
class SegmentTree{
public:
    int l, m, r, sz;
    int64_t il, ir;
    int64_t weight;
    SegmentTree *left, *right;
    SegmentTree(int l, int r): l(l), r(r), m((l+r)/2), sz(r-l+1){
        if(sz==1){
            il=ir=1;
            weight=1;
        }
        else{
            left=new SegmentTree(l, m);
            right=new SegmentTree(m+1, r);
            make();
        }
    }

    void make(){
        weight=left->weight+right->weight;
        il=left->il;
        ir=right->ir;
        if(a[right->l]>=a[left->r]){
            weight+=left->ir*right->il;
            if(il==left->sz) il+=right->il;
            if(ir==right->sz) ir+=left->ir;
        }
    }

    class ret{
    public:
        int sz;
        int64_t weight;
        int64_t il, ir;
        ret(int sz=0, int64_t weight=0, int64_t il=0, int64_t ir=0): sz(sz), weight(weight), il(il), ir(ir){}
    };
    ret get(int u, int v){
        // cerr<<u<<' '<<v<<' '<<l<<' '<<r<<'\n';
        // cerr<<weight<<' '<<il<<' '<<ir<<'\n';
        // cerr<<left->weight<<' '<<right->weight<<'\n';
        if((l>v)||(r<u)){
            return ret(0, 0, 0, 0);
        }
        else if((u<=l)&&(v>=r)){
            return ret(sz, weight, il, ir);
        }
        else{
            if(m>=v) return left->get(u, v);
            else if(m<u) return right->get(u, v);
            int64_t weight, il, ir;
            auto get_l=left->get(u, v);
            auto get_r=right->get(u, v);
            weight=get_l.weight+get_r.weight;

            il=get_l.il;
            ir=get_r.ir;
            if(a[left->r]<=a[right->l]){
                weight+=get_l.ir*get_r.il;
                if(il==get_l.sz){
                    il+=get_r.il;
                }
                if(ir==get_r.sz){
                    ir+=get_l.ir;
                }
            }
            // cerr<<u<<' '<<v<<' '<<l<<' '<<r<<' '<<m<<'\n'<<weight<<' '<<il<<' '<<ir<<'\n'<<get_l.sz<<' '<<get_r.sz<<' '
            // <<get_l.il<<' '<<get_l.ir<<' '<<get_r.il<<' '<<get_r.ir<<'\n';
            return ret(get_l.sz+get_r.sz, weight, il, ir);
        }
    }

    void update(int u, int x){
        if(l==r){
            a[u]=x;
        }
        else{
            if(m>=u) left->update(u, x);
            else right->update(u, x);
            make();
        }
    }
};

SegmentTree* tree;
void solve(){
    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>a[i];
    a[n+1]=1e9;
    a[0]=0;
    tree=new SegmentTree(1, n);
    for(int i=1, t, x, y; i<=q; i++){
        cin>>t>>x>>y;
        if(t==1) tree->update(x, y);
        else cout<<tree->get(x, y).weight<<'\n';
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