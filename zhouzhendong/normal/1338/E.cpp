#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
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
//int Pow(int x,int y){
//	int ans=1;
//	for (;y;y>>=1,x=(LL)x*x%mod)
//		if (y&1)
//			ans=(LL)ans*x%mod;
//	return ans;
//}
//void Add(int &x,int y){
//	if ((x+=y)>=mod)
//		x-=mod;
//}
//void Del(int &x,int y){
//	if ((x-=y)<0)
//		x+=mod;
//}
//int Add(int x){
//	return x>=mod?x-mod:x;
//}
//int Del(int x){
//	return x<0?x+mod:x;
//}
void ckmax(int &x,int y){
	if (x<y)
		x=y;
}
void ckmin(int &x,int y){
	if (x>y)
		x=y;
}
const int N=8005;
int n;
int g[N][N];
char s[N];
LL val=0;
int in[N];
int main(){
	n=read();
	For(i,0,n-1){
		scanf("%s",s);
		For(j,0,n/4-1){
			int v='0'<=s[j]&&s[j]<='9'?s[j]-'0':s[j]-'A'+10;
			For(t,0,3)
				g[i][j*4+(3-t)]=v>>t&1;
		}
		For(j,0,n-1)
			in[j]+=g[i][j];
	}
//	outarr(in,0,n-1);
	val=n*614;
	LL ans=0;
	{
		queue <int> q;
		For(i,0,n-1)
			if (!in[i])
				q.push(i);
		while (!q.empty()){
			int x=q.front();
			q.pop();
			For(i,0,n-1)
				if (g[x][i]){
					if (!--in[i])
						q.push(i);
				}
		}
	}
	int cnt=n;
	For(i,0,n-1)
		if (!in[i])
			ans+=(val+1)*--cnt;
	int x=-1;
	For(i,0,n-1)
		if (x==-1||in[i]>in[x])
			x=i;
	if (!in[x])
		return cout<<ans<<endl,0;
//	outval(x);
	vi P,Q;
	For(i,0,n-1)
		if (in[i]){
			if (i==x||g[i][x])
				P.pb(i);
			else
				Q.pb(i);
		}
	sort(P.begin(),P.end(),[&](int a,int b){
		return g[a][b];
	});
	sort(Q.begin(),Q.end(),[&](int a,int b){
		return g[a][b];
	});
//	outval(ans);
	ans+=3LL*P.size()*Q.size();
	ans+=1LL*P.size()*(P.size()-1)/2;
	ans+=1LL*Q.size()*(Q.size()-1)/2;
//	outval(ans);
	For(i,0,(int)P.size()-1)
		in[P[i]]-=i;
	For(i,0,(int)Q.size()-1)
		in[Q[i]]-=i;
	For(i,0,(int)P.size()-1)
		For(j,i+1,(int)P.size()-1)
			ans+=in[P[i]]==in[P[j]]?3LL:2LL;
	For(i,0,(int)Q.size()-1)
		For(j,i+1,(int)Q.size()-1)
			ans+=in[Q[i]]==in[Q[j]]?3LL:2LL;
	cout<<ans<<endl;
	return 0;
}