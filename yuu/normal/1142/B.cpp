#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
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
#define taskname "B"
int n, m, q;
int p[200002];
int pos[200002];
int a[200002];
int best[200002];
int ton[200002];
int from1[200002];
int f[200002];
vector <int> s[200002];
class segment_tree{
public:
    using pointer=segment_tree*;
    int l, r, m;
    int value;
    pointer left, right;
    segment_tree(int l, int r){
        this->l=l;
        this->r=r;
        m=(l+r)/2;
        if(l==r) value=f[l];
        else{
            left=new segment_tree(l, m);
            right=new segment_tree(m+1, r);
            value=min(left->value, right->value);
        }
    }
    int get(int u, int v){
        if(l>v||r<u) return 1e9;
        else if(u<=l&&v>=r) return value;
        else return min(left->get(u, v), right->get(u, v));
    }
};
segment_tree::pointer tree;
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(m);
    read(q);
    FOR(i, 1, n){
        read(p[i]);
        pos[p[i]]=i;
    }
    FOR(i, 1, m){
        read(a[i]);
        a[i]=pos[a[i]];
        s[a[i]].pb(i);
//        cerr<<a[i]<<" \n"[i==m];
    }
    FOR(i, 1, n) best[i]=m+1;
    DFOR(i, m, 1){
        if(a[i]==n) best[a[i]]=i;
        else best[a[i]]=best[a[i]+1];
        ton[i]=best[a[i]];
    }
    FOR(i, 1, n) best[i]=0;
    FOR(i, 1, m){
        if(a[i]==1) best[a[i]]=i;
        else best[a[i]]=best[a[i]-1];
        from1[i]=best[a[i]];
    }
    FOR(i, 1, m){
        if(a[i]==1) f[i]=ton[i];
        else{
            int low=0, high=((int)s[a[i]-1].size())-1, mid, res=m+1;
            while(low<=high){
                mid=(low+high)/2;
                if(from1[s[a[i]-1][mid]]>ton[i]){
                    res=s[a[i]-1][mid];
                    high=mid-1;
                }
                else low=mid+1;
            }
            f[i]=res;
        }
    }
    tree=new segment_tree(1, m);
    {
        int l, r;
        FOR(i, 1, q){
            read(l);
            read(r);
            putchar("01"[tree->get(l, r)<=r]);
        }
    }
}