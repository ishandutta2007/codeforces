#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x.size())
#define pb push_back
#define PII pair<int,int>
#define ll long long
#define gc getchar()
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=1e6+5;
int n,a[maxn],m;
int dp[maxn][3][3];
int sum[maxn]; 
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)a[i]=gi(),sum[a[i]]++;
} 
inline void solve()
{
	dp[0][0][0]=0;
	FOR(i,1,m)
	{
		FOR(j,0,2)
		{
			FOR(k,0,2)
			{
				FOR(l,0,2)
				{
					if(j+k+l>sum[i])continue;
					dp[i][k][l]=max(dp[i][k][l],dp[i-1][j][k]+(sum[i]-j-k-l)/3+l);
				}
			}
		}
	}
	printf("%d\n",dp[m][0][0]);
}
int main()
{
	input();
	solve();
	return 0;
}