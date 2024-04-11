#include<stdio.h>
#define S 300
int v[300002],b[1002][302],fl[1002],dv[1002],mv[1002];
inline int Max(int p,int q){return p>q?p:q;}
inline void Maxx(int &p,int q){p=p>q?p:q;}
inline void calc(int B){
	if(fl[B])for(int i=1,j=B*S+1;i<=S;i++,j++)b[B][i]=Max(mv[B],v[j]-dv[B]);
	else for(int i=1;i<=S;i++)b[B][i]=Max(b[B][i]-=dv[B],mv[B]);
	fl[B]=dv[B]=mv[B]=0;
}
inline int get(int p){
	if(!p)return 0;
	int B=(p-1)/S;
	return Max(mv[B],(fl[B]?v[p]:b[B][p-S*B])-dv[B]);
}
void addvm(int l,int r,int v){
	int lb=(l+S-2)/S,rb=r/S;
	if(lb>rb){calc(rb);for(int i=l-rb*S,e=r-rb*S;i<=e;i++)Maxx(--b[rb][i],v);return;}
	if(lb*S>=l){calc(lb-1);for(int i=l-(lb-1)*S;i<=S;i++)Maxx(--b[lb-1][i],v);}
	if(rb*S<r){calc(rb);for(int i=r-rb*S;i>=1;i--)Maxx(--b[rb][i],v);}
	for(int i=lb;i<rb;i++)dv[i]++,Maxx(--mv[i],v);
}
void resv(int l,int r,int V){
	int lb=(l+S-2)/S,rb=r/S;
	if(lb>rb){calc(rb);for(int i=l-rb*S,j=l,e=r-rb*S;i<=e;i++,j++)b[rb][i]=v[j]-V;return;}
	if(lb*S>=l){calc(lb-1);for(int i=l-(lb-1)*S,j=l;i<=S;i++,j++)b[lb-1][i]=v[j]-V;}
	if(rb*S<r){calc(rb);for(int i=r-rb*S,j=r;i>=1;i--,j--)b[rb][i]=v[j]-V;}
	for(int i=lb;i<rb;i++)fl[i]=1,dv[i]=V,mv[i]=0;
}
int Last[200002],Next[200002],t[200002],s[200002],d[200002],f[2000002],tot=0,n,m;
void dfs(int p){
	t[p]=++tot;s[p]=1;
	for(int i=Last[p];i;i=Next[i])d[i]=d[p]+1,dfs(i),s[p]+=s[i];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++){
		scanf("%d",&f[i]);
		Next[i]=Last[f[i]];Last[f[i]]=i;
	}for(int i=0;i<=1000;i++)fl[i]=1;d[1]=1;dfs(1);
	for(int i=1;i<=n;i++)v[t[i]]=d[i];int cnt=0;
	while(m--){
		int hdhd,AKIOI;scanf("%d%d",&hdhd,&AKIOI);
		if(hdhd==1){
			int l=t[AKIOI],r=t[AKIOI]+s[AKIOI]-1,v=get(t[f[AKIOI]]);
			addvm(l,r,v);
		}else if(hdhd==2){
			int l=t[AKIOI],r=t[AKIOI]+s[AKIOI]-1,v=d[f[AKIOI]]-get(t[f[AKIOI]]);
			resv(l,r,v);
		}else printf("%s\n",get(t[f[AKIOI]])==get(t[AKIOI])?"black":"white");
	}
}