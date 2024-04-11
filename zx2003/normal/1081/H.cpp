#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mo1=1e9+7,mo2=998244853;
inline int poww(int x,int y,int mo){int ans=1;for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;return ans;}
struct P{int x,y;}mi[N],imi[N],ha[2][N];
const P B=(P){31,29},iB=(P){poww(31,mo1-2,mo1),poww(29,mo2-2,mo2)};
inline P operator+(const P&a,const P&b){return (P){(a.x+b.x)%mo1,(a.y+b.y)%mo2};}
inline P operator-(const P&a,const P&b){return (P){(a.x+mo1-b.x)%mo1,(a.y+mo2-b.y)%mo2};}
inline P operator*(const P&a,const P&b){return (P){int(1ll*a.x*b.x%mo1),int(1ll*a.y*b.y%mo2)};}
inline bool operator<(const P&a,const P&b){return a.x==b.x?a.y<b.y:a.x<b.x;}
char c[2][N];
int i,j,k,l[2],le[2][N],xbb[2];
long long ans;
struct PAM{
	int ch[N][26],pre[N],xb,len[N],anc[20][N];P h[N];
	inline void build(char*c){
		int i,j,x,p,q,lst=1;
		xb=1;len[1]=-1;pre[0]=1;
		for(int i=1;c[i];++i){
			x=c[i]-'a';
			for(p=lst;c[i-len[p]-1]!=c[i];p=pre[p]);
			if(!ch[p][x]){
				for(q=pre[p];c[i-len[q]-1]!=c[i];q=pre[q]);
				len[++xb]=len[p]+2;pre[xb]=ch[q][x];ch[p][x]=xb;
			}
			lst=ch[p][x];
		}
		for(i=0;i<=xb;++i)for(j=0;j<26;++j)if(ch[i][j]>1)
			h[ch[i][j]]=i==1?(P){j+1,j+1}:h[i]*B+(P){j+1,j+1}*(mi[0]+mi[len[ch[i][j]]-1]);
		memcpy(anc[0],pre,xb+1<<2);
		for(i=1;i<20;++i)for(j=0;j<=xb;++j)anc[i][j]=anc[i-1][anc[i-1][j]];
	}
	inline int go1(char*c,int i,int u,char x){
		for(;c[i-len[u]-1]!=x;u=pre[u]);
		return ch[u][x-'a'];
	}
	inline int go2(char*c,int i,int u,char x){
		for(;c[i+len[u]+1]!=x;u=pre[u]);
		return ch[u][x-'a'];
	}
	inline int climb(int u,int l){
		for(int i=19;i>=0;--i)if(len[anc[i][u]]>l)u=anc[i][u];
		return pre[u];
	}
	inline P gethh(int o,int u){
		return o==0?h[u]-h[pre[u]]*mi[len[u]-len[pre[u]]]:(h[u]-h[pre[u]])*imi[len[pre[u]]];
	}
}PA[2];
inline void work(int o){
	static int pos[N],rpos[N],id[N];
	scanf("%s",c[o]+1);l[o]=strlen(c[o]+1);
	PA[o].build(c[o]);
	pos[0]=1;for(i=1;i<=l[o];++i)pos[i]=PA[o].go1(c[o],i,pos[i-1],c[o][i]),id[pos[i]]=i;
	rpos[l[o]+1]=1;for(i=l[o];i;--i)rpos[i]=PA[o].go2(c[o],i,rpos[i+1],c[o][i]);
	for(i=2;i<=PA[o].xb;++i)if(PA[o].len[i]>1){
		int r=id[i],l=r-PA[o].len[i]+1,z;
		if(o==1)r-=PA[o].len[PA[o].pre[i]];else l+=PA[o].len[PA[o].pre[i]];
		if(l>=r)continue;
		j=PA[o].climb(rpos[l],r-l);z=PA[o].len[j];
		if(j>1 && (k=PA[o].climb(pos[r],r-l+1-z),PA[o].len[k]==r-l+1-z)){
			++xbb[o];
			if(o==0)ha[o][xbb[o]]=PA[o].h[j]*(mi[r-l+1]+mi[0])+PA[o].h[k]*mi[z],le[o][xbb[o]]=z;
				else ha[o][xbb[o]]=PA[o].h[k]*(mi[r-l+1]+mi[0])+PA[o].h[j]*mi[r-l+1-z],le[o][xbb[o]]=r-l+1-z;
			continue;
		}
		j=PA[o].climb(pos[r],r-l);z=PA[o].len[j];
		if(j>1 && (k=PA[o].climb(rpos[l],r-l+1-z),PA[o].len[k]==r-l+1-z)){
			swap(j,k);z=r-l+1-z;
			++xbb[o];
			if(o==0)ha[o][xbb[o]]=PA[o].h[j]*(mi[r-l+1]+mi[0])+PA[o].h[k]*mi[z],le[o][xbb[o]]=z;
				else ha[o][xbb[o]]=PA[o].h[k]*(mi[r-l+1]+mi[0])+PA[o].h[j]*mi[r-l+1-z],le[o][xbb[o]]=r-l+1-z;
		}
	}
}
inline void work2(int o){
	map<P,int>mp;
	for(i=2;i<=PA[o].xb;++i)if(PA[o].len[i]>1)mp[PA[o].h[i]]=i;
	for(i=1;i<=xbb[!o];++i){
		auto it=mp.find(ha[!o][i]);if(it==mp.end())continue;
		ans-=PA[o].len[PA[o].pre[it->second]]>le[!o][i];
	}
}
int main(){
	for(i=1,mi[0]=imi[0]=(P){1,1};i<N;++i)mi[i]=mi[i-1]*B,imi[i]=imi[i-1]*iB;
	work(0);work(1);
	ans=1ll*(PA[0].xb-1)*(PA[1].xb-1);
	map<P,int>mp;
	for(i=2;i<=PA[0].xb;++i)if(PA[0].len[i]>1)++mp[PA[0].gethh(0,i)];
	for(i=2;i<=PA[1].xb;++i)if(PA[1].len[i]>1)ans-=mp[PA[1].gethh(1,i)];
	work2(0);work2(1);printf("%lld\n",ans);
}