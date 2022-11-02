#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=105,INF=1e9;
int n;
pair <int,int> a[N];
int dp[N][N][2];
void ckmax(int &a,int b){
	if (a<b)
		a=b;
}
int main(){
	n=read();
	For(i,1,n)
		a[i].fi=read(),a[i].se=read();
	sort(a+1,a+n+1);
//	if (n==1)
//		return cout<<a[1].se<<endl,0;
	For(i,0,N-1)
		For(j,0,N-1)
			For(k,0,1)
				dp[i][j][k]=-INF;
	a[0].fi=-INF,a[0].se=0;
	dp[0][0][0]=0;
	int ans=-INF;
	For(i,0,n-1)
		For(j,0,i)
			For(k,0,1){
				int v=dp[i][j][k];
				if (v==-INF)
					continue;
//				printf("dp[%d][%d][%d] = %d\n",i,j,k,v);
				int rp=a[j].fi+k*a[j].se;
				{
					int tmp=v,R=rp;
					For(t,i+1,n){
						if (a[t].fi+a[t].se<=R)
							continue;
						tmp+=a[t].fi+a[t].se-max(R,a[t].fi);
						R=a[t].fi+a[t].se;
					}
					ckmax(ans,tmp);
				}
				pair <int,int> R=mp(j,k);
				For(t,i+1,n-1){
					int p=a[t].fi-a[t].se;
					if (a[R.fi].fi+R.se*a[R.fi].se<=a[t].fi)
						R=mp(t,0);
					if (p<=rp)
						ckmax(dp[t][R.fi][R.se],
							v+(a[R.fi].fi+R.se*a[R.fi].se-rp));
					else {
						int id=i+1;
						while (id<t&&a[id].fi+a[id].se<=rp)
							id++;
						int RR=rp,tmp=v;
						For(x,id,t-1){
							if (a[x].fi>=p)
								break;
							if (a[x].fi+a[x].se<=RR)
								continue;
							tmp+=a[x].fi+a[x].se-max(RR,a[x].fi);
							RR=a[x].fi+a[x].se;
						}
						tmp+=a[R.fi].fi+R.se*a[R.fi].se-max(RR,p);
						ckmax(dp[t][R.fi][R.se],tmp);
					}
					if (a[R.fi].fi+R.se*a[R.fi].se<=a[t].fi+a[t].se)
						R=mp(t,1);
				}
			}
	cout<<ans<<endl;
	return 0;
}