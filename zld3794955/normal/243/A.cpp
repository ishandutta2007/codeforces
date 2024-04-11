#include<bits/stdc++.h>
using namespace std;
const int N=100010,D=20;
int n,a[N]={},last[D+1]={};
vector<int> s;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		if(a[i]==0)
			s.push_back(0);
		for(int d=0;d<=D;++d)
			if(a[i]&(1<<d))
				last[d]=i;
		int v[D+1]={},tmp=0;
		copy(last,last+D+1,v);
		sort(v,v+D+1);
		for(int j=D;j>=0 && v[j];--j)
		{
			for(int k=0;k<=D;++k)
				if(last[k]==v[j])
					tmp|=(1<<k);
			s.push_back(tmp);
		}
	}
	sort(s.begin(),s.end());
	s.erase(unique(s.begin(),s.end()),s.end());
	printf("%u\n",s.size());
	return 0;
}