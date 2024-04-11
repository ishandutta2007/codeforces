#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

typedef vector<int> vi;

int n,m;

vi a[N],pre[N],suf[N],dif[N];

int get(int x,int y,int z)
{
	if(z==-1)
		return pre[x][y-1]+suf[x][y+1];
	if(y>z)
		swap(y,z);
	return pre[x][y-1]+pre[x][z-1]-pre[x][y]+suf[x][z+1];		
}

int anspx,ansz;

int chk(int x,int y,int z,int px=-1)
{
	if(z!=-1&&px==-1)
		px=x;
	for(int i=2;i<=n;i++)
	{
		int d=get(i,y,z);
		d+=a[i][y]!=a[x][y];
		if(z!=-1)
			d+=a[i][z]!=a[px][z];
		if(d>2)
		{
			if(d==3&&z==-1)
			{
				for(auto t:dif[i])
					if(t!=y&&chk(x,y,t,i))
					{
						ansz=t,anspx=i;
						return 1;
					}
			}
			return 0;
		}
	}
	return 1;
}

void out(int x,int y,int z,int px=-1)
{
    puts("Yes");
	if(z!=-1&&px==-1)
		px=x;
	for(int i=1;i<=m;i++)
		if(i==y)
			printf("%d ",a[x][i]);
		else if(i==z)
			printf("%d ",a[px][i]);
		else
			printf("%d ",a[1][i]);
	puts("");
}

int main()
{
	int st=clock();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		a[i].resize(m+1);
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	}
	int mx=0;
	for(int i=2;i<=n;i++)
	{
		pre[i].resize(m+2);
		suf[i].resize(m+2);
		for(int j=1;j<=m;j++)
			pre[i][j]=pre[i][j-1]+(a[1][j]!=a[i][j]);
		for(int j=m;j>=1;j--)
			suf[i][j]=suf[i][j+1]+(a[1][j]!=a[i][j]);
		for(int j=1;j<=m;j++)
			if(a[i][j]!=a[1][j])
				dif[i].push_back(j);
		mx=max(mx,pre[i][m]);
	}
	if(mx<=2)
	{
		puts("Yes");
		for(int i=1;i<=m;i++)
			printf("%d%c",a[1][i]," \n"[i==m]);
		return 0;
	}
	if(mx>4)
	{
		puts("No");
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		if(dif[i].size()<=2)
			continue;
		if(dif[i].size()==3)
		{
			vector<int>v;
			for(int j=1;j<=m;j++)
				if(a[1][j]!=a[i][j])
					v.push_back(j);
			for(int t=0;t<v.size();t++)
			{
				if(chk(i,v[t],-1))
				{
					if(anspx)
						out(i,v[t],ansz,anspx);
					else
						out(i,v[t],-1);
					return 0;
				}
				for(int s=t+1;s<v.size();s++)
					if(chk(i,v[t],v[s]))
					{
						out(i,v[t],v[s]);
						return 0;
					}
			}
			continue;
		}
		else
		{
			vector<int>v;
			for(int j=1;j<=m;j++)
				if(a[i][j]!=a[1][j])
					v.push_back(j);
			for(int t=0;t<v.size();t++)
			{
				for(int s=t+1;s<v.size();s++)
					if(chk(i,v[t],v[s]))
					{
						out(i,v[t],v[s]);
						return 0;
					}
			}
			continue;
		}
	}
	puts("No");
}