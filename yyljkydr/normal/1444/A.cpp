#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

typedef long long ll;

ll p,q;

int T;

vector<int>v;

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>p>>q;
		v.clear();
		int x=q;
		for(int i=2;i*i<=x;i++)
			if(x%i==0)
			{
				v.push_back(i);
				while(x%i==0)
					x/=i;
			}
		if(x!=1)
			v.push_back(x);
		ll ans=0;
		for(auto w:v)
		{
			ll y=p;
			while(y%q==0)
				y/=w;
			ans=max(ans,y);
		}
		cout<<ans<<endl;
	}
}