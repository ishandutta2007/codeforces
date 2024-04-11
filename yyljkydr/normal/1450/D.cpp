#include<bits/stdc++.h>
using namespace std;
 
const int N=3e5+1e3+7;
 
int T,n,a[N],ans[N];
 
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		multiset<int>s;
		set<int>c;	
		for(int i=1;i<=n;i++)
			s.insert(a[i]),c.insert(a[i]);
		fill(ans+1,ans+n+1,0);
		if(*s.begin()==1)
			ans[n]=1;
		if(c.size()==n)
			ans[1]=1;
		int l=1,r=n;
		for(int i=1;i<n;i++)
		{
			s.erase(s.begin());
			if(s.count(i)!=0)
				break;
			if(a[l]==i)
				l++;
			else if(a[r]==i)
				r--;
			else
				break;
			if(*s.begin()!=i+1)
				break; 
			ans[n-i]=1;
		}
		for(int i=1;i<=n;i++)
			printf("%d",ans[i]);
		puts("");	
	}
}