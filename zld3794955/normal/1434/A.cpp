#include<bits/stdc++.h>
using namespace std;
const int D=6,N=100010;
int n,a[D]={},b[N]={},t[N]={};
pair<int,int> c[N*D];
int main()
{
	for(int i=0;i<D;++i)
		scanf("%d",a+i);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",b+i);
	int pos=0;
	for(int i=1;i<=n;++i)
		for(int j=0;j<D;++j)
		{
			++pos;
			c[pos].first=b[i]-a[j];
			c[pos].second=i;
		}
	sort(c+1,c+pos+1);
	int p=1, q=0, ans=c[pos].first-c[1].first;
	for(int i=1;i<=pos;++i)
	{
		if(t[c[i].second]==0)
			++q;
		++t[c[i].second];
		while(t[c[p].second]>1)
			--t[c[p++].second];
		if(q==n)
			ans=min(ans,c[i].first-c[p].first);
	}
	printf("%d\n",ans);
}