#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,a[N]={};
multiset<int> s;
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n*n;++i)
	{
		scanf("%d",&x);
		s.insert(x);
	}
	for(int i=1;i<=n;++i)
	{
		a[i]=*s.rbegin();
		s.erase(s.find(a[i]));
		for(int j=1;j<i;++j)
			s.erase(s.find(__gcd(a[j],a[i]))),s.erase(s.find(__gcd(a[j],a[i])));
	}
	for(int i=1;i<=n;++i)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}