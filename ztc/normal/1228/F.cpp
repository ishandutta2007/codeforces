#include<stdio.h>
#include<bits/stdc++.h>
using std::make_pair;
int Last[500002],Next[500002],End[500002],s,tot=0,f[500002],rt,n;
template<typename T>inline T Max(T p,T q){return p>q?p:q;}
std::pair<int,int>dfs(int p,int d,int f){
	std::pair<int,int>ans=make_pair(d,p);
	for(int i=Last[p];i;i=Next[i])if(End[i]!=f)ans=Max(ans,dfs(End[i],d+1,p));
	return ans;
}
void dfs0(int p){
	for(int i=Last[p];i;i=Next[i])if(End[i]!=f[p]){f[End[i]]=p;dfs0(End[i]);}
}
bool ish(int p,int f,int h){
	if(h==1)return p&&!Next[Last[p]];int cnt=0;bool ans=1;
	for(int i=Last[p];i;i=Next[i])if(End[i]!=f){if(++cnt>2)return 0;ans&=ish(End[i],p,h-1);if(ans==0)return 0;}
	if(cnt!=2||!ans)return 0;return 1;
}
void get(int p,int f,int h){
	if(h==1)exit(printf("0")&0);int cnt=0;
	for(int i=Last[p];i;i=Next[i])if(End[i]!=f)cnt++;
	if(cnt>3||cnt==0)exit(printf("0")&0);
	if(cnt==3){
		int a[3],top=0;
		for(int i=Last[p];i;i=Next[i])if(End[i]!=f)a[top++]=End[i];
		if(ish(a[0],p,h-1)&&ish(a[1],p,h-2)&&ish(a[2],p,h-2))exit(printf("1\n%d",p)&0);
		if(ish(a[1],p,h-1)&&ish(a[0],p,h-2)&&ish(a[2],p,h-2))exit(printf("1\n%d",p)&0);
		if(ish(a[2],p,h-1)&&ish(a[1],p,h-2)&&ish(a[0],p,h-2))exit(printf("1\n%d",p)&0);
		exit(printf("0")&0);
	}if(cnt==1){
		if(h!=2)exit(printf("0")&0);int q;
		for(int i=Last[p];i;i=Next[i])if(End[i]!=f)q=End[i];
		if(!Next[Last[q]])exit(printf("1\n%d",p)&0);exit(printf("0")&0);
	}int a[2],top=0;
	for(int i=Last[p];i;i=Next[i])if(End[i]!=f)a[top++]=End[i];
	if(ish(a[0],p,h-1))get(a[1],p,h-1);
	else if(ish(a[1],p,h-1))get(a[0],p,h-1);
	else exit(printf("0")&0);
}
int main(){
	scanf("%d",&n);if(n==2)return printf("2\n1 2")&0;
	for(int i=1;i<=(1<<n)-3;i++){
		int p,q;scanf("%d%d",&p,&q);
		End[++tot]=q;Next[tot]=Last[p];Last[p]=tot;
		End[++tot]=p;Next[tot]=Last[q];Last[q]=tot;
	}std::pair<int,int>t=dfs(rt=dfs(1,0,0).second,0,0);
	if(t.first+1>>1!=n-1)return printf("0")&0;
	dfs0(t.second);for(int i=1;i<n;i++)s=rt,rt=f[rt];
	if(t.first&1){
		if(Next[Next[Next[Last[rt]]]]||!Next[Next[Last[rt]]])return printf("0")&0;
		if(ish(s,rt,n-1)&&ish(rt,s,n-1))return printf("%d\n%d %d",2,s<rt?s:rt,s>rt?s:rt)&0;
		return printf("0")&0;
	}if(Next[Next[Last[rt]]])return printf("0")&0;
	if(ish(End[Last[rt]],rt,n-1))get(End[Next[Last[rt]]],rt,n-1);
	else if(ish(End[Next[Last[rt]]],rt,n-1))get(End[Last[rt]],rt,n-1);
	else printf("0");
}