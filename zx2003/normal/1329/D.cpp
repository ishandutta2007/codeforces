#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,i;
char c[N];
struct node{int pre,nxt,be,en;}a[N];int xb;
int bi[N];
inline void add(int x,int v){for(;x<=n;x+=x&-x)bi[x]+=v;}
inline int ask(int x){int ans=0;for(;x;x-=x&-x)ans+=bi[x];return ans;}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%s",c+1);n=strlen(c+1);
		for(i=1;i<=n;++i)bi[i]=i&-i;
		for(i=1,xb=0;i<=n;++i){
			if(xb && c[a[xb].en]!=c[i])a[xb].en=i;
				else a[++xb]=(node){xb-1,0,i,i},a[xb-1].nxt=xb;
		}
		a[0].nxt=1;a[xb].nxt=xb+1;a[xb+1].pre=xb;
		static int buc[26];queue<int>q[26];memset(buc,0,104);
		static bool del[N];memset(del+1,0,xb);
		auto ck=[&](int i){return !del[i] && 0<a[i].pre && a[i].nxt<xb+1 && 
			c[a[i].be]!=c[a[i].en];};
		auto tryins=[&](int i){if(ck(i))q[c[a[i].be]-'a'].push(i),q[c[a[i].en]-'a'].push(i);};
		for(i=1;i<xb;++i)++buc[c[a[i].en]-'a'];
		for(i=2;i<xb;++i)tryins(i);
		vector<pair<int,int>>ans;
		set<int>S;for(i=1;i<=n;++i)S.insert(i);
		auto pushh=[&](int i){
			ans.push_back({ask(a[i].be),ask(a[i].en)});
			if(a[i].be>1)--buc[c[a[i].be]-'a'];if(a[i].en<n)--buc[c[a[i].en]-'a'];
			for(auto it=S.lower_bound(a[i].be);it!=S.end() && *it<=a[i].en;S.erase(it++))add(*it,-1);
		};
		for(;;){
			int mx=-1,mxid;
			for(i=0;i<26;++i)if(buc[i]>mx)mx=buc[i],mxid=i;
			auto ck2=[&](int i,char cc){return c[a[i].be]==cc || c[a[i].en]==cc;};
			i=mxid;for(;!q[i].empty() && (!ck2(q[i].front(),i+'a') || !ck(q[i].front()));q[i].pop());
			if(q[i].empty())break;
			i=q[i].front();
			pushh(i);
			int x=a[i].pre,y=a[i].nxt;del[i]=del[y]=1;
			a[x].en=a[y].en;y=a[y].nxt;
			a[x].nxt=y;a[y].pre=x;tryins(x);
		}
		for(i=a[0].nxt;i<=xb;i=a[i].nxt)pushh(i);
		printf("%d\n",(int)ans.size());
		for(auto u:ans)printf("%d %d\n",u.first,u.second);
	}
}