#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n,a[N],l[N];

vector<int>v;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		v.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&l[i]);
			if(!l[i])
				v.push_back(a[i]);
		}
		sort(v.begin(),v.end());
		for(int i=1;i<=n;i++)
			if(!l[i])
				a[i]=v.back(),v.pop_back();
		for(int i=1;i<=n;i++)
			printf("%d%c",a[i]," \n"[i==n]);
	}
}