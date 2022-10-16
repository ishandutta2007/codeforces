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
#define taskname "335B"
#define count _count
int n;
int count[256];
string s;
int f[3000][3000];
bool done[3000][3000];
int F(int u, int v){
    if(done[u][v]) return f[u][v];
    done[u][v]=1;
    if(u>v) return f[u][v]=0;
    if(u==v) return f[u][v]=1;
    if(s[u]==s[v]) return f[u][v]=2+F(u+1, v-1);
    return f[u][v]=max(F(u+1, v), F(u, v-1));
}
void make(int l, int r, int left){
    if(left==0) return;
    if(l>r) return;
    if(l==r){
        cout<<s[l];
        return;
    }
    if(s[l]==s[r]){
        cout<<s[l];
        make(l+1, r-1, left-2);
        cout<<s[r];
        return;
    }
    if(F(l, r)==F(l+1, r)) make(l+1, r, left);
    else make(l, r-1, left);
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    cin>>s;
    n=s.size();
    for(char c: s){
        count[c]++;
        if(count[c]==100){
            FOR(i, 1, 100) putchar(c);
            return 0;
        }
    }
    s='0'+s;
    make(1, n, 100);
}