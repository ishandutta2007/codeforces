#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct node{
	int ch[2],fa,s,v,mn;bool b;
	inline int dir(int x){return ch[1]==x;}
	inline void rev(){b^=1;swap(ch[0],ch[1]);}
}t[N*3];
inline void upd(int x){
	t[x].s=t[t[x].ch[0]].s+t[t[x].ch[1]].s+1;
	t[x].mn=min(min(t[t[x].ch[0]].mn,t[t[x].ch[1]].mn),t[x].v);
}
inline void setc(int x,int y,int o){t[x].ch[o]=y;t[y].fa=x;}
inline void pushdown(int x){if(t[x].b)t[t[x].ch[0]].rev(),t[t[x].ch[1]].rev(),t[x].b=0;}
inline bool nrt(int x){return t[t[x].fa].ch[0]==x || t[t[x].fa].ch[1]==x;}
inline void rotate(int x){
	int y=t[x].fa,z=t[y].fa,o;
	if(nrt(y))setc(z,x,t[z].dir(y));t[x].fa=z;
	o=t[y].dir(x);setc(y,t[x].ch[!o],o);setc(x,y,!o);upd(y);
}
inline void splay(int x,int gd=0){
	static int st[N*3];int w=0,y,z;
	for(y=x;st[++w]=y,nrt(y);y=t[y].fa);
	for(;w;)pushdown(st[w--]);
	for(;nrt(x) && t[x].fa!=gd;rotate(x)){
		y=t[x].fa;z=t[y].fa;
		if(nrt(y))rotate(t[z].dir(y)==t[y].dir(x)?y:x);
			else ++x,--x;
	}
	upd(x);
}
inline void access(int x){
	for(int y=0;x;x=t[x].fa)
		splay(x),t[x].ch[1]=y,upd(x),y=x;
}
inline void makeroot(int x){access(x);splay(x);t[x].rev();}
inline void expose(int x,int y){makeroot(x);access(y);splay(y);}
inline void link(int x,int y){makeroot(x);t[x].fa=y;}
inline int goleft(int x){for(;pushdown(x),t[x].ch[0];x=t[x].ch[0]);return x;}
inline int findmn(int x){int v=t[x].mn;for(;t[x].v!=v;pushdown(x),x=t[x].ch[t[t[x].ch[1]].mn==v]);splay(x);return x;}
int n,m,k,q,a[N],b[N],e[N],c[N],i,p[N],na[N],nb[N],oc[N];
vector<int>ve[55],tim[N];int ps[55];
inline int getid(int c,int x){return lower_bound(ve[c].begin(),ve[c].end(),x)-ve[c].begin()+ps[c-1]+1;}
inline void insedge(int x,int y,int z,int ti){
	assert(!na[z]);assert(!nb[z]);
	t[z+ps[k]].v=t[z+ps[k]].mn=ti;t[z+ps[k]].s=1;
	expose(x,y);
	int w=goleft(y);if(x==w &&  t[y].mn>=ti)return splay(w);
	na[z]=x;nb[z]=y;
	if(x==w){
		w=findmn(y);pushdown(w);
		int p=t[w].ch[0],q=t[w].ch[1];t[p].fa=t[q].fa=t[w].ch[0]=t[w].ch[1]=0;
		na[w-ps[k]]=nb[w-ps[k]]=0;
		splay(x);
	}else splay(w);
	splay(y);t[y].rev();t[x].fa=t[y].fa=z+ps[k];
}
inline void deledge(int z){
	makeroot(z+ps[k]);pushdown(z+ps[k]);t[z+ps[k]].ch[0]=t[z+ps[k]].ch[1]=0;
	splay(na[z],z+ps[k]);splay(nb[z],z+ps[k]);
assert(t[na[z]].fa==z+ps[k]);
assert(t[nb[z]].fa==z+ps[k]);
	t[na[z]].fa=t[nb[z]].fa=0;na[z]=nb[z]=0;
}
int main(){
	t[0].mn=N;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k>>q;
	for(i=1;i<=m;++i)cin>>a[i]>>b[i];
	for(i=1;i<=q;++i)cin>>e[i]>>c[i],ve[c[i]].push_back(a[e[i]]),ve[c[i]].push_back(b[e[i]]),tim[e[i]].push_back(i);
	for(i=1;i<=k;++i)sort(ve[i].begin(),ve[i].end()),ve[i].erase(unique(ve[i].begin(),ve[i].end()),
		ve[i].end()),ps[i]=ps[i-1]+ve[i].size();
	for(i=1;i<=ps[k];++i)t[i].mn=t[i].v=N+5;
	for(i=1;i<=q;++i){
		int x=getid(c[i],a[e[i]]),y=getid(c[i],b[e[i]]),w,tt=++p[e[i]]==tim[e[i]].size()?N:tim[e[i]][p[e[i]]];
		expose(x,y);w=goleft(y);splay(w);
		if(w==x && t[w].s/2%2==0){
			cout<<"NO\n";
			if(oc[e[i]]){
				if(!na[e[i]])insedge(getid(oc[e[i]],a[e[i]]),getid(oc[e[i]],b[e[i]]),e[i],tt);
					else makeroot(e[i]+ps[k]),t[e[i]+ps[k]].v=tt,upd(e[i]+ps[k]);
			}
		}else{
			cout<<"YES\n";
			if(na[e[i]])
				deledge(e[i]);
			insedge(x,y,e[i],tt);oc[e[i]]=c[i];
		}
	}
	return 0;
}