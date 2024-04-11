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
#define taskname "413E"
int n, m;
char c[3][200001];
int component[3][200001];
vector <int> v;
int cost[200001];
int r[200001];
int ccnt;
void dfs(int i, int j){
    component[i][j]=ccnt;
    if(j>1) if(c[i][j-1]=='.') if(!component[i][j-1]) dfs(i, j-1);
    if(j<n) if(c[i][j+1]=='.') if(!component[i][j+1]) dfs(i, j+1);
    if(i<2) if(c[i+1][j]=='.') if(!component[i+1][j]) dfs(i+1, j);
    if(i>1) if(c[i-1][j]=='.') if(!component[i-1][j]) dfs(i-1, j);
}
int first_greater_or_equal(int x){
    int l=0, r=v.size()-1, m, res;
    while(l<=r){
        m=(l+r)/2;
        if(v[m]>=x){
            res=m;
            r=m-1;
        }
        else l=m+1;
    }
    return res;
}
int query(int i1, int j1, int i2, int j2){
    if(component[i1][j1]!=component[i2][j2]) return -1;
    if(j1>j2){
        swap(i1, i2);
        swap(j1, j2);
    }
    int p1=first_greater_or_equal(j1);
    int p2=first_greater_or_equal(j2);
    if(p1==p2) return j2-j1+(i1!=i2);
    p2--;
    p1=v[p1];
    p2=v[p2];
    return p1-j1+(r[p1]!=i1)+j2-p2+(r[p2]!=i2)+cost[p2]-cost[p1];
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(m);
    FOR(i, 1, 2) FOR(j, 1, n) while(true){
        c[i][j]=getchar();
        if((c[i][j]=='.')||(c[i][j]=='X')) break;
    }
    FOR(i, 1, 2) FOR(j, 1, n){
        if((!component[i][j])&&(c[i][j]!='X')){
            ccnt++;
            dfs(i, j);
        }
    }
    FOR(j, 1, n) if(c[1][j]=='X'||c[2][j]=='X'){
        v.pb(j);
        if(c[1][j]=='X') r[j]=2;
        else r[j]=1;
    }
    FFOR(i, 1, v.size()){
//        if((c[1][v[i-1]]=='X')&&(c[2][v[i-1]]=='X')) continue;
//        if((c[1][v[i]]=='X')&&(c[2][v[i]]=='X')) continue;
        if((c[1][v[i-1]]=='X')==(c[1][v[i]]=='X')) cost[v[i]]=cost[v[i-1]]+v[i]-v[i-1];
        else cost[v[i]]=cost[v[i-1]]+v[i]-v[i-1]+1;
    }
    v.pb(n+1);
    {
        int a, b;
        FOR(i, 1, m){
            read(a);
            read(b);
            writeln(query(1+(a>n), (a%n==0)?n:a%n, 1+(b>n), (b%n==0)?n:b%n));
        }
    }
}