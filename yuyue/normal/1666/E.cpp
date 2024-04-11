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
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e5+10;
int L,n,a[M];
int dp[50][50][50][50],hh;
void solve(){
	dp[0][0][L][0]=1;
	
	F(i,1,n){
		F(j,0,a[i]){
			F(mi,0,L){
				F(mx,0,L){
					if (dp[i-1][j][mi][mx]){
//						cerr<<i-1<<" "<<j<<" "<<mi<<" "<<mx<<"   oo\n";
						F(k,(i==n ? L : a[i]),a[i+1]){
							int le=k-j;
							dp[i][k][min(mi,le)][max(mx,le)]=1; 
						}
					}
				}
			}
		}
	}
	int ans=1e9;
	F(mi,0,L) F(mx,0,L){
		if (dp[n][L][mi][mx]){
			if (mx-mi<=ans){
				ans=mx-mi;
				cerr<<mi<<" "<<mx<<"\n";
			}
		}
	}
	cerr<<ans<<"  ans\n";
	int tmp=1e9;
	F(i,0,n+1){
		F(j,i+2,n+1){
			int o=(a[j]-a[i])/(j-i-1);
			tmp=min(tmp,o);
		}
	}
	cerr<<tmp<<"\n";
	hh=tmp;
//	cerr<<dp[n][L][tmp][tmp+ans]<<"   ok ??? \n";
	assert(dp[n][L][tmp][tmp+ans]);
}
LL s[M];
int Lo[M],Ro[M],Al[M],Ar[M];
bool chk(int mi,int mx){
	Lo[0]=Ro[0]=0;
	F(i,1,n){
		Lo[i]=Lo[i-1]+mi;
		Ro[i]=Ro[i-1]+mx;
		Lo[i]=max(Lo[i],a[i]);
		Ro[i]=min(Ro[i],a[i+1]);
		if (Lo[i]>Ro[i]) return 0;
	}
	return Lo[n]<=L && L<=Ro[n];
}
void work(){
	int l=1,r=L,ret=r;
	while (l<=r){
		int mid=(l+r>>1);
		LL mi=-1e18;
		bool fl=1;
		F(i,0,n+1){
			s[i]=a[i]-1ll*mid*i;
			if (i>=2){
				mi=max(mi,s[i-2]);
			}
			if (s[i]+mid<mi) 
			fl=0;
		}
		if (fl) l=mid+1,ret=mid;
		else r=mid-1;
	}
//	cerr<<ret<<" "<<hh<<"\n";
//	assert(ret==hh);
	int mi=ret;
	l=mi,r=L,ret=mi;
	while (l<=r){
		int mid=(l+r>>1);
		if (chk(mi,mid)) r=mid-1,ret=mid;
		else l=mid+1;
	}
	chk(mi,ret);
	int mx=ret;
//	cerr<<mi<<" "<<mx<<"     hhh\n";
	int po=L;
	DF(i,n,2){
		int lp=po-mx,rp=po-mi;
		lp=max(lp,Lo[i-1]);
		rp=min(rp,Ro[i-1]);
		Ar[i]=po;
		Al[i]=lp;
		po=lp;
	}
	Al[1]=0; Ar[1]=po;
	F(i,1,n){
		cout<<Al[i]<<" "<<Ar[i]<<"\n";
	}
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen(".out","w",stdout);

	L=read(); n=read();
	F(i,1,n) a[i]=read();a[n+1]=L;
//	solve();
	work();
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/