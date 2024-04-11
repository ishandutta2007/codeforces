#include<bits/stdc++.h>
using namespace std;
 
const int N=23;
 
int n,x,y;
 
int f[2][(1<<N)+7],w[N*2];
 
int main()
{
	scanf("%d",&n);
	scanf("%d%d",&x,&y);
	if(x<y)
		swap(x,y); 
	int p=x+y;
	for(int i=0;i<p;i++)
		w[i]=(n/p)+(i<n%p);
	int all=(1<<x)-1;
	for(int i=0;i<2;i++)
		for(int S=0;S<=all;S++)
			f[i][S]=-1e9;
	f[0][0]=0;
	f[0][1]=w[0];
	for(int i=0;i<p-1;i++)
	{
		for(int S=0;S<=all;S++)
			f[(i+1)&1][S]=-1e9;
		for(int S=0;S<=all;S++)
		if(f[i&1][S]>=0)
		{
			if((i+1<y||(S&(1<<y-1))==0)&&(i+1<x||(S&(1<<x-1))==0))
				f[(i+1)&1][((S<<1)&all)|1]=max(f[(i+1)&1][((S<<1)&all)|1],f[i&1][S]+w[i+1]);
			f[(i+1)&1][(S<<1)&all]=max(f[(i+1)&1][(S<<1)&all],f[i&1][S]);
		}
	}
	int ans=0;
	for(int S=0;S<=all;S++)
		ans=max(ans,f[(p-1)&1][S]);
	printf("%d\n",ans);
}