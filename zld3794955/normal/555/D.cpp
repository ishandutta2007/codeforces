#include<bits/stdc++.h>
using namespace std;
const int N=200020,M=200020;
int n,m,x[N]={},num[N]={};
pair<int,int> tmp[N];
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x[i]);
		tmp[i]={x[i],i};
	}
	sort(tmp+1,tmp+n+1);
	for(int i=1;i<=n;++i)
		x[i]=tmp[i].first, num[i]=tmp[i].second;
	for(int i=1;i<=n;++i)
	{
		swap(tmp[i].first,tmp[i].second);
		tmp[i].second=i;
	}
	sort(tmp+1,tmp+n+1);
}
void work()
{
	int a,l;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&a,&l);
		a=tmp[a].second;
		int dir=1,last[4]={};
		last[3]=a;
		for(;;dir=!dir)
		{
			//cout<<"a="<<a<<" l="<<l<<endl;
			for(int j=0;j<3;++j)
				last[j]=last[j+1];
			int d=0;
			if(dir)
			{
				int p=upper_bound(x+1,x+n+1,x[a]+l)-x-1;
				d=x[p]-x[a];
				l-=d;
				a=last[3]=p;
			}
			else
			{
				int p=lower_bound(x+1,x+n+1,x[a]-l)-x;
				d=x[a]-x[p];
				l-=d;
				a=last[3]=p;
			}
			if(last[0]==last[2] && last[1]==last[3])
			{
				if(last[0]==last[1])
					break;
				int c=l/d;
				l%=d;
				dir^=(c%2);
				a=last[3]=last[3-c%2];
				last[0]=last[1]=last[2]=0;
			}
		}
		printf("%d\n",num[a]);
	}
}
int main()
{	
	init();
	work();
	return 0;
}