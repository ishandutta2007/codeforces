#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int T,n;

ll t[N],x[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ll pos=0,dir=0,des=0;
		int ans=0;
		t[n+1]=1e15;
		for(int i=1;i<=n;i++)
			scanf("%lld%lld",&t[i],&x[i]);
		for(int i=1;i<=n;i++)
		{
			if(pos==des)
			{
				if(x[i]!=pos)
					dir=(x[i]-pos)/abs(x[i]-pos);
				else
					dir=0;
				des=x[i];
			}
			ll dis=min(t[i+1]-t[i],abs(des-pos));
			ll L=min(pos,pos+dis*dir),R=max(pos,pos+dis*dir);
			if(L<=x[i]&&x[i]<=R)
				ans++;
			pos=pos+dis*dir;
		}	
		printf("%d\n",ans);
	}
}