#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp  make_pair
#define fi first
#define se second
#define eps 1e-8
#define N 300100
using namespace std;

ll n,m,top,tot,B,S;
P sta[N];

inline db calc(P u,P v){return (db)(u.se-v.se)/(db)(v.fi-u.fi);}
inline bool cmp(P u,P v){return (u.fi-1)*S+u.se<=(v.fi-1)*S+v.se;}
int main()
{
    ll i,j,o,p,q;
    cin>>n>>m;
    tot=n;
    sta[++top]=mp(1,0);
    while(m--)
    {
	scanf("%lld",&o);
	if(o==1)
	{
	    scanf("%lld",&p);
	    tot+=p,B=S=0;
	    sta[top=1]=mp(1,0);
	}
	else if(o==2)
	{
	    scanf("%lld",&p);
	    P tmp=mp(tot+1,-B-tot*S);
	    for(;top>1&&calc(tmp,sta[top])+eps>calc(sta[top],sta[top-1]);top--);
	    sta[++top]=tmp;
	    tot+=p;
	}
	else
	{
	    scanf("%lld%lld",&p,&q);
	    B+=p,S+=q;
	}
	for(;top>1&&cmp(sta[top-1],sta[top]);top--);
//	cout<<sta[top-1].fi<<" "<<sta[top-1].se<<"  "<<sta[top].fi<<" "<<sta[top].se<<"   "<<S<<" "<<B<<endl;
	printf("%lld %lld\n",sta[top].fi,(sta[top].fi-1)*S+sta[top].se+B);
    }
}