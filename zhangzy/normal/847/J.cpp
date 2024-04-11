#include<bits/stdc++.h>
using namespace std;

int n,m,u[5555],v[5555],st,en;

namespace mxfl{
	struct R{
		int to,fl,nex;
	}r[53333];
	int hea[10100],cnt,d[10100],ans,inf;
	queue<int>q;
	
	void add(int u,int v,int flow){
		r[++cnt]=(R){v,flow,hea[u]}; hea[u]=cnt;
		r[++cnt]=(R){u,0   ,hea[v]}; hea[v]=cnt;
	}
	
	void RE(){
		memset(hea,0,sizeof hea);
		cnt=1;ans=0;
	}
	
	bool bfs(){
		memset(d,38,sizeof d);
		inf=d[233];d[st]=0;
		while (!q.empty()) q.pop();
		q.push(st);
		for (int u,v;!q.empty();){
			u=q.front();q.pop();
			for (int i=hea[u];i>0;i=r[i].nex){
				v=r[i].to;
				if (!r[i].fl||d[v]!=inf) continue;
				d[v]=d[u]+1;
				q.push(v);
			}
		}
		return d[en]!=inf;
	}
	
	int dfs(int x,int f){
		if (x==en||f==0) return f;
		int las=f,y,t;
		for (int i=hea[x];i>0;i=r[i].nex){
			y=r[i].to;
			if (d[y]!=d[x]+1) continue;
			t=dfs(y,min(las,r[i].fl));
			r[i].fl-=t;
			r[i^1].fl+=t;
			las-=t;
		}
		return f-las;
	}
	
	int realmain(){
		while (bfs()) ans+=dfs(st,inf);
		return ans;
	}
}

bool pd(int now){
	mxfl::RE();
	for (int i=1;i<=m;i++){
		mxfl::add(u[i],i+n,1);
		mxfl::add(v[i],i+n,1);
		mxfl::add(i+n,en,1);
	}
	for (int i=1;i<=n;i++){
		mxfl::add(st,i,now);
	}
	return mxfl::realmain()==m;
}	

int main(){
	scanf("%d%d",&n,&m);
	st=n+m+1;en=st+1;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
	}
	
	int l=0,r=st,mid;
	for (;l<r;pd(mid)?r=mid:l=mid+1){
		mid=(l+r)>>1;
	}
	printf("%d\n",l);
	pd(l);
	for (int i=1,id;i<=m;i++){
		id=6*i-4;
		if (mxfl::r[id].fl){
			printf("%d %d\n",v[i],u[i]);
		}else{
			printf("%d %d\n",u[i],v[i]);
		}
	}
}