#include<bits/stdc++.h>
using namespace std;

const int N=111;

int n,k,c[N*N];

int p[N][N],r[N];

int ki;

bool cmp(int a,int b)
{
	return p[a][ki]<p[b][ki];
}

int L[N],R[N];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n*k;i++)
		scanf("%d",&c[i]),p[c[i]][++p[c[i]][0]]=i;
	for(int i=1;i<=n;i++)
		r[i]=i;
	int lim=(n+k-2)/(k-1);
	for(int i=2;i<=k;i++)
	{
		ki=i;
		sort(r+1,r+n+1,cmp);
		int tot=0;
		for(int j=1;j<=n;j++)
		{
			int x=r[j];
			if(L[x]||tot==lim)
				continue;
			tot++;
			L[x]=p[x][i-1],R[x]=p[x][i];
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d %d\n",L[i],R[i]);
}