#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <cassert>
#include <functional>
#include <cmath>
#define SIZE 2005

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
typedef pair <P,int> PP;

PP st[SIZE];

bool down(PP p,PP q,PP r)//p.f<q.f<r.f
{
    P a=p.first,b=q.first,c=r.first;
    if(b.first==c.first) return true;
    if(a.first==b.first) return false;
    return (b.second-a.second)*(c.first-a.first)<(c.second-a.second)*(b.first-a.first);
}
bool up(PP p,PP q,PP r)//p.f<q.f<r.f
{
    P a=p.first,b=q.first,c=r.first;
    if(b.first==c.first) return false;
    if(a.first==b.first) return true;
    return (b.second-a.second)*(c.first-a.first)>(c.second-a.second)*(b.first-a.first);
}
vector <PP> convex_ids(vector <PP> vec)
{
    sort(vec.begin(),vec.end());
    int sz=0;
    for(int i=0;i<vec.size();i++)
    {
        while(sz>=2&&up(st[sz-2],st[sz-1],vec[i])) sz--;
        st[sz++]=vec[i];
    }
    int ls=sz;
    for(int i=((int) vec.size())-2;i>=0;i--)
    {
        while(sz>=ls+1&&down(vec[i],st[sz-1],st[sz-2])) sz--;
        st[sz++]=vec[i];
    }
    vector <PP> ret;
    for(int i=0;i<sz-1;i++) ret.push_back(st[i]);
    return ret;
}
char str[SIZE];
int main()
{
	int n;
	scanf("%d",&n);
    vector <PP> vec;
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        vec.push_back(PP(P(x,y),i));
    }
    scanf("%s",&str);
    vector <PP> now=convex_ids(vec);
    //for(int i=0;i<now.size();i++) printf("%d ",now[i].second);puts("");
    vector <int> ans;
    PP f=now[0];
    ans.push_back(f.second);
    for(int i=0;i<n-1;i++)
    {
        vector <PP> nxt;
        for(int j=0;j<vec.size();j++) if(vec[j]!=f) nxt.push_back(vec[j]);
        int pos=0;
        for(int j=0;j<now.size();j++)
        {
            if(now[j]==f)
            {
                pos=j;
            }
        }
        if(str[i]=='R')
        {
            f=now[(pos-1+now.size())%now.size()];
        }
        else
        {
            f=now[(pos+1)%now.size()];
        }
        ans.push_back(f.second);
        vec=nxt;
        now=convex_ids(vec);
        //for(int j=0;j<now.size();j++) printf("%d ",now[j].second);puts("");
    }
    for(int i=0;i<ans.size();i++) printf("%d ",ans[i]+1);
    puts("");
    return 0;
}