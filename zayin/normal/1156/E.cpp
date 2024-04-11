#include<bits/stdc++.h>
#define maxn 200050
#define maxh 20
using namespace std;
typedef long long LL;

int n,a[maxn],pos[maxn];

int Log2[maxn]={-1};
int ST[maxn][maxh];

int Max(int i,int j)	{
	return a[i]>a[j]?i:j;
}

void init()	{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",a+i),pos[a[i]]=i;
	for (int i=1;i<=n;++i)	ST[i][0]=i,Log2[i]=Log2[i>>1]+1;
	for (int j=1;(1<<j)<=n;++j)
		for (int i=1;i+(1<<j)-1<=n;++i)
			ST[i][j]=Max(ST[i][j-1],ST[i+(1<<j-1)][j-1]);
}

int get(int l,int r)	{
	int t=Log2[r-l+1];
	return Max(ST[l][t],ST[r-(1<<t)+1][t]);
}

LL ans=0;

void solve(int l,int r)	{
	if (l>=r)	return ;
	int p=get(l,r);
	if (p-l<r-p)	{
		for (int i=l;i<p;++i)	{
			int c=a[p]-a[i];
			if (1<=c&&c<=n&&p<pos[c]&&pos[c]<=r)
				++ans;
		}
	} else	{
		for (int i=r;i>p;--i)	{
			int c=a[p]-a[i];
			if (1<=c&&c<=n&&l<=pos[c]&&pos[c]<p)
				++ans;
		}
	}
	solve(l,p-1);
	solve(p+1,r);
}

int main()	{
	init();
	solve(1,n);
	cout<<ans<<endl;
	return 0;
}