#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N=2e5+1e3+7;

int T,n;

ll s;

int l[N],r[N];

vector<int>vl,vr,v;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&s);
		vl.clear(),vr.clear();
		for(int i=1;i<=n;i++)
			scanf("%d%d",&l[i],&r[i]),vl.push_back(l[i]),vr.push_back(r[i]);
		sort(vl.begin(),vl.end());
		sort(vr.begin(),vr.end());
		int md=n/2;
		int L=vl[md],R=vr[md]+1;
		while(R-L>1)
		{
			v.clear();
			int mid=(L+R)>>1;
			ll now=0;
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(l[i]>mid&&cnt<n/2)
					now+=l[i],cnt++;
			for(int i=1;i<=n;i++)
				if(l[i]<=mid&&mid<=r[i])
					v.push_back(l[i]);
			sort(v.begin(),v.end());
			for(int i=(int)v.size()-1;i>=0;i--)
			{
				if(cnt<n/2+1)
					now+=mid,cnt++;
				else
					now+=v[i];
			}
			for(int i=1;i<=n;i++)
				if(r[i]<mid)
					now+=l[i];
			if(now<=s)
				L=mid;
			else
				R=mid;
		}
		printf("%d\n",L);
	}
}