#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#define N 400100
using namespace std;

int n,num[N],b[N],pos[N],mx[N],ans,an,last[N],tmp[N];
map<int,int>mm;

int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		b[i]=num[i];
	}
	sort(b+1,b+n+1);
	for(i=1,j=0;i<=n;i++)
	{
		if(i==1||b[i]!=b[i-1])
		{
			if(b[i]-b[i-1]>1) ++j;
			mm[b[i]]=++j;
		}
	}
	for(i=1;i<=n;i++) num[i]=mm[num[i]];
	for(i=1;i<=n;i++)
	{
		mx[num[i]]=mx[num[i]-1]+1;
		pos[num[i]]=i;
		last[i]=pos[num[i]-1];
		if(mx[num[i]]>ans)
		{
			ans=mx[num[i]];
			an=i;
		}
	}
	cout<<ans<<endl;
	for(i=an,j=1;i;j++,i=last[i])
	{
		tmp[j]=i;
	}
	for(j--;j;j--)
	{
		printf("%d ",tmp[j]);
	}
}