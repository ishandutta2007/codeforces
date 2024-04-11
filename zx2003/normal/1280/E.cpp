#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int T,r,i,st[N],w,xb,f[N];
vector<int>ch[N];int tp[N];
long long ans[N];
void dfs(int x){
	if(tp[x]==0)f[x]=1;
	if(tp[x]==1)f[x]=0;
	if(tp[x]==2)f[x]=N;
	for(int y:ch[x]){
		dfs(y);
		if(tp[x]==1)f[x]+=f[y];
		if(tp[x]==2)f[x]=min(f[x],f[y]);
	}
}
void getway(int x,int w){
	if(tp[x]==0){ans[x]=1ll*w*r;return;}
	if(tp[x]==1){
		for(int y:ch[x])getway(y,w);
	}else{
		for(int y:ch[x])if(f[y]==f[x]){getway(y,w);break;}
	}
}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&r);
		xb=0;
		for(;;){
			char c=getchar();
			if(c=='\n')break;
			if(c=='('){
				if(w)ch[st[w]].push_back(xb+1);
				st[++w]=++xb,ch[xb].clear();
			}
			if(c==')')--w;
			if(c=='S')tp[st[w]]=2;
			if(c=='P')tp[st[w]]=1;
			if(c=='*')tp[++xb]=0,ch[xb].clear(),ch[st[w]].push_back(xb);
		}
		dfs(1);
		for(i=1;i<=xb;++i)ans[i]=0;
		getway(1,f[1]);
		printf("REVOLTING ");
		for(i=1;i<=xb;++i)if(tp[i]==0)printf("%lld ",ans[i]);puts("");
	}
}