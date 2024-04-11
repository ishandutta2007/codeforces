#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,q;

int pl[N],pr[N],val[N],sl[N],sr[N],sv[N];

int a[N];

char s[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='+')
				a[i]=1;
			else
				a[i]=-1;
		}
		sl[n+1]=0,sr[n+1]=0,sv[n+1]=0;
		pl[0]=0,pr[0]=0;
		for(int i=1;i<=n;i++)
		{
			val[i]=val[i-1]+a[i];
			pl[i]=min(pl[i-1],val[i]);
			pr[i]=max(pr[i-1],val[i]);
		}
		int s=0;
		for(int i=n;i>=1;i--)
		{
			sl[i]=min(sl[i+1],s);
			sr[i]=max(sr[i+1],s);
			sv[i]=s;
			s-=a[i];
		}
		while(q--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			int L=pl[l-1],R=pr[l-1];
			int s=val[l-1]-sv[r];
			L=min(L,s+sl[r]),R=max(R,s+sr[r]);
			printf("%d\n",R-L+1);
		}
	}
}