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
#define taskname "G"
class segment_tree;
using pointer=segment_tree*;
pointer p[200000][20], tree;
int n, k, q, min_all, b[200001], length;
class segment_tree{
public:
    pointer left, right;
    bool lazy;
    int value;
    segment_tree(pointer oldnode){
        (*this)=*oldnode;
        left=right=nullptr;
    }
    segment_tree(){
        left=right=nullptr;
        lazy=value=0;
    }
    void attach_children(pointer left, pointer right){
        this->left=left;
        this->right=right;
        value=min(left->value, right->value);
    }
    void generate_children(int l, int r, int m){
        if(left==nullptr){
            if((r-m)>n){
                left=new segment_tree();
                right=new segment_tree();
                left->value=right->value=min_all;
            }
            else{
                left=new segment_tree(p[l%n][__lg(r-m)]);
                right=new segment_tree(p[(m+1)%n][__lg(r-m)]);
            }
        }
        if(lazy){
            left->value=right->value=value;
            left->lazy=right->lazy=1;
            lazy=0;
        }
    }
    void update(int l, int r, int u, int v, int x){
        if((l>v)||(r<u)) return;
        if((u<=l)&&(v>=r)){
            value=x;
            lazy=1;
        }
        else{
            int m=(l+r)/2;
            generate_children(l, r, m);
            left->update(l, m, u, v, x);
            right->update(m+1, r, u, v, x);
            value=min(left->value, right->value);
        }
    }
    int get(int l, int r, int u, int v){
        if((l>v)||(r<u)) return 2e9;
        if((u<=l)&&(v>=r)) return value;
        else{
            int m=(l+r)/2;
            generate_children(l, r, m);
            return min(left->get(l, m, u, v), right->get(m+1, r, u, v));
        }
    }
};
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(k);
    length=1;
    while(length<n*k) length+=length;
    length--;
    FFOR(i, 0, n) read(b[i]);
    FFOR(i, 0, n) b[i+n]=b[i];
    min_all=*min_element(b, b+n);
    n=n+n;
    FFOR(i, 0, n){
        p[i][0]=new segment_tree();
        p[i][0]->value=b[i];
    }
    {
        int len=2, half=1;
        FOR(l, 1, 100){
            FFOR(i, 0, n){
                if(i+len-1>=n) break;
                p[i][l]=new segment_tree();
                p[i][l]->attach_children(p[i][l-1], p[i+half][l-1]);
            }
            half=len;
            len*=2;
            if(len>n) break;
        }
    }
    n=n/2;
    read(q);
    tree=new segment_tree();
    tree->value=min_all;
    {
        int o, l, r, x;
        FOR(i, 1, q){
            read(o);
            read(l);
            read(r);
            l--;
            r--;
            if(o==1){
                read(x);
                tree->update(0, length, l, r, x);
            }
            else writeln(tree->get(0, length, l, r));
        }
    }
}