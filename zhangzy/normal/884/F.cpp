#include<bits/stdc++.h>
#define ll long long
using namespace std;

namespace mincf{
    #define E 20100
    #define V 110
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
        int x,y,z;
        for (q.push(st);!q.empty();q.pop()){
            x=q.front(); in[x]=0;
            for (int i=hea[x];i>0;i=r[i].nex) if (r[i].flow){
                y=r[i].to;
                z=d[x]+r[i].cost;
                if (z<d[y]){
                    d[y]=z;
                    f[y]=min(f[x],(ll)r[i].flow);
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

int n,val[233][26],st,en,cnt[26],bas=51;
char s[233];

int main(){
	scanf("%d%s",&n,s+1);
	for (int i=1;i<=n;i++) cnt[s[i]-'a']++;
	for (int i=1;i<=n;i++) scanf("%d",&val[i][s[i]-'a']);
	mincf::resta(78,77,78);
	for (int i=0;i<26;i++){
		mincf::A(77,i+bas,0,cnt[i]);
	}
	for (int i=1;i<=n/2;i++){
		mincf::A(i,78,0,2);
		val[i][s[n+1-i]-'a']=max(val[i][s[n+1-i]-'a'],val[n+1-i][s[n+1-i]-'a']);
		for (int j=0;j<26;j++)
			mincf::A(j+bas,i,-val[i][j],1);
	}
	cout<<-mincf::realmain();
}