#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,a[N]={};
set<int> s;
void insert(int x)
{
	while(s.count(x))
	{
		s.erase(x);
		++x;
	}
	s.insert(x);
}
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=n;i>=1;--i)
		insert(a[i]);
	printf("%d\n",*s.rbegin()-s.size()+1);
	return 0;
}