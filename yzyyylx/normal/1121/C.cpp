#include<bits/stdc++.h>
#define db double
#define N 1010
using namespace std;

int n,m,ans,ok,now,num[N],pos[N],use[N];
vector<int>gg;
set<int>pc;
set<int>::iterator it;

int main()
{
    int i,j,p,q;
    cin>>n>>m;
    for(i=1;i<=n;i++) scanf("%d",&num[i]);
    for(q=1,p=0,j=1;;j++)
    {
	now=(int)(100.0*(db)ok/(db)n+0.5);
	for(;q<=n&&p<m;p++,q++) pc.insert(q);
	if(!pc.size()) break;
	for(it=pc.begin();it!=pc.end();it++)
	{
	    pos[*it]++;
	    if(now==pos[*it]&&!use[*it]) ans++,use[*it]=1;
	}
	for(it=pc.begin();it!=pc.end();it++)
	{
	    if(pos[*it]==num[*it]) gg.push_back(*it),ok++,p--;
	}
	for(i=0;i<gg.size();i++) pc.erase(gg[i]);
	gg.clear();
    }
    cout<<ans;
}