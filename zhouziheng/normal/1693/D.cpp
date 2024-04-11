#include<cstdio>
#include<algorithm>
#include<vector>
 
using namespace std;
 
int p[300000];vector<int> maxs,mins;
int preb[300000],nxtb[300000],ansr[300000],upr[300000],downr[300000];
 
int main()
{
	int n=0;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	
	for(int i=1,lst=0;i<n;i++)
	{
		while(!maxs.empty()&&p[maxs.back()]<p[i]){if(maxs.back()!=i-1)lst=max(lst,maxs.back());maxs.pop_back();}
		while(!mins.empty()&&p[mins.back()]>p[i]){if(mins.back()!=i-1)lst=max(lst,mins.back());mins.pop_back();}
		maxs.push_back(i),mins.push_back(i);
		//printf("%d\n",lst);
		if(p[i+1]>p[i])
		{
			if(maxs.size()>=2&&p[maxs[maxs.size()-2]]<p[i+1])
			{
				preb[i]=max(lst,maxs[maxs.size()-2])+1;
			}
			else preb[i]=lst+1;
		}
		else
		{
			if(mins.size()>=2&&p[mins[mins.size()-2]]>p[i+1])
			{
				preb[i]=max(lst,mins[mins.size()-2])+1;
			}
			else preb[i]=lst+1;
		}
	}
	//for(int i=1;i<=n;i++)printf("%d ",preb[i]);puts("");
	maxs.clear();mins.clear();
	
	for(int i=n,lst=n+1;i>=2;i--)
	{
		while(!maxs.empty()&&p[maxs.back()]<p[i]){if(maxs.back()!=i+1)lst=min(lst,maxs.back());maxs.pop_back();}
		while(!mins.empty()&&p[mins.back()]>p[i]){if(mins.back()!=i+1)lst=min(lst,mins.back());mins.pop_back();}
		maxs.push_back(i),mins.push_back(i);
		if(p[i-1]>p[i])
		{
			if(maxs.size()>=2&&p[maxs[maxs.size()-2]]<p[i-1])
			{
				nxtb[i]=min(lst,maxs[maxs.size()-2])-1;
			}
			else nxtb[i]=lst-1;
		}
		else
		{
			if(mins.size()>=2&&p[mins[mins.size()-2]]>p[i-1])
			{
				nxtb[i]=min(lst,mins[mins.size()-2])-1;
			}
			else nxtb[i]=lst-1;
		}
	}
	//for(int i=1;i<=n;i++)printf("%d ",preb[i]);puts("");
	//for(int i=1;i<=n;i++)printf("%d ",nxtb[i]);puts("");
	
	for(int i=1;i<=n;i++)ansr[i]=i;
	upr[n]=downr[n]=n;for(int i=n-1;i>=1;i--)if(p[i]<p[i+1])upr[i]=upr[i+1],downr[i]=i;else upr[i]=i,downr[i]=downr[i+1];
	for(int i=1;i<n;i++)
	{
		int l=preb[i],r=i+1;
		if(i+1<n)
		{
			
			if(p[i]>p[i+1])
			{
				int t=upr[i+1];r=max(r,t);
				if(t==n)r=n;
				else if(p[t+1]<p[i])r=max(r,nxtb[t+1]);
			}
			else
			{
				int t=downr[i+1];r=max(r,t);
				if(t==n)r=n;
				else if(p[t+1]>p[i])r=max(r,nxtb[t+1]);
			}
		}
		ansr[l]=max(ansr[l],r);
	}
	//for(int i=1;i<=n;i++)printf("%d ",ansr[i]);puts("");
	for(int i=2;i<=n;i++)ansr[i]=max(ansr[i],ansr[i-1]);
	long long ans=0;for(int i=1;i<=n;i++)ans+=(ansr[i]-i+1);
	printf("%lld",ans);
}