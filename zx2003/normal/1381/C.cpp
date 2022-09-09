#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,X,Y,a[N],b[N],i,zz,x,y;
vector<int>ve[N];
priority_queue<pair<int,int>>q;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d%d",&n,&X,&Y);
		for(i=1;i<=n+1;++i)ve[i].clear();for(;!q.empty();q.pop());
		for(i=1;i<=n;++i)scanf("%d",b+i),ve[b[i]].push_back(i);
		for(i=1;i<=n+1;++i)if(!ve[i].empty())q.push({ve[i].size(),i});else zz=i;
		for(i=1;i<=n;++i)a[i]=zz;
		for(i=1;i<=X;++i){
			x=q.top().second;q.pop();
			a[ve[x].back()]=x;ve[x].pop_back();if(!ve[x].empty())q.push({ve[x].size(),x});
		}
		int tot=X;
		for(;q.size()>1 && tot<Y && q.top().first>1;){
			x=q.top().second;q.pop();
			y=q.top().second;q.pop();
			++tot;a[ve[x].back()]=y;ve[x].pop_back();if(!ve[x].empty())q.push({ve[x].size(),x});
			if(tot<Y)++tot,a[ve[y].back()]=x;ve[y].pop_back();if(!ve[y].empty())q.push({ve[y].size(),y});
		}
		if(q.size()>1){
			vector<int>v;
			for(;!q.empty();q.pop())v.push_back(ve[q.top().second][0]);
			for(i=0;i<v.size() && tot<Y;++i)a[v[i]]=b[v[(i+1)%v.size()]],++tot;
		}
		if(tot<Y)puts("NO");else{
			puts("YES");
			for(i=1;i<=n;++i)printf("%d%c",a[i],i==n?'\n':' ');
		}
	}
}