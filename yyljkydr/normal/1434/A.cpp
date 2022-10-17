#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=1e9+7;

int a[N],b[N];

int T,n,m,cnt[N],ct;

struct D{
	int i,j,k;
};

bool cmp(D a,D b)
{
	return a.k<b.k;
}

vector<D>v;

bool chk(int w)
{
	for(int i=1;i<=n;i++)
		cnt[i]=0;
	ct=0;
	for(int l=0,r=0;r<v.size();r++)
	{
		if(!cnt[v[r].i])
			ct++;
		cnt[v[r].i]++;
		while(v[r].k-v[l].k>w)
		{
			cnt[v[l].i]--;
			if(!cnt[v[l].i])
				ct--;
			l++;
		}
		if(ct==n)
			return 1;
	}
	return 0;
}

int main()
{
	m=6;
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
			v.push_back(D{i,j,b[i]-a[j]});
	sort(v.begin(),v.end(),cmp);
	int ans=2e9;
	int l=-1,r=1e9;
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		if(chk(mid))
			r=mid;
		else
			l=mid;
	}
	printf("%d\n",r);
}