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
const int maxn=1005;
int n,k;
inline void input()
{
	n=gi(),k=gi();
}
vector<int>v[maxn];
int col[maxn][maxn];
inline void solve()
{
	FOR(i,1,n)v[i].pb(i);
	int cnt=n,t=0;
	while(cnt!=1)
	{
		t++;
		vector<int>v2[maxn];
		FOR(j,1,cnt)
		{
			for(int x:v[j])v2[(j-1)/k+1].pb(x);
		}
		FOR(i,1,cnt)
		{
			FOR(j,i+1,cnt)
			{
				if((i-1)/k==(j-1)/k)
				{
					for(int x:v[i])for(int y:v[j])
					{
						col[x][y]=t;	
					} 
				}
			}
		}
		cnt=(cnt-1)/k+1;
		FOR(i,1,cnt)v[i]=v2[i];
	}
	printf("%d\n",t);
	FOR(i,1,n)FOR(j,i+1,n)printf("%d ",col[i][j]);
	puts("");
}
int main()
{
	input();
	solve();
	return 0;
}