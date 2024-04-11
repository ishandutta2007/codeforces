#include<bits/stdc++.h>
using namespace std;
#define ll long long

namespace mincf{
	#define E 1001000
	#define V 10100
	struct R{
		int to,nex;
		ll cost,flow;
	}r[E];
	int st,en,n,cnt,hea[V];
	
	void A(int u,int v,ll c,ll f){
		r[++cnt]=(R){v,hea[u],c,f}; hea[u]=cnt;
		r[++cnt]=(R){u,hea[v],-c,0};hea[v]=cnt;
	}
	void resta(int n_,int st_,int en_){
		memset(hea,0,sizeof hea);
		cnt=1;
		n=n_; st=st_; en=en_;
	}
	
	int pv[V],pe[V],in[V];
	queue<int>q;
	ll fl,f[V],d[V],ans,sf,inf;
	
	bool spfa(){
		while (!q.empty()) q.pop();
		memset(in,0,sizeof in);
		memset(d,62,sizeof d);
		f[st]=inf=d[0];
		d[st]=0;
		ll x,y,z;
		for (q.push(st);!q.empty();q.pop()){
			x=q.front(); in[x]=0;
			for (int i=hea[x];i>0;i=r[i].nex) if (r[i].flow){
				y=r[i].to;
				z=d[x]+r[i].cost;
				if (z<d[y]){
					d[y]=z;
					f[y]=min(f[x],r[i].flow);
					pv[y]=x;
					pe[y]=i;
					if (!in[y]){
						in[y]=1;
						q.push(y);
					}
				}
			}
		}
		return d[en]!=inf;
	}
	
	ll realmain(){
		sf=ans=0;
		while (spfa()){
			sf+=fl=f[en];
			ans+=fl*d[en];
			for (int x=en;x!=st;x=pv[x]){
				r[pe[x]].flow-=fl;
				r[pe[x]^1].flow+=fl;
			}
		}
		return ans;
	}
}

int n, m, s, t, cnt[111];
ll bas, inf=1e9;

int main(){
    cin>>n>>m; s=n+1; t=n+2;
    mincf::resta(n+2,s,t);
    for (int u, v, c, f;m--;){
        cin>>u>>v>>c>>f;
        cnt[v]+=f;
        cnt[u]-=f;
        if (f>c){
            bas+=f-c;
            mincf::A(v,u,0,f-c);
            mincf::A(v,u,1,c);
            mincf::A(u,v,2,inf);
        }else{
            mincf::A(u,v,1,c-f);
            mincf::A(v,u,1,f);
            mincf::A(u,v,2,inf);
        }
    }
    mincf::A(n,1,0,inf);
    mincf::A(1,n,0,inf);
    for (int i=1;i<=n;++i){
        if (cnt[i]>0){
            mincf::A(s,i,0,cnt[i]);
        }
        if (cnt[i]<0){
            mincf::A(i,t,0,-cnt[i]);
        }
    }
    ll ans=mincf::realmain();
    cout<<ans+bas<<endl;
}