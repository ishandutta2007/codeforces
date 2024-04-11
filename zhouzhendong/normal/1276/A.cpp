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
template <class T> void ckmax(T &x,const T &y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,const T &y){
	if (x>y)
		x=y;
}
LL absl(LL x){
	return x<0?-x:x;
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
const int N=200005,INF=1e9;
int n;
char s[N];
int dp[N][5],las[N][5];
string s1="one",s2="two";
void gao(int i,int j,int k,int t){
	if (dp[i][j]>dp[i-1][k]+t){
		dp[i][j]=dp[i-1][k]+t;
		las[i][j]=k;
	}
}
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1)+1;
	s[n]='z';
	For(i,1,n)
		For(j,0,4)
			dp[i][j]=INF;
	dp[0][0]=0;
	vi f(300);
	f['o']=1;
	f['n']=1;
	f['e']=1;
	f['t']=1;
	f['w']=1;
	For(i,1,n){
		For(j,0,4){
			gao(i,j,j,1);
			if (f[s[i]]==0)
				gao(i,0,j,0);
			else {
				if (j==0){
					if (s[i]=='o'){
						gao(i,1,j,0);
					}
					else if (s[i]=='t'){
						gao(i,3,j,0);
					}
					else
						gao(i,0,j,0);
				}
				else if (j<=2){
					if (s[i]==s1[j]){
						if (j==2)
							continue;
						gao(i,j+1,j,0);
					}
					else if (s[i]=='o'){
						gao(i,1,j,0);
					}
					else if (s[i]=='t'){
						gao(i,3,j,0);
					}
					else 
						gao(i,0,j,0);
				}
				else {
					if (s[i]==s2[j-2]){
						if (j==4)
							continue;
						gao(i,j+1,j,0);
					}
					else if (s[i]=='o'){
						gao(i,1,j,0);
					}
					else if (s[i]=='t'){
						gao(i,3,j,0);
					}
					else 
						gao(i,0,j,0);
				}
			}
		}
////		outarr(dp[i],0,4);
	}
	vi pos;
	int mi=0;
	For(i,1,4)
		if (dp[n][i]<dp[n][mi])
			mi=i;
	Fod(i,n,1){
		int t=las[i][mi];
//		outval(t);
		if (dp[i-1][t]+1==dp[i][mi])
			pos.pb(i);
		mi=t;
	}
	printf("%d\n",(int)pos.size());
	for (auto i : pos)
		printf("%d ",i);
	puts("");
}
int main(){
	int T=read();
	while (T--)
		solve();
	return 0;
}