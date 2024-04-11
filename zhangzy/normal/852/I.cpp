#include<bits/stdc++.h>
#define ll long long
#define xxx 201000
using namespace std;

int n,q,sex[xxx],num[xxx],tmp[xxx];
struct R{ int to,nex; }r[xxx];
int hea[xxx]={0},cnt=1;

int d[xxx],bsz,bel[xxx],used[23333],tim[xxx];
ll tot[2][xxx],ans,an[xxx];
int fa[xxx][20]={0},dft=0,df1[xxx],df2[xxx],dep[xxx]={0};
void dfs(int x,int fff){
	d[df1[x]=++dft]=x;
	fa[x][0]=fff;dep[x]=dep[fff]+1;
	for (int i=1;i<20;i++){
		if (dep[x]>(1<<i)){
			fa[x][i]=fa[fa[x][i-1]][i-1];
		}else{
			break;
		}
	}
	for (int i=hea[x],y;i>0;i=r[i].nex){
		y=r[i].to; if (y==fff) continue;
		dfs(y,x);
	}
	d[df2[x]=++dft]=x;
}
int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=19;i>=0;i--){
		x= dep[fa[x][i]]>=dep[y] ? fa[x][i]:x;
	}
	if (x==y) return x;
	for (int i=19;i>=0;i--){
		if (fa[x][i]!=fa[y][i]){
			x=fa[x][i];y=fa[y][i];
		}
	}
	return fa[x][0];
}

struct Que{
	int st,en,more,id;
}que[xxx];
bool cmp(Que q1,Que q2){
	return bel[q1.st]==bel[q2.st] ? q1.en<q2.en : q1.st<q2.st;
}
void add(int w){
	ll fh=tim[w]?-1:1;
	ans+=fh*tot[sex[w]^1][num[w]];
	tot[sex[w]][num[w]]+=fh;
	tim[w]^=1;
}
void del(int w){
	ll fh=tim[w]?1:-1;
	ans-=fh*tot[sex[w]^1][num[w]];
	tot[sex[w]][num[w]]-=fh;
	tim[w]^=1;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;scanf("%d",&sex[i++]));
	for (int i=1;i<=n;scanf("%d",&num[i++]));
	memcpy(tmp,num,sizeof tmp);
	sort(tmp+1,tmp+n+1);
	for (int i=1;i<=n;i++) num[i]=lower_bound(tmp+1,tmp+n+1,num[i])-tmp;
	for (int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		r[++cnt]=(R){y,hea[x]};hea[x]=cnt;
		r[++cnt]=(R){x,hea[y]};hea[y]=cnt;
	}
	dfs(1,0);
	bsz=sqrt(dft+0.1);
	for (int i=1;i<=dft;i++){
		bel[i]=(i-1)/bsz+1;
	}
	scanf("%d",&q);
	for (int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		if (df1[x]>df1[y]) swap(x,y);
		if (df2[x]<=df1[y]) {
			que[i]=(Que){df2[x],df1[y],lca(x,y),i};
		}else{
			que[i]=(Que){df1[x],df1[y],0,i};
		}
	}
	sort(que+1,que+q+1,cmp);
	
	memset(used,0,sizeof used);
	for (int i=1,l,r;i<=q;i++){
		//printf(" %d %d %d %d\n",que[i].id,que[i].st,que[i].en,que[i].more);
		if (!used[bel[que[i].st]]){
			used[bel[que[i].st]]=1;
			memset(tot,0,sizeof tot);
			memset(tim,0,sizeof tim);
			ans=0;
			l=que[i].st;r=l-1;
		}
		while (r<que[i].en) add(d[++r]);
		while (l>que[i].st) add(d[--l]);
		while (l<que[i].st) del(d[l++]);
		if (que[i].more) add(que[i].more);
		an[que[i].id]=ans;
		if (que[i].more) del(que[i].more);
	}
	for (int i=1;i<=q;printf("%I64d\n",an[i++]));
}