#include<bits/stdc++.h>
#define maxn 200050
using namespace std;

const char *D="LRDU";
const int d[2]={-1,1};

int n,sx,sy;
char s[maxn];

int X,Y;
int R[maxn],C[maxn];

int chr(char c)
{
	for (int i=0;i<4;++i)
		if (D[i]==c)
			return i;
}

void init()
{
	scanf("%d%s%d%d",&n,s+1,&sx,&sy);
	for (int i=1;i<=n;++i)
	{
		R[i]=R[i-1],C[i]=C[i-1];
		int c=chr(s[i]);
		if (c<2)
			R[i]+=d[c];
		else
			C[i]+=d[c-2];
	}
	X=R[n],Y=C[n];
	
}

bool judge(int len)
{
	for (int i=0;i<n;++i)
	{
		int j=min(n,i+len);
		int x=X-(R[j]-R[i]),y=Y-(C[j]-C[i]);
		int d=abs(x-sx)+abs(y-sy);
		if (d<=j-i&&(j-i-d)%2==0)
			return 1;
	}
	return 0;
}

void solve()
{
	if (!judge(n))
		printf("-1\n");
	else
	{
		int l=0,r=n;
		while (l<r)
		{
			int mid=(l+r)>>1;
			if (judge(mid))
				r=mid;
			else
				l=mid+1;
		}
		printf("%d\n",l);
	}
}

int main()
{
	init();
	solve();		
	return 0;
}