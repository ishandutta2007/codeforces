#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,L,a[N],i,nxt[N],lb[N],rb[N],sz[N],rt;
vector<int>e[N],aa;
bool bb[N];
void E(){puts("no");exit(0);}
void ckk(){
	static int ri[N],st[N];int w=0;
	for(i=1;i<=L;++i)if(a[i]){
		if(!lb[a[i]])lb[a[i]]=i;else if((i-rb[a[i]])&1)E();
		ri[rb[a[i]]]=i;rb[a[i]]=i;
	}
	for(i=L;i;--i)if(a[i]){
		for(;w && st[w]<ri[i];--w){
			if(ri[st[w]]>ri[i])E();
			if(a[st[w]]!=a[st[w+1]])e[a[i]].push_back(a[st[w]]);
		}
		st[++w]=i;
	}
	for(i=1;i<=n;++i)if(!lb[i])aa.push_back(i);
	if(!rt){
		rt=a[1]=a[L]=aa.back(),aa.pop_back();lb[rt]=1;rb[rt]=L;
		for(;w;--w)if(a[st[w]]!=a[st[w+1]])e[rt].push_back(a[st[w]]);
	}
}
bool bbb[N];
void dfs(int x){
	for(int y:e[x])dfs(y);
	static int b[N],st[N];int xb=0,w=0,i;
	for(i=lb[x];i<=rb[x];i=nxt[i])b[++xb]=i;
	for(i=1;i<=xb;++i)if(a[b[i]]){
		st[++w]=b[i];
		for(;;){
			if(w>2 && a[st[w-1]] && a[st[w-2]]==a[st[w]]){w-=2;break;}
			if(w>2 && a[st[w-1]] && !a[st[w-2]]){
				if(a[st[w-1]]==x)break;
				a[st[w-2]]=a[st[w]];w-=2;
			}else break;
		}
	}else{
		if(w>1 && a[st[w]] && a[st[w-1]])a[b[i]]=a[st[w-1]],--w;
			else st[++w]=b[i];
	}
	for(i=1;i<w;++i)if(a[st[i]] && a[st[i+1]] && a[st[i]]!=x && a[st[i+1]]!=x)
		E();
	int z=x;
	for(i=1;i<=w;)if(a[st[i]]!=x){
		if(a[st[i]])a[st[i+1]]=a[st[i-1]],i+=2;else{
			if(z==x)z=aa.back(),aa.pop_back();else z=x;
			a[st[i]]=z;++i;
		}
	}else z=x,++i;
	nxt[lb[x]]=rb[x]+1;
}
int main(){
	scanf("%d",&n);L=n*2-1;
	for(i=1;i<=L;++i)scanf("%d",a+i);
	if(a[1] && a[L] && a[1]!=a[L])E();
	if(a[1] || a[L])rt=a[1]|a[L],a[1]=a[L]=rt;
	ckk();
	for(i=1;i<=L;++i)nxt[i]=i+1;
	dfs(rt);
	puts("yes");for(i=1;i<=L;++i)printf("%d%c",a[i],i==L?'\n':' ');
	return 0;
}