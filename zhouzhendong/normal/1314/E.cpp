#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
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
const int N=2025,mod=998244353;
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
int n,k;
namespace So1{
	int dp[N][N];
	int main(){
		dp[0][1]=1;
		For(i,0,n)
			For(j,1,n){
				Add(dp[i][j+1],dp[i][j]);
				if (i+j<=n)
					Add(dp[i+j][j],dp[i][j]);
			}
		int ans=0;
		For(i,1,n)
			Add(ans,dp[i][n]);
		cout<<ans<<endl;
		return 0;
	}
}
namespace So2{
	vector <int> dp[70][N];
	int main(){
		For(i,1,69)
			For(j,0,n)
				dp[i][j].resize(n/i+1);
		dp[1][0][n]=1;
		int ans=0;
		For(i,1,69)
			For(j,0,n){
				Fod(k,n/i,1){
					int v=dp[i][j][k];
					if (v){
						Add(dp[i][j][k-1],v);
						if (j+i*k<=n)
							Add(dp[i+1][j+i*k][min(n/(i+1),k)],v);
					}
				}
				if (j)
					Add(ans,dp[i][j][0]);
			}
		cout<<ans<<endl;
		return 0;
	}
}
namespace So3{
	int LIMIT;
	vi v,a;
	int ans=0,sum=0;
	int S(vi a){
		int ans=0;
		for (auto i : a)
			ans+=i;
		return ans;
	}
	vi trans(vi a){
		reverse(a.begin(),a.end());
		vi b;
		int c=0;
		for (auto i : a){
			c++;
			For(j,1,i)
				b.pb(c);
		}
		return b;
	}
	int check(){
		a=v;
		if (S(a)>LIMIT)
			return 0;
		For(_,1,k-3){
			a=trans(a);
			if (S(a)>LIMIT)
				return 0;
		}
		a=trans(a);
		int s=0,c=0;
		reverse(a.begin(),a.end());
		for (auto i : a)
			s+=i*(++c);
		return s<=n;
	}
	int dfs(int x,int k){
		if (k){
			if (!check())
				return 0;
			ans++;
		}
		if (sum+x>LIMIT)
			return 1;
		sum+=x;
		v.pb(x);
		int res=dfs(x,1);
		v.pop_back();
		sum-=x;
		if (res)
			dfs(x+1,0);
		return 1;
	}
	int main(){
		LIMIT=sqrt(n*2)+1;
		dfs(1,0);
		cout<<ans<<endl;
		return 0;
	}
}
int main(){
	n=read(),k=read();
	if (k==1)
		return So1::main();
	if (k==2)
		return So2::main();
	return So3::main();
	return 0;
}