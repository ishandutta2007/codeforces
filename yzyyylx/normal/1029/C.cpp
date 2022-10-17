#include<bits/stdc++.h>
#define fi first
#define se second
#define N 300100
using namespace std;

int n,ans,le[N],ri[N];
multiset<int>a,b;

int main()
{
	int i,j,p,q;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&p,&q);
		a.insert(p),b.insert(q);
		le[i]=p,ri[i]=q;
	}
	for(i=1;i<=n;i++)
	{
		a.erase(a.find(le[i]));
		b.erase(b.find(ri[i]));
		ans=max(ans,*b.begin()-*(--a.end()));
		a.insert(le[i]);
		b.insert(ri[i]);
	}
	cout<<ans;
}