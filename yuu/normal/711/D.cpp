#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
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
#define taskname "D"
vector <int> g[200001];
vector <int> h[200001];
vector <int> order;
bool done[200001];
int comp[200001];
int n, a;
ll cnt;
const ll base=1000000007;
ll power(ll a, ll b){
	if(b==0) return 1;
	ll temp=power(a, b/2);
	temp=(temp*temp)%base;
	if(b%2)
		temp=(temp*a)%base;
	return temp;
}
void dfs(int u){
    done[u]=1;
    for(int v: g[u])
        if(!done[v])
            dfs(v);
    order.push_back(u);
}
void dfs2(int u, int c){
    comp[u]=c;
	cnt++;
    for(int v: h[u])
        if(comp[v]==-1)
            dfs2(v, c);
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
	read(n);
	FOR(i, 1, n){
		read(a);
		g[i].pb(a);
		h[a].pb(i);
	}
    FOR(i, 1, n){
        if(!done[i])
            dfs(i);
        comp[i]=-1;
    }
	ll ans=1;
    for(int i=0, j=0; i<n; i++){
        int v=order[order.size()-1-i];
		cnt=0;
        if(comp[v]==-1){
            dfs2(v, j++);
			if(cnt==1)
				ans=(ans*2)%base;
			else ans=(ans*(power(2, cnt)-2))%base;
		}
    }
	writeln(ans);
}