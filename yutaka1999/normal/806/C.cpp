#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#define SIZE 100005
#define BT 50
#define BB 1024*128*2
#define INF 1000000000

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct segtree
{
	int seg[BB];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=-INF;
	}
	int get(int k)
	{
		k+=mum-1;
		int ret=seg[k];
		while(k>0)
		{
			k=(k-1)/2;
			ret=max(ret,seg[k]);
		}
		return ret;
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) seg[k]=max(seg[k],v);
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
		}
	}
	void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
};
segtree seg;
int cnt[BT],kt[SIZE];
int dp[BT][SIZE];
int nxt[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		ll a;
		scanf("%lld",&a);
		int nm=0;
		while((1LL<<nm)<a) nm++;
		if(a==(1LL<<nm)) cnt[nm]++;
		else kt[nm-1]++;
	}
	//for(int i=0;i<5;i++) printf("%d %d\n",cnt[i],kt[i]);
	memset(dp,-1,sizeof(dp));
	dp[BT-1][0]=0;
	for(int i=BT-2;i>=0;i--)
	{
		//cnt[i] 2
		seg.init(n+2);
		for(int j=0;j<=n;j++)
		{
			if(dp[i+1][j]==-1) continue;
			if(j>cnt[i]) continue;//j<=cnt[i]
			int zan=cnt[i]-j;//]12xg or g
			//a+b=zan Adp[i][j+a]=max(dp[i][j+a],dp[i+1][j]+a-b)  . b=zan-a
			//dp[i][j+a]=max(dp[i][j+a],dp[i+1][j]+2a-zan) ( 0<=a<=zan )
			//dp[i][j+a]-2*(j+a) = max(dp[i][j+a]-2*(j+a),dp[i+1][j]-2*j -zan) <- segtree
			seg.update(j,j+zan+1,dp[i+1][j]-2*j-zan);
		}
		memset(nxt,-1,sizeof(nxt));
		//printf("%d : ",i);
		for(int j=0;j<=n;j++)
		{
			int gt=seg.get(j);
			dp[i][j]=max(dp[i][j],gt+2*j-kt[i]);
			//if(dp[i][j]!=-1) printf("[%d %d]",j,dp[i][j]);
		}
		//puts("");
	}
	vector <int> vec;
	for(int i=0;i<=n;i++) if(dp[0][i]!=-1) vec.push_back(i);
	if(vec.empty()) puts("-1");
	else
	{
		for(int i=0;i<vec.size();i++)
		{
			if(i!=0) printf(" ");
			printf("%d",vec[i]);
		}puts("");
	}
	return 0;
}