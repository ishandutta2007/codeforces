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
#define taskname "C"
const ll inf=10000000000000000;
ll f[102][102][102];
ll p[102][102];
int c[102];
inline void update(ll &x, ll y){
	x=(x<y?x:y);
}
int n, m, k;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
	read(n);
	read(m);
	read(k);
	FOR(i, 1, n)
		read(c[i]);
	FOR(i, 1, n) FOR(j, 1, m)
			read(p[i][j]);
	FOR(i, 1, n) FOR(j, 1, m) FOR(l, 1, k)
		f[i][j][l]=inf;
	if(c[1])
		f[1][c[1]][1]=0;
	else
		FOR(z, 1, m)
			f[1][z][1]=p[1][z];
	FOR(i, 1, n-1){
		int l, r;
		if(c[i]==0)
			l=1, r=m;
		else l=r=c[i];
		if(c[i+1]==0)
			FOR(j, l, r){
				FOR(h, 1, k){
					if(f[i][j][h]==inf) continue;
					FOR(z, 1, m)
						update(f[i+1][z][h+(z!=j)], f[i][j][h]+p[i+1][z]);
				}
			}
		else
			FOR(j, l, r){
				FOR(h, 1, k){
					if(f[i][j][h]==inf) continue;
					update(f[i+1][c[i+1]][h+(c[i+1]!=j)], f[i][j][h]);
				}
			}
	}
	ll ans=inf;
	FOR(i, 1, m)
		update(ans, f[n][i][k]);
	if(ans==inf){
		puts("-1");
		return 0;
	}
	writeln(ans);	
}