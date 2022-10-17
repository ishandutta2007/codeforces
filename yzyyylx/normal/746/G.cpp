#include<bits/stdc++.h>
#define N 200005
using namespace std;

int k,n,cs,gs[N],first[N],from[N],mn=0,mx=1,sy,ans1[N],ans2[N],aa;

int main()
{
	int i,j;
	cin>>n>>cs>>k;
	cs++;
	for(i=2;i<=cs;i++)
	{
		scanf("%d",&gs[i]);
	}
	gs[1]=1;
	
	for(i=1;i<=cs;i++)
	{
		mx+=gs[i]-1;
		if(i>2)
			mn+=max(0,gs[i-1]-gs[i]);
	}
	mn+=gs[cs];
	
	if(k<mn||k>mx)
	{
		cout<<-1;
		return 0;
	}
	sy=mx-k;
//	cout<<mx<<mn<<sy;
	int last=1,dd=1;
	for(i=2;i<=cs;i++)
	{
		for(j=1;j<=gs[i];j++)
		{
			dd++;
			aa++;
			ans1[aa]=dd;
			ans2[aa]=last;
		}
		last+=gs[i-1];
	}
	/*
	for(i=1;i<=n-1;i++)
	{
		cout<<ans1[i]<<" "<<ans2[i]<<endl;
	}
	return 0;
	//*/
	last=gs[1]+gs[2];
	for(i=3;i<=cs;i++)
	{
		if(sy>=min(gs[i],gs[i-1])-1)
		{
			sy-=min(gs[i],gs[i-1])-1;
			for(j=1;j<=min(gs[i],gs[i-1])-1;j++)
			{
				ans1[last+j-1]=j+last-gs[i-1]+1;
				ans2[last+j-1]=j+last;
//				if(i==4) cout<<"Y"<<endl;
			}
		}
		else if(sy==0) break;
		else
		{
			for(j=1;j<=sy;j++)
			{
				ans1[last+j-1]=j+last-gs[i-1]+1;
				ans2[last+j-1]=j+last;
			}
			break;
		}
		last+=gs[i];
	}
	
	cout<<n<<endl;
	for(i=1;i<=n-1;i++)
	{
		cout<<ans1[i]<<" "<<ans2[i]<<endl;
	}
	return 0;
}