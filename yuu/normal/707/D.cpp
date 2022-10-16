#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
using ll=long long;
using ld=long double;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "707D"
class persistent_segment_tree{
public:
    using pointer=persistent_segment_tree*;
    int l, r, m;
    int count;
    pointer left, right;
    persistent_segment_tree(int l, int r, bool x){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        if(l==r) count=x;
        else{
            left=new persistent_segment_tree(l, m, x);
            right=new persistent_segment_tree(m+1, r, x);
            count=left->count+right->count;
        }
    }
    persistent_segment_tree (pointer x){
        (*this)=*x;
    }
    pointer update(int u, int x){
        pointer res=new persistent_segment_tree(this);
        if(l==r){
            res->count=x;
        }
        else{
            if(m>=u) res->left=left->update(u, x);
            else res->right=right->update(u, x);
            res->count=res->left->count+res->right->count;
        }
        return res;
    }
};
class pst2d{
public:
    using pointer=pst2d*;
    int count;
    persistent_segment_tree::pointer tree;
    int l, r, m;
    pointer left, right;
    pst2d(int l, int r, int sz, bool x){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        if(l==r){
            tree=new persistent_segment_tree(1, sz, x);
            count=tree->count;
        }
        else{
            tree=nullptr;
            left=new pst2d(l, m, sz, x);
            right=new pst2d(m+1, r, sz, x);
            count=left->count+right->count;
        }
    }
    pst2d (pointer x){
        (*this)=*x;
    }
    pointer update(int u, int v, bool x){
        pointer res=new pst2d(this);
        if(l==r){
            res->tree=tree->update(v, x);
            res->count=res->tree->count;
        }
        else{
            if(m>=u) res->left=res->left->update(u, v, x);
            else res->right=res->right->update(u, v, x);
            res->count=res->left->count+res->right->count;
        }
        return res;
    }
    static pair <pointer, pointer> exchange(pointer x, pointer y, int u){
        if(x->l==x->r){
            return mp(new pst2d(y), new pst2d(x));
        }
        else{
            pair <pointer, pointer> res=mp(new pst2d(x), new pst2d(y));
            if(x->m>=u){
                pair <pointer, pointer> r2=exchange(x->left, y->left, u);
                res.first->left=r2.first;
                res.second->left=r2.second;
            }
            else{
                pair <pointer, pointer> r2=exchange(x->right, y->right, u);
                res.first->right=r2.first;
                res.second->right=r2.second;
            }
            res.first->count=res.first->left->count+res.first->right->count;
            res.second->count=res.second->left->count+res.second->right->count;
            return res;
        }
    }
};
pst2d::pointer normal[100001];
pst2d::pointer invert[100001];
int n, m, q;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    read(q);
    normal[0]=new pst2d(1, n, m, 0);
    invert[0]=new pst2d(1, n, m, 1);
//    bug(normal[0]->count);
    {
        int o, u, v;
        FOR(i, 1, q){
            read(o);
            read(u);
            if(o<=2){
                read(v);
                if(o==1){
                    normal[i]=normal[i-1]->update(u, v, 1);
                    invert[i]=invert[i-1]->update(u, v, 0);
                }
                else{
                    normal[i]=normal[i-1]->update(u, v, 0);
                    invert[i]=invert[i-1]->update(u, v, 1);
                }
            }
            else if(o==3){
                pair<pst2d::pointer, pst2d::pointer> res=pst2d::exchange(normal[i-1], invert[i-1], u);
//                bug(res.first);
//                bug(res.second);
//                bug(res.first->count);
//                bug(res.second->count);
                normal[i]=res.first;
                invert[i]=res.second;
            }
            else{
                normal[i]=normal[u];
                invert[i]=invert[u];
            }
//            bug(normal[0]->count);
            writeln(normal[i]->count);
        }
    }
}