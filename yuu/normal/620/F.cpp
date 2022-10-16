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
typedef long long ll;
typedef long double ld;
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
#define taskname "620F"
class trie{
public:
    typedef trie* iterator;
    int minvalue;
    int maxvalue;
    iterator g[2];
    trie(){
        g[0]=g[1]=nullptr;
        minvalue=1e9;
        maxvalue=-1e9;
    }
    void add(int x, int step, int key){
        minvalue=min(minvalue, key);
        maxvalue=max(maxvalue, key);
        if(step<0) return;
        if(g[bit(x, step)]==nullptr) g[bit(x, step)]=new trie();
        g[bit(x, step)]->add(x, step-1, key);
    }
    int get_min(int x, int step, int key, int now){
        if(step<0) return now;
        int b=bit(x, step);
        if((g[b^1]!=nullptr)){
            if((g[b^1]->minvalue<=key)) return g[b^1]->get_min(x, step-1, key, now*2+1);
        }
        return g[b]->get_min(x, step-1, key, now*2);
    }
    int get_max(int x, int step, int key, int now){
        if(step<0) return now;
        int b=bit(x, step);
        if((g[b^1]!=nullptr)){
            if((g[b^1]->maxvalue>=key)) return g[b^1]->get_max(x, step-1, key, now*2+1);
        }
        return g[b]->get_max(x, step-1, key, now*2);
    }
};
const int sz=sqrt(50000);
int n, m;
int a[50001];
int f[1001][1001];
int b[50001][1001];
int block[50001];
int sx[1000001];
trie::iterator tree[1001];
trie::iterator tree2[1001];
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    sx[0]=0;
    FOR(i, 1, 1000000) sx[i]=sx[i-1]^i;
    read(n);
    read(m);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) if((i%sz)==1) block[i]=block[i-1]+1;
    else block[i]=block[i-1];
    FOR(i, 1, block[n]) tree[i]=new trie();
    FOR(i, 1, block[n]) tree2[i]=new trie();
    FOR(i, 1, n){
        tree[block[i]]->add(sx[a[i]-1], 23, a[i]);
        tree2[block[i]]->add(sx[a[i]], 23, a[i]);
    }
    FOR(i, 1, n) FOR(j, 1, block[n]){
        b[i][j]=(tree[j]->minvalue<=a[i])?(tree[j]->get_min(sx[a[i]], 23, a[i], 0)):0;
        b[i][j]=max(b[i][j], (tree2[j]->maxvalue>=a[i])?(tree2[j]->get_max(sx[a[i]-1], 23, a[i], 0)):0);
        f[block[i]][j]=f[j][block[i]]=max(max(f[block[i]][j], f[j][block[i]]), b[i][j]);
    }
    FOR(length, 2, block[n]){
        FOR(i, 1, block[n]){
            int j=i+length-1;
            if(j>block[n]) break;
            f[i][j]=max(f[i][j], f[i+1][j]);
            f[i][j]=max(f[i][j], f[i][j-1]);
        }
    }
    {
        #define left _left
        #define right _right
        int l, r;
        FOR(qr, 1, m){
            vector <int> left;
            vector <int> right;
            vector <int> mid;
            read(l);
            read(r);
            int res=0;
            FOR(i, l, r) if(block[i]==block[l]) left.pb(i); else break;
            DFOR(i, r, l) if(block[i]==block[r]) right.pb(i); else break;
            FFOR(i, block[l]+1, block[r]) mid.pb(i);
            for(int x: left){
                for(int y: left) if(a[x]>=a[y]) res=max(res, sx[a[x]]^sx[a[y]-1]);
                for(int y: right) if(a[x]>=a[y]) res=max(res, sx[a[x]]^sx[a[y]-1]);
                for(int i: mid) res=max(res, b[x][i]);
            }
            for(int x: right){
                for(int y: left) if(a[x]>=a[y]) res=max(res, sx[a[x]]^sx[a[y]-1]);
                for(int y: right) if(a[x]>=a[y]) res=max(res, sx[a[x]]^sx[a[y]-1]);
                for(int i: mid) res=max(res, b[x][i]);
            }
            if(!mid.empty()) res=max(res, f[mid[0]][mid.back()]);
            writeln(res);
        }
    }

}