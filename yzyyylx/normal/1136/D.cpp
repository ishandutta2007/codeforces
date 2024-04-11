#include<bits/stdc++.h>
#define N 300100
using namespace std;

int n,m,ans,num[N],pos[N];
bool vis[N];
vector<int>to[N];
set<int>now;
set<int>::iterator it;

int main()
{
    int i,j,p,q;
    cin>>n>>m;
    for(i=1;i<=n;i++) scanf("%d",&num[i]);
    for(i=1;i<=m;i++)
    {
	scanf("%d%d",&p,&q);
	to[p].push_back(q);
    }
    for(i=1;i<=n;i++) sort(to[i].begin(),to[i].end());
    now.insert(num[n]);
    for(i=n-1;i>=1;i--)
    {
	for(it=now.begin(),j=0;it!=now.end()&&j<to[num[i]].size();j++)
	{
	    if((*it)==to[num[i]][j]) it++;
	}
	if(it==now.end()) ans++;
	else now.insert(num[i]);
//	for(it=now.begin();it!=now.end();it++) cout<<(*it)<<' ';puts("");
    }
    cout<<ans;
}