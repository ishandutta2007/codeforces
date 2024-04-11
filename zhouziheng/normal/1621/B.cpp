#include<cstdio>
#include<map>

using namespace std;

int l[200000],r[200000],c[200000];
map<pair<int,int>,int> mp;map<int,int> L,R;

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&l[i],&r[i],&c[i]);
		mp.clear(),L.clear(),R.clear();
		
		int ll=l[1],rr=r[1];
		for(int i=1;i<=n;i++)
		{
			ll=min(ll,l[i]),rr=max(rr,r[i]);
			if(mp[make_pair(l[i],r[i])]==0||mp[make_pair(l[i],r[i])]>c[i])
				mp[make_pair(l[i],r[i])]=c[i];
			if(L[l[i]]==0||L[l[i]]>c[i])L[l[i]]=c[i];
			if(R[r[i]]==0||R[r[i]]>c[i])R[r[i]]=c[i];
			int ans=L[ll]+R[rr];
			//printf("%d %d %d %d %d\n",ll,rr,L[ll],R[rr],ans);
			if(mp[make_pair(ll,rr)]>0)ans=min(ans,mp[make_pair(ll,rr)]);
			printf("%d\n",ans);
		}
	}
}