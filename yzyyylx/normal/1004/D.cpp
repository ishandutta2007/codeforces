#include<bits/stdc++.h>
#define N 1001000
using namespace std;

int n,cnt[N],tmp[N],mx,jj;

inline void pd(int u,int v,int x,int y)
{
	int i,j;
	if(x<=0||x>u||y<=0||y>v) return;
//	if(u==4&&v==5) cout<<x<<" "<<y<<endl;
	memset(tmp,0,sizeof(tmp));
	for(i=1;i<=u;i++)
	{
		for(j=1;j<=v;j++)
		{
			tmp[abs(i-x)+abs(j-y)]++;
		}
	}
	for(i=1;i<=mx;i++) if(tmp[i]!=cnt[i]) return;
	printf("%d %d\n%d %d\n",u,v,x,y);
	exit(0);
}

int main()
{
	int i,j,p,q;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p);
		cnt[p]++;
		mx=max(mx,p);
	}
	if(cnt[0]!=1)
	{
		puts("-1");
		return 0;
	}
	for(i=1;;i++) if(cnt[i]!=i*4) break;
	jj=i;
	for(i=1;i*i<=n;i++)
	{
		if(n%i) continue;
		pd(i,n/i,jj,i+n/i-mx-jj);
		pd(i,n/i,i+n/i-mx-jj,jj);
	}
	puts("-1");
}