#include<bits/stdc++.h>
using namespace std;
const int K=12;
const int mod=1000000007;
int n,m,k,a[K][K]={},now[K][K]={},oc[K][K]={};
int tryy(int x,int y,int c)
{
	if(x>n)
		return 1;
	now[x][y]=now[x-1][y]|now[x][y-1];
	if(a[x][y])
	{
		if(now[x][y]&oc[x][y])
			return 0;
		now[x][y]|=1<<a[x][y];
		return y==m ? tryy(x+1,1,c) : tryy(x,y+1,c);
	}
	else
	{
		int s=0;
		for(int i=1;i<=c;++i)
		{
			if((now[x][y]|oc[x][y])&(1<<i))
				continue;
			now[x][y]^=1<<i;
			(s+=(y==m ? tryy(x+1,1,c) : tryy(x,y+1,c)))%=mod;
			now[x][y]^=1<<i;
		}
		if(c<k)
		{
			now[x][y]^=1<<(c+1);
			(s+=(k-c)*1ll*(y==m ? tryy(x+1,1,c+1) : tryy(x,y+1,c+1))%mod)%=mod;
			now[x][y]^=1<<(c+1);
		}
		return s;
	}
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		if(n+m-1>k)
		{
			puts("0");
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					scanf("%*d");
		}
		else
		{
			int c[K]={},totc=0; 
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
				{
					scanf("%d",&a[i][j]);
					if(a[i][j])
					{
						if(c[a[i][j]]==0)
							c[a[i][j]]=++totc;
						a[i][j]=c[a[i][j]];
					}
				}
			bool flag=false;
			for(int i=n;i>=1;--i)
				for(int j=m;j>=1;--j)
				{
					oc[i][j]=oc[i+1][j]|oc[i][j+1];
					if(a[i][j])
					{
						if(oc[i][j]&(1<<a[i][j]))
							flag=true;
						oc[i][j]|=1<<a[i][j];
					}
				}
			if(flag)
				puts("0");
			else
				printf("%d\n",tryy(1,1,totc));
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					now[i][j]=oc[i][j]=0;
		}
	}
}