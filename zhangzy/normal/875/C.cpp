#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

namespace ts{
	#define N 401000
	int n,m,x_id[N],x_who[N],y_id[N],y_who[N],bel[N],cnt_block,sta[N],top,used[N],dfn[N],dft,low[N];
	struct R{
		int from,to,nex;
	}r[N<<1];
	int hea[N],cnt,ans[N];
	
	map<pii,bool>mp;
	
	void A(int u,int v){
		if (mp.count((pii){u,v})) return;
		mp[(pii){u,v}]=1;
		//printf("%d->%d\n",u,v);
		r[++cnt]=(R){u,v,hea[u]};
		hea[u]=cnt;
	}
	
	void dfs(int x){
		used[x]=1;
		dfn[x]=low[x]=++dft;
		sta[++top]=x;
		int y;
		for (int i=hea[x];i>0;i=r[i].nex){
			y=r[i].to;
			if (!used[y]){
				dfs(y);
				low[x]=min(low[x],low[y]);
			}else{
				if (!bel[y]){
					low[x]=min(low[x],dfn[y]);
				}
			}
		}
		if (dfn[x]==low[x]){
			cnt_block++;
			while (sta[top]!=x){
				bel[sta[top]]=cnt_block;
				top--;
			}
			bel[x]=cnt_block;
			top--;
		}
	}
	
	void oorr(int tx,int ix,int ty,int iy){
		m++;
		x_who[m]=tx;
		x_id[m]=ix^1;
		y_who[m]=ty;
		y_id[m]=iy^1;
	}
	
	bool realmain(){
		memset(hea,0,sizeof(hea));
		cnt=0;
		int the_x,the_y;
		for (int i=1;i<=m;i++){
			the_x=x_who[i]*2+x_id[i];
			the_y=y_who[i]*2+y_id[i];
			A(the_x,the_y^1);
			A(the_y,the_x^1);
		}
		
		memset(bel,0,sizeof(bel));
		memset(dfn,0,sizeof(dfn));
		memset(used,0,sizeof(used));
		
		cnt_block=0;dft=0;
		for (int i=2;i<=n*2+1;i++){
			if (!bel[i]){
				top=0;
				dfs(i);
			}
		}
		
		for (int i=1;i<=n;i++){
			if (bel[i<<1]==bel[i<<1|1]){
				return 0;
			}
			ans[i]=bel[i<<1|0]>bel[i<<1|1];
		}
		return 1;
	}
}

int n,m,x,l,sz1,sz2;
vector<int>v[101000];

void doit(vector<int>v1,vector<int>v2){
	sz1=v1.size();
	sz2=v2.size();
	for (int i=0;i<min(sz1,sz2);i++){
		if (v1[i]==v2[i]) continue;
		if (v1[i]<v2[i]){
			ts::oorr(v1[i],1,v2[i],0);
		}else{
			ts::oorr(v1[i],1,v1[i],1);
			ts::oorr(v2[i],0,v2[i],0);
		}
		return;
	}
	if (sz1<=sz2) return;
	puts("No");
	exit(0);
}

int main(){
	scanf("%d%d",&n,&m);
	ts::n=m;
	ts::m=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&l);
		for (;l--;){
			scanf("%d",&x);
			v[i].push_back(x);
		}
		if (i>1) doit(v[i-1],v[i]);
	}
	if (!ts::realmain()) puts("No");
	else{
		int tot=0;
		for (int i=1;i<=ts::n;i++){
			if (ts::ans[i]) tot++;
		}
		printf("Yes\n%d\n",tot);
		for (int i=1;i<=ts::n;i++){
			if (ts::ans[i]) printf("%d ",i);
		}
	}
}