#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
char c[N];
int ch[N*2][26],pre[N*2],step[N*2],f[20][N*2],lst=1,xb=1;
vector<int>e[N*2];
int m,q,i,j,l,r,pl,pr,pos[N],x,u;
struct A{
	int x,y;
	inline bool operator<(const A&rhs)const{return x==rhs.x?y>rhs.y:x<rhs.x;}
	inline void out(){printf("%d %d\n",y,x);}
}ans[N];
struct node{int l,r,s;A mx;}t[N*3];int tcnt;
inline void upd(int x){t[x].mx=max(t[t[x].l].mx,t[t[x].r].mx);}
void ins(int&x,int l,int r,int k){
	if(!x)x=++tcnt;if(l==r){t[x].mx=(A){++t[x].s,l};return;}
	int m=l+r>>1;if(k<=m)ins(t[x].l,l,m,k);else ins(t[x].r,m+1,r,k);upd(x);
}
int merge(int x,int y){
	if(!x || !y)return x|y;
	if(t[x].s)t[x].mx=(A){t[x].s+=t[y].s,t[x].mx.y};
		else t[x].l=merge(t[x].l,t[y].l),t[x].r=merge(t[x].r,t[y].r),upd(x);
	return x;
}
A ask(int x,int rl,int rr,int l,int r){
	if(!x || (l<=rl && rr<=r))return t[x].mx;
	int m=rl+rr>>1;A ans=(A){0,0};if(l<=m)ans=max(ans,ask(t[x].l,rl,m,l,r));if(m<r)ans=max(ans,ask(t[x].r,m+1,rr,l,r));
	return ans;
}
vector<pair<int,int>>a[N*2];
struct que{int l,r,i,len;};vector<que>qu[N*2];int rt[N*2];
inline bool cmp(const que&a,const que&b){return a.len<b.len;}
void dfs(int u){
	for(int v:e[u])dfs(v),rt[u]=merge(rt[u],rt[v]);
	int i=qu[u].size()-1,j=a[u].size()-1;sort(qu[u].begin(),qu[u].end(),cmp);
	sort(a[u].begin(),a[u].end());
	for(;i>=0;--i){
		for(;j>=0 && a[u][j].first>=qu[u][i].len;rt[u]=merge(rt[u],a[u][j--].second));
		A t=ask(rt[u],1,m,qu[u][i].l,qu[u][i].r);
		ans[qu[u][i].i]=t.x?t:(A){0,qu[u][i].l};
	}
	for(;j>=0;rt[u]=merge(rt[u],a[u][j--].second));
}
inline int ask(int l,int r){
	int len=r-l+1,u=pos[r],i=19;for(;i>=0;--i)if(step[f[i][u]]>=len)u=f[i][u];
	return u;
}
int main(){
	scanf("%s",c+1);
	for(i=1;c[i];++i){
		int p,q,np,nq;x=c[i]-'a';step[np=++xb]=step[p=lst]+1;
		for(;p && !ch[p][x];p=pre[p])ch[p][x]=np;
		if(p){
			q=ch[p][x];
			if(step[p]+1!=step[q]){
				step[nq=++xb]=step[p]+1;memcpy(ch[nq],ch[q],104);
				pre[nq]=pre[q];pre[q]=pre[np]=nq;for(;p && ch[p][x]==q;p=pre[p])ch[p][x]=nq;
			}else pre[np]=q;
		}else pre[np]=1;pos[i]=lst=np;
	}
	memcpy(f[0]+1,pre+1,xb<<2);for(i=1;i<20;++i)for(j=1;j<=xb;++j)f[i][j]=f[i-1][f[i-1][j]];
	for(i=2;i<=xb;++i)e[pre[i]].push_back(i);
	scanf("%d",&m);
	for(i=1;i<=m;++i){
		scanf("%s",c+1);u=1;l=0;
		for(j=1;c[j];++j){
			x=c[j]-'a';
			for(;u>1 && !ch[u][x];u=pre[u],l=step[u]);
			if(ch[u][x])++l,u=ch[u][x],r=0,ins(r,1,m,i),a[u].push_back(make_pair(l,r));
		}
	}
	scanf("%d",&q);for(i=1;i<=q;++i)scanf("%d%d%d%d",&l,&r,&pl,&pr),qu[ask(pl,pr)].push_back((que){l,r,i,pr-pl+1});
	dfs(1);for(i=1;i<=q;++i)ans[i].out();
	return 0;
}