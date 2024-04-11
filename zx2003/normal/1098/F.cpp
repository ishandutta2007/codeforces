#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,q,i,l[N],r[N],s1[N];ll s2[N];
template<typename T>struct BIT{
	T bi[N];
	inline void add(int x,int v){for(;x<=n;x+=x&-x)bi[x]+=v;}
	inline T ask(int x){T ans=0;for(;x;x-=x&-x)ans+=bi[x];return ans;}
};
BIT<ll>b1;BIT<int>b2;
struct que{int l,r,i;};
struct tree{
	static const int N=::N*4;
	int vcnt,ecnt,h[N];
	int dad[N],idd[N],depp[N];
	struct edge{int to,next;}e[N<<1];
	void addedge(int x,int y){
		e[++ecnt]=(edge){y,h[x]};h[x]=ecnt;
		e[++ecnt]=(edge){x,h[y]};h[y]=ecnt;dad[y]=x;
	}
	vector<que>qu[N];
	int sz[N],ce,sum,ww[N];
	bool vi[N],bb[N];
	void getce(int x,int fa){
		sz[x]=1;
		for(int i=h[x];i;i=e[i].next)if(!vi[i>>1] && e[i].to!=fa){
			getce(e[i].to,x),sz[x]+=sz[e[i].to];
			auto cost=[&](int x){return max(sum-sz[e[x].to],sz[e[x].to]);};
			if(!ce || cost(ce)>cost(i))ce=i;
		}
	}
	pair<int,int>vv[N];int vxb;
	void dfs1(int x,int fa){
		ww[x]=bb[x]?depp[x]:ww[fa];
		if(idd[x])vv[++vxb]={idd[x],ww[x]+idd[x]};
		for(int i=h[x];i;i=e[i].next)if(!vi[i>>1] && e[i].to!=fa)dfs1(e[i].to,x);
	}
	que quu[N];int qxb;
	void dfs2(int x,int fa){
		for(auto u:qu[x])quu[++qxb]=(que){u.l-1,u.r,-u.i},quu[++qxb]=(que){u.r,u.r,u.i};
		for(int i=h[x];i;i=e[i].next)if(!vi[i>>1] && e[i].to!=fa)dfs2(e[i].to,x);
	}
	void dfs3(int x,int fa){
		if(idd[x])vv[++vxb]={idd[x],idd[x]};
		for(int i=h[x];i;i=e[i].next)if(!vi[i>>1] && e[i].to!=fa)dfs3(e[i].to,x);
	}
	int dd[N];
	void dfs4(int x,int fa){
		for(auto u:qu[x])quu[++qxb]=(que){u.l-1,u.r-ww[x],-u.i},quu[++qxb]=(que){u.r,u.r-ww[x],u.i},dd[u.i]=ww[x];
		for(int i=h[x];i;i=e[i].next)if(!vi[i>>1] && e[i].to!=fa)dfs4(e[i].to,x);
	}
	void solve(int x){
		if(sum==1)return;
		ce=0;getce(x,0);vi[ce>>1]=1;
		int y,i,j,r,s;
		for(y=e[ce^1].to;bb[y]=1,y!=x;y=dad[y]);
		vxb=0;dfs1(x,0);
		qxb=0;dfs2(e[ce].to,0);
		sort(vv+1,vv+vxb+1);sort(quu+1,quu+qxb+1,[&](const que&a,const que&b){return a.l<b.l;});
		for(i=1,j=0;i<=qxb;++i){
			for(;j<vxb && (tie(r,s)=vv[j+1],r<=quu[i].l);++j)b1.add(s,s),b2.add(s,1);
			r=quu[i].i;if(r<0)s=-1,r=-r;else s=1;
			s1[r]+=s*b2.ask(quu[i].r);s2[r]+=s*b1.ask(quu[i].r);
		}
		for(i=1;i<=j;++i)tie(r,s)=vv[i],b1.add(s,-s),b2.add(s,-1);
		vxb=0;dfs3(e[ce].to,0);
		qxb=0;dfs4(x,0);
		sort(vv+1,vv+vxb+1);sort(quu+1,quu+qxb+1,[&](const que&a,const que&b){return a.l<b.l;});
		for(i=1,j=0;i<=qxb;++i){
			for(;j<vxb && (tie(r,s)=vv[j+1],r<=quu[i].l);++j)b1.add(s,s),b2.add(s,1);
			r=quu[i].i;if(r<0)s=-1,r=-r;else s=1;
			if(quu[i].r>0)s1[r]+=s*b2.ask(quu[i].r),s2[r]+=s*(b1.ask(quu[i].r)+1ll*b2.ask(quu[i].r)*dd[r]);
		}
		for(i=1;i<=j;++i)tie(r,s)=vv[i],b1.add(s,-s),b2.add(s,-1);
		for(y=e[ce^1].to;bb[y]=0,y!=x;y=dad[y]);
		int oc=ce;
		sum-=sz[e[oc].to];solve(x);
		sum=sz[e[oc].to];solve(e[oc].to);
	}
}T;
struct SAM{
	static const int N=::N*2;
	int ch[N][26],step[N],pre[N],xb,pos[N],id[N];
	vector<int>e[N];
	void build(){
		static char c[N];int x,lst,p,q,np,nq,i;xb=lst=1;
		scanf("%s",c+1);n=strlen(c+1);
		for(int i=n;i;--i){
			x=c[i]-'a';step[np=++xb]=step[p=lst]+1;
			for(;p && !ch[p][x];p=pre[p])ch[p][x]=np;
			if(p){
				q=ch[p][x];	
				if(step[p]+1!=step[q]){
					step[nq=++xb]=step[p]+1;
					memcpy(ch[nq],ch[q],104);
					pre[nq]=pre[q];pre[q]=pre[np]=nq;
					for(;p && ch[p][x]==q;p=pre[p])ch[p][x]=nq;
				}else pre[np]=q;
			}else pre[np]=1;
			lst=np;pos[i]=lst;id[lst]=i;
		}
		for(i=2;i<=xb;++i)e[pre[i]].push_back(i);
		T.vcnt=xb;T.ecnt=1;
		for(i=1;i<=xb;++i){
			int j=0,x=i;
			for(;j+2<e[i].size();++j)T.addedge(x,e[i][j]),T.addedge(x,++T.vcnt),x=T.vcnt,T.depp[x]=step[i];
			for(;j<e[i].size();++j)T.addedge(x,e[i][j]);
		}
		memcpy(T.idd+1,id+1,xb<<2);memcpy(T.depp+1,step+1,xb<<2);
	}
}S;
int main(){
	S.build();
	scanf("%d",&q);for(i=1;i<=q;++i)scanf("%d%d",l+i,r+i),T.qu[S.pos[l[i]]].push_back((que){l[i],r[i],i});
	T.sum=T.vcnt;T.solve(1);
	for(i=1;i<=q;++i){
		int len=r[i]-l[i]+1;
		printf("%lld\n",s2[i]+1ll*(len-s1[i])*(r[i]+1)-1ll*len*(l[i]+r[i])/2);
	}
	return 0;
}