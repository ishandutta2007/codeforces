#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,m,k;

int x[N],y[N];

vector<int>s[N],t[N];

int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int bor[4];

int xnow,ynow,flg[N];

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&x[i],&y[i]),s[x[i]].push_back(y[i]),t[y[i]].push_back(x[i]);
		if(y[i]==1)
			flg[x[i]]=1;
	}
	int now=1,num=0;
	while(now<=n)
	{
		if(flg[now])
			break;
		num++;
		now++;
	}
	if(num==1ll*n*m-k)
	{
		puts("Yes");
		return 0;
	}
	for(int i=1;i<=n;i++)
		s[i].push_back(0),s[i].push_back(m+1),sort(s[i].begin(),s[i].end());
	for(int i=1;i<=m;i++)
		t[i].push_back(0),t[i].push_back(n+1),sort(t[i].begin(),t[i].end());
	bor[0]=m+1,bor[1]=n+1,bor[2]=0,bor[3]=1;
	int dir=3;
	xnow=ynow=1;
	long long tot=1;
	while(1)
	{
		dir=(dir+1)%4;
		if(dir==0)
		{
			int pos=lower_bound(s[xnow].begin(),s[xnow].end(),ynow)-s[xnow].begin();
			int to=min(s[xnow][pos],bor[dir]);
			if(to==ynow+1)
				break;
			tot+=to-ynow-1;
			bor[dir]=to-1;
			ynow=to-1;
		}
		if(dir==1)
		{
			int pos=lower_bound(t[ynow].begin(),t[ynow].end(),xnow)-t[ynow].begin();
			int to=min(t[ynow][pos],bor[dir]);
			if(to==xnow+1)
				break;
			tot+=to-xnow-1;
			bor[dir]=to-1;
			xnow=to-1;
		}
		if(dir==2)
		{
			int pos=lower_bound(s[xnow].begin(),s[xnow].end(),ynow)-s[xnow].begin()-1;
			int to=max(s[xnow][pos],bor[dir]);
			if(to==ynow-1)
				break;
			tot+=ynow-to-1;
			bor[dir]=to+1;
			ynow=to+1;
		}
		if(dir==3)
		{
			int pos=lower_bound(t[ynow].begin(),t[ynow].end(),xnow)-t[ynow].begin()-1;
			int to=max(t[ynow][pos],bor[dir]);
			if(to==xnow-1)
				break;
			tot+=xnow-to-1;
			bor[dir]=to+1;
			xnow=to+1;
		}
	}
	if(tot==1ll*n*m-k)
		puts("Yes");
	else
		puts("No");
}