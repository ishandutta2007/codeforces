#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e6+10,inf=2e9,mod=998244353;
LL Inf=2e18; 
__int128 n,a[M],m,b[M],ind[M];
char s[M],t[M];
vector<int> v[M];
void work(){
	n=read(); m=read();
	F(i,1,n) ind[i]=0,a[i]=read(),v[i].clear();
	F(i,1,m){
		int x=read(),y=read();
		v[x].pb(y);
	}
	F(T,1,n){
		F(i,1,n) b[i]=a[i];
		bool fl=0;
		F(i,1,n){
			if (a[i]>0){
				for (int y:v[i]){
					b[y]++;
				}
				b[i]--;
				fl=1;
			}
		}
		if (!fl){
			cout<<T-1<<"\n";
			return ;
		}
		F(i,1,n) a[i]=b[i];//,cerr<<(int)a[i]<<" ";
//		cerr<<" ffk\n";
	}
	LL ans=n;
	
	F(T,1,n){
		F(i,1,n) ind[i]=0;
		F(i,1,n){
			if (a[i]) for (int y:v[i]) ind[y]++;
		}
		__int128 mi=(__int128)Inf*Inf;
		F(i,1,n){
			if (a[i] && !ind[i]){
				if (mi>a[i]){
					mi=a[i];
//					cerr<<(int)mi<<"  mimi\n";
				}
			}
		}
		if (mi!=(__int128)Inf*Inf) ans=(ans+(LL)(mi%mod))%mod;
		else break;
		F(i,1,n){
			if (a[i]){
				a[i]+=mi*(ind[i]-1);
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
	while (T--) work();
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/