#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
const int N=500,EXT=10;
int T,n,nn,rk,lst,top,anstop,ans[5000010],arr[N+EXT],bkt[N+EXT],map[N+EXT],p[5000010],v[5000010],nw[5000010],nxt[5000010];
struct unset{
	int id,val;
	unset(){};
	unset(int id,int val):id(id),val(val){};
}urr[N+EXT];
inline bool cmp(unset a,unset b){return a.val<b.val;}
/*void insert(int u,int val){
	++top,p[top]=u,v[top]=val;
	for(register int i=1;i<=u;++i)nxt[i]=nw[i];
	nxt[u+1]=nxt[u+2]=val;
	for(register int i=u+1;i<=nn;++i)nxt[i+2]=nw[i];
	nn+=2;
	for(register int i=1;i<=nn;++i)nw[i]=nxt[i];
}*/
int main(){
	scanf("%d",&T);
	do{
		scanf("%d",&n);
		memset(bkt,0,sizeof(bkt));
		top=0,nn=n;
		for(register int i=1;i<=n;++i)scanf("%d",&urr[i].val),urr[i].id=i;
		std::sort(urr+1,urr+1+n,cmp);
		rk=0,lst=-1;
		for(register int i=1;i<=n;++i){
			if(urr[i].val!=lst)lst=urr[i].val,++rk,map[rk]=lst;
			arr[urr[i].id]=nw[urr[i].id]=rk;
		}
		for(register int i=1;i<=n;++i)++bkt[arr[i]];
		bool flag=true;
		for(register int i=1;i<=n;++i)if(bkt[i]%2==1)flag=false;
		if(!flag){
			puts("-1");
			continue;
		}
		int pos=1;
		anstop=0;
		while(pos<=nn){
			int nxt=pos+1;
			while(nw[nxt]!=nw[pos])++nxt;
			for(register int i=pos+1;i<nxt;++i){
				++top,p[top]=nxt+i-pos-1,v[top]=nw[i];
			}
			int p=pos,q=nxt;
			ans[++anstop]=(nxt-pos)*2,pos=2*nxt-pos;
			for(register int i=1;i<q;++i)::nxt[i]=nw[i];
			for(register int i=p;i<q;++i)::nxt[i-p+q]=nw[i];
			for(register int i=p;i<q-1;++i)::nxt[i-2*p+2*q]=nw[p+q-1-i];
			for(register int i=q+1;i<=nn;++i)::nxt[i-2*p+2*q-2]=nw[i];
			nn+=(q-p-1)*2;
			for(register int i=1;i<=nn;++i)nw[i]=::nxt[i];
		}
		printf("%d\n",top);
		for(register int i=1;i<=top;++i){
			printf("%d %d\n",p[i],map[v[i]]);
		}
		printf("%d\n",anstop);
		for(register int i=1;i<=anstop;++i)printf("%d\n",ans[i]);
	}while(--T);
	return 0;
}