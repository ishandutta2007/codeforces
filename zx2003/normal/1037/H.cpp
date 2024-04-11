#include<bits/stdc++.h>
const int M=2e5+5;
char c[M];
int q,l,r,n;
int rt[M];
struct node{int l,r;}t[M*200];int tcnt;
void ins(int&x,int l,int r,int k){
	if(!x)x=++tcnt;if(l==r)return;
	int m=l+r>>1;if(k<=m)ins(t[x].l,l,m,k);else ins(t[x].r,m+1,r,k);
}
int merge(int x,int y){
	if(!x && !y)return 0;
	int z=++tcnt;
	if(!x)t[z]=t[y];if(!y)t[z]=t[x];
	if(!x || !y)return z;
	t[z].l=merge(t[x].l,t[y].l);t[z].r=merge(t[x].r,t[y].r);
	return z;
}
bool ask(int x,int l,int r,int ql,int qr){
	if(!x)return 0;
	if(ql<=l && r<=qr)return 1;
	bool ret=0;int m=l+r>>1;
	if(ql<=m)ret|=ask(t[x].l,l,m,ql,qr);
	if(m<qr)ret|=ask(t[x].r,m+1,r,ql,qr);
	return ret;
}
struct SAM{
	int ch[M][26],pre[M],step[M],xb;
	std::vector<int>e[M];
	void dfs(int x){for(int y:e[x])dfs(y),rt[x]=merge(rt[x],rt[y]);}
	void build(){
		int p,q,np,nq,lst=xb=1,i,x;
		for(i=1;i<=n;++i){
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
			}else pre[np]=1;lst=np;
			ins(rt[np],1,n,i);
		}
		for(i=2;i<=xb;++i)e[pre[i]].push_back(i);
		dfs(1);
	}
	void solve(){
		static int nd[M],cc[M];int i,j,le=strlen(c+1);
		nd[0]=1;
		for(i=1;i<=le;++i)cc[i]=c[i]-'a';
		for(i=1;i<=le;++i)nd[i]=ch[nd[i-1]][cc[i]];
		auto ck=[&](int x,int c,int le){
			x=ch[x][c];
			return x && le<=r-l+1 && ask(rt[x],1,n,l+le-1,r);
		};
		cc[le+1]=-1;
		for(i=le;i>=0;--i){
			for(j=cc[i+1]+1;j<26;++j)if(ck(nd[i],j,i+1)){
				c[i+1]=j+'a';c[i+2]=0;
				puts(c+1);return;
			}
		}
		puts("-1");
	}
}S;
int main(){
	scanf("%s",c+1);n=strlen(c+1);
	S.build();
	for(scanf("%d",&q);q--;){
		scanf("%d%d%s",&l,&r,c+1);
		S.solve();
	}
}