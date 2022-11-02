#include<bits/stdc++.h>
using namespace std;
const int N=100010,V=100010;
int n,a[N]={},t[V]={},f[N]={};
vector<int> d[V];
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=2;i<=a[n];++i)
		for(int j=i;j<=a[n];j+=i)
			d[j].push_back(i);
	for(int i=1;i<=n;++i)
	{
		for(auto p:d[a[i]])
			f[i]=max(f[i],t[p]);
		++f[i];
		for(auto p:d[a[i]])
			t[p]=max(t[p],f[i]);
	}
	printf("%d\n",*max_element(f+1,f+n+1));
	return 0;
}