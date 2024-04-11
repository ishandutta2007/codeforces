#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

int n,m,l[110],r[110];

namespace flower{
	struct R{
		int to,nex,fl,cost;
	}r[233333];
	int hea[233],cnt,st,en,nd;
	
	void RE(){
		memset(hea,0,sizeof hea);
		cnt=1;
	}
	void A(int u,int v,int f,int c){
		//printf("%d: %d->%d %d %d\n",cnt+1,u,v,f,c);
		r[++cnt]=(R){v,hea[u],f,c}; hea[u]=cnt;
		r[++cnt]=(R){u,hea[v],0,-c};hea[v]=cnt;
	}
	
	queue<int>q;
	int d[233],prev[233],pree[233],f[233],in[233],inf;
	
	bool Spfa(){
		memset(d,62,sizeof d);
		memset(in,0,sizeof in);
		memset(f,62,sizeof f);
		inf=d[33]; d[st]=0;
		while (!q.empty()) q.pop();
		q.push(st);
		for (int u,v,t;!q.empty();){
			u=q.front(); q.pop();
			//printf(" %d\n",u);Sleep(333);
			in[u]=0;
			for (int i=hea[u];i>0;i=r[i].nex){
				if (!r[i].fl) continue;
				v=r[i].to;
				t=d[u]+r[i].cost;
				if (t<d[v]){
					d[v]=t;
					prev[v]=u;
					pree[v]=i;
					f[v]=min(f[u],r[i].fl);
					if (!in[v]){
						in[v]=1;
						q.push(v);
					}
				}
			}
		}
		return d[en]<inf;
	}
	
	int realmain(){
		int ans=0,x,flow;
		while (Spfa()){
			flow=f[en];
			ans+=d[en]*flow;
			x=en;
			while (x!=st){
				//printf(" %d(%d)",x,pree[x]);
				r[pree[x]].fl-=flow;
				r[pree[x]^1].fl+=flow;
				x=prev[x];
			}
			//printf("\n");
		}
		return ans;
	}
}

int main(){
	flower::RE();
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		r[i]=n;
		l[i]=1;
	}
	int t,x,y,z;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d%d",&t,&x,&y,&z);
		for (int j=x;j<=y;j++){
			if (t==1) l[j]=max(l[j],z);
			else r[j]=min(r[j],z);
		}
	}
	flower::nd=n*2+2;
	flower::st=n*2+1;
	flower::en=n*2+2;
	for (int i=1;i<=n;i++){
		flower::A(flower::st,i,1,0);
		if (l[i]>r[i]) return 0*puts("-1");
		for (int j=l[i];j<=r[i];j++){
			flower::A(i,j+n,1,0);
		}
		for (int j=1;j<=n;j++){
			flower::A(i+n,flower::en,1,j*2-1);
		}
	}
	cout<<flower::realmain();
}