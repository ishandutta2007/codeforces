#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 1e10
#define N 300100
using namespace std;

ll n,ans;
char str[3];
vector<ll>num[3];
vector<P>tmp;

int main()
{
    ll i,j,p,q,bm,bx,rm,rx,last,lb,lr,mb,mr;
    bool hb,hr;
    cin>>n;
    for(i=1;i<=n;i++)
    {
	scanf("%lld%s",&p,str);
	q=(str[0]=='G'?0:str[0]=='B'?1:2);
	num[q].push_back(p);
	tmp.push_back(mp(p,q));
    }
    sort(tmp.begin(),tmp.end());
    bm=INF,bx=-INF;
    rm=INF,rx=-INF;
    hb=hr=mb=mr=0;
    last=lb=lr=-1;
    for(i=0;i<tmp.size();i++)
    {
	if(!tmp[i].se)
	{
	    mb=max(mb,tmp[i].fi-lb);
	    mr=max(mr,tmp[i].fi-lr);
	    if(last==-1)
	    {
		if(hb) ans+=tmp[i].fi-bm;
		if(hr) ans+=tmp[i].fi-rm;
	    }
	    else
	    {
		ll t=0;
		if(hb) t+=min(bx-last,tmp[i].fi-bm);
		if(hr) t+=min(rx-last,tmp[i].fi-rm);
		ans+=2*(tmp[i].fi-last)+min(0ll,tmp[i].fi-last-mb-mr);
	    }
	    hb=hr=mb=mr=0;
	    bm=rm=INF,bx=rx=-INF;
	    lb=lr=last=tmp[i].fi;
	}
	else if(tmp[i].se==1)
	{
	    hb=1;
	    bm=min(bm,tmp[i].fi);
	    bx=max(bx,tmp[i].fi);
	    mb=max(tmp[i].fi-lb,mb);
	    lb=tmp[i].fi;
	}
	else
	{
	    hr=1;
	    rm=min(rm,tmp[i].fi);
	    rx=max(rx,tmp[i].fi);
	    mr=max(tmp[i].fi-lr,mr);
	    lr=tmp[i].fi;
	}
    }
    if(last==-1)
    {
	if(hb) ans+=bx-bm;
	if(hr) ans+=rx-rm;
    }
    else
    {
	if(hb) ans+=bx-last;
	if(hr) ans+=rx-last;
    }
    cout<<ans;
}