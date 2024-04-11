#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=3e5+1e3+7;

int q,anc[N][21];

ll a[N],c[N];

int main()
{
	scanf("%d%lld%lld",&q,&a[1],&c[1]);
	for(int x=2;x<=q+1;x++)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%lld%lld",&anc[x][0],&a[x],&c[x]);
			anc[x][0]++;
			for(int j=1;j<=20;j++)
				anc[x][j]=anc[anc[x][j-1]][j-1];
		}
		else
		{
			ll v,w;
			scanf("%lld%lld",&v,&w);
			v++;
			ll sa=0,sc=0;
			while(a[v]&&w)
			{
				int p=v;
				for(int j=20;j>=0;j--)
					if(a[anc[p][j]])
						p=anc[p][j];
				ll val=min(a[p],w);
				a[p]-=val;
				w-=val;
				sa+=val;
				sc+=c[p]*val;
			}
			printf("%lld %lld\n",sa,sc);
			fflush(stdout);
		}
	}
}