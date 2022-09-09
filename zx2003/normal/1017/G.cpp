#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q,i,o,v,be[N],en[N],dfn[N],dcnt;
vector<int>e[N];
void dfs(int x){dfn[be[x]=++dcnt]=x;for(int y:e[x])dfs(y);en[x]=dcnt;}
set<int>S;
struct node{int ch[2],fa,x,s,f;}t[N];
int dir(int x,int y){return t[x].ch[1]==y;}
void setc(int x,int y,int o){t[x].ch[o]=y;t[y].fa=x;}
bool nrt(int x){return t[t[x].fa].ch[0]==x || t[t[x].fa].ch[1]==x;}
void upd(int x){
	int l=t[x].ch[0],r=t[x].ch[1];
	t[x].s=t[l].s+t[r].s+t[x].x;
	t[x].f=max(t[r].f,t[r].s+max(t[x].x,t[x].x+t[l].f));
}
void rotate(int x){
	int y=t[x].fa,z=t[y].fa,o;
	if(nrt(y))setc(z,x,dir(z,y));t[x].fa=z;
	o=dir(y,x);setc(y,t[x].ch[!o],o);setc(x,y,!o);upd(y);
}
void splay(int x){
	for(;nrt(x);rotate(x)){
		int y=t[x].fa,z=t[y].fa;
		if(nrt(y))rotate(dir(z,y)==dir(y,x)?y:x);
	}
	upd(x);
}
void access(int x){int y=0,ox=x;for(;x;)splay(x),setc(x,y,1),upd(x),y=x,x=t[x].fa;splay(ox);}
int main(){
	t[0].f=-1;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(i=2;i<=n;++i)cin>>v,t[i].fa=v,e[v].push_back(i);dfs(1);
	for(i=1;i<=n;++i)t[i].x=-1,upd(i);
	for(;q--;){
		cin>>o>>v;
		if(o==1)access(v),++t[v].x,upd(v),S.insert(be[v]);
		if(o==2){
			for(auto it=S.lower_bound(be[v]);it!=S.end() && *it<=en[v];S.erase(it++))
				access(dfn[*it]),t[dfn[*it]].x=-1,upd(dfn[*it]);
			access(v);t[v].x-=t[v].f+1;upd(v);S.insert(be[v]);
		}
		if(o==3)access(v),cout<<(t[v].f>=0?"black":"white")<<'\n';
	}
	return 0;
}