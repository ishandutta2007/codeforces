#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
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
#define taskname "F"
vector <int> g[401];
string t[401];
bool done[401];
int n;
void dfs(int u){
    done[u]=1;
    for(int v: g[u]) if(!done[v]) dfs(v);
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    cin>>n;
    FOR(i, 1, n){
        cin>>t[i];
        int temp;
        while((temp=t[i].find("kh"))!=-1) t[i].erase(temp, 1);
        while((temp=t[i].find("u"))!=-1) t[i].replace(temp, 1, "oo");
    }
    FOR(i, 1, n) FOR(j, i+1, n) if(t[i]==t[j]){
        g[i].pb(j);
        g[j].pb(i);
    }
    int ans=0;
    FOR(i, 1, n) if(!done[i]){
        ans++;
        dfs(i);
    }
    write(ans);
}