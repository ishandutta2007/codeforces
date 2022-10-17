#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n;

set<int>s;

int main()
{
	scanf("%d",&n);
	int ans=1;
	for(int i=1;i<n;i++)
		if(__gcd(i,n)==1)
			s.insert(i),ans=1ll*ans*i%n;
	if(ans!=1)
	{
		assert(s.find(ans)!=s.end());
		s.erase(ans);
	}
	printf("%d\n",s.size());
	for(auto x:s)
		printf("%d ",x);
}