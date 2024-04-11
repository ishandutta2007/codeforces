#include<bits/stdc++.h>
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
using namespace std;

int n,Q,ans;
struct Zt
{
    int l,r;
    bool num;
    bool operator < (const Zt &u) const{if(l!=u.l) return l<u.l;return r<u.r;}
};
set<Zt>se;
set<Zt>::iterator it;
vector<set<Zt>::iterator>cle;

inline void cut(int u)
{
//    cerr<<" "<<u<<endl;
    it=se.upper_bound((Zt){u,INF,0});it--;
    Zt tmp=(*it);
    se.erase(it);
    se.insert((Zt){tmp.l,u,tmp.num});
    if(u<tmp.r) se.insert((Zt){u+1,tmp.r,tmp.num});
//    cerr<<u<<endl;
}

int main()
{
    int i,j,p,q,o;
    cin>>n>>Q;
    ans=n;
    se.insert((Zt){1,n,0});
    for(i=1;i<=Q;i++)
    {
	scanf("%d%d%d",&p,&q,&o);
	if(p>1) cut(p-1);cut(q);
	it=se.upper_bound((Zt){p,INF,0});it--;
	cle.clear();
	for(;it!=se.end()&&(*it).r<=q;it++)
	{
	    cle.push_back(it);
	    Zt tmp=(*it);
	    if(o==1&&!tmp.num) ans-=tmp.r-tmp.l+1;
	    if(o==2&&tmp.num) ans+=tmp.r-tmp.l+1;
	}
	for(j=0;j<cle.size();j++) se.erase(cle[j]);
	se.insert((Zt){p,q,o==1});
	printf("%d\n",ans);
    }
}