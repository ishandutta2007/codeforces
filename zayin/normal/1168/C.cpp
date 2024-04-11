#include<bits/stdc++.h>
#define maxh 21
#define maxn 300050
using namespace std;

int n,m;

int a[maxn];

int pos[maxh];
int T[maxn][maxh];

int init()	{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%d",a+i);
}


void solve()	{
	memset(T,0x3f,sizeof(T));
	for (int i=n;i;--i)	{
		for (int b=0;b<maxh;++b)	{
			if (~a[i]>>b&1)	continue;
			T[i][b]=i;
			int k=pos[b];
			pos[b]=i;
			if (!k)	continue;
//			cout<<i<<" "<<b<<" "<<k<<endl;
			for (int j=0;j<maxh;++j)
				T[i][j]=min(T[i][j],T[k][j]);
		}
		/*cout<<i<<":";
		for (int b=0;b<2;++b)
			cout<<T[i][b]<<" ";
		cout<<endl;*/
	}
	
	while(m--)	{
		int l,r;
		scanf("%d%d",&l,&r);
		
		bool flag=0;
		for (int j=0;j<maxh;++j)
			if (T[l][j]<=r&&(a[r]>>j&1))
				flag=1;
		puts(flag?"Shi":"Fou");
	}
}

int main()	{
	init();
	solve();
	return 0;
}