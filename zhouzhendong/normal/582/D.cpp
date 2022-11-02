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
const int N=3505,mod=1e9+7;
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
int n,m,p;
int a[N];
void geta(){
	string s;
	cin>>s;
	int len=s.size();
	static int x[N],y[N];
	For(i,1,len)
		x[i]=s[(int)s.size()-i]-'0';
	while (len){
		LL tmp=0;
		Fod(i,len,1){
			tmp=tmp*10+x[i];
			y[i]=tmp/p;
			tmp%=p;
		}
		a[++n]=tmp;
		For(i,1,len)
			x[i]=y[i];
		while (len>0&&!x[len])
			len--;
	}
}
int dp[N][N][2][2];
int cnt[N];
int calc(int x){
	return (LL)x*(x+1)/2%mod;
}
int calc(int x,int y){
	return Del(calc(y)-calc(x-1));
}
int calcs(int x){
	if (x<p)
		return x+1;
	else
		return p-1-(x-p);
}
int calcd(int x,int y){
	if (x>y)
		return 0;
	if (x<p&&y>=p)
		return Add(calcd(x,p-1)+calcd(p,y));
	if (y<p)
		return calc(calcs(x),calcs(y));
	else
		return calc(calcs(y),calcs(x));
}
int main(){
	p=read(),m=read();
	geta();
	reverse(a+1,a+n+1);
//	outarr(a,1,n);
	dp[0][0][1][0]=1;
	For(i,1,n)
		For(j,0,i)
			For(k,0,1)
				For(t,0,1){
					int v=dp[i-1][j][k][t];
					if (!v)
						continue;
//					printf("dp[%d][%d][%d][%d] = %d\n",i-1,j,k,t,v);
					For(nt,0,1){
						int s=(k?a[i]:p-1)+p*t-nt;
						if (s<0)
							continue;
						Add(dp[i][j+nt][k][nt],(LL)v*calcs(s)%mod);
						Add(dp[i][j+nt][0][nt],(LL)v*calcd(max(p*t-nt,0),s-1)%mod);
					}
				}
	int ans=0;
	For(i,m,n)
		For(j,0,1)
			Add(ans,dp[n][i][j][0]);
	cout<<ans<<endl;
	return 0;
}