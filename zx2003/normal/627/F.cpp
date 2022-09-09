#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef vector<int>V;
int n,ca[N],cb[N],u[N],v[N],i,j,z,S,T,deg[N],id[N],X;
long long ans;
V e[N],ep;
multiset<int>SS;
bool b1[N];
int dad[N],dep[N];
void dfs(int x,int fa){dep[x]=dep[fa]+1;dad[x]=fa;for(int y:e[x])if(y!=fa)dfs(y,x);}
inline V getP(int x,int y){dfs(y,0);V ans;for(;ans.push_back(x),x!=y;x=dad[x]);return ans;}
inline void shift(V&a,int d){
	V b=V(a.begin(),a.begin()+d);
	a=V(a.begin()+d,a.end());a.insert(a.end(),b.begin(),b.end());
}
int dfs2(int x,int fa){
	if(x==X)return !id[x];
	if(b1[x]){puts("-1");exit(0);}
	for(int y:e[x])if(y!=fa){int t=dfs2(y,x);if(t!=-1)return t+!id[x];}
	return -1;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",ca+i),ca[i]?0:S=i;
	for(i=1;i<=n;++i)scanf("%d",cb+i),cb[i]?0:T=i;
	for(i=1;i<n;++i)scanf("%d%d",u+i,v+i),e[u[i]].push_back(v[i]),e[v[i]].push_back(u[i]);

	auto zz=getP(S,T);
	for(i=0;i+1<zz.size();++i)swap(ca[zz[i]],ca[zz[i+1]]),++ans;
	for(i=0;i<zz.size();++i)id[zz[i]]=i+1;
	for(i=1;i<=n;++i)b1[i]=ca[i]!=cb[i];
	for(i=1;i<n;++i)if(b1[u[i]] && b1[v[i]])++deg[u[i]],++deg[v[i]];
	for(i=1;i<=n;++i)if(b1[i] && deg[i]<2)for(int x=2-deg[i];x--;)SS.insert(i);
	if(SS.empty()){printf("0 %lld\n",ans);return 0;}
	
	dfs(T,0);
	int mn=N,mnid=0;
	for(i=1;i<=n;++i)if(b1[i] && dep[i]<mn)mn=dep[i],mnid=i;
	if(SS.size()==2){
		if(deg[mnid]>1){puts("-1");return 0;}
		X=dad[mnid];
		ep={X,*SS.begin()^*SS.rbegin()^mnid};
	}else if(SS.size()==4){
		for(i=1;i<=n;++i)if(!b1[i]){int ct=0;for(int j:e[i])ct+=b1[j] && deg[j]<2;if(ct==2)break;}
		if(i>n){puts("-1");return 0;}
		X=i;
		if(dep[X]>=dep[mnid]){puts("-1");return 0;}
		for(int j:e[i])if(b1[j] && deg[j]<2)SS.erase(SS.find(j));
		ep={*SS.begin(),*SS.rbegin()};
	}else{puts("-1");return 0;}
	
	auto p0=getP(ep[0],ep[1]),pp0=p0;p0.erase(find(p0.begin(),p0.end(),X));
	auto p1=p0,p2=p0;
	for(int&x:p1)x=ca[x];for(int&y:p2)y=cb[y];
	for(i=0;i<p1.size() && p1[i]!=p2[0];++i);
	if(i==p1.size()){puts("-1");return 0;}
	shift(p1,i);
	if(p1!=p2){puts("-1");return 0;}
	for(int x:p0)z+=id[x]>0;
	if(z<1){
		ans+=dfs2(T,0)*2;
		ans+=1ll*(p0.size()+1)*min(int(p0.size()-i),i);
	}else{
		p0=pp0;
		p0.push_back(p0[0]);
		long long v1=1ll*(p0.size()-1)*i,v2=1ll*(p0.size()-1)*(p1.size()-i);
		if(v1)for(j=0;j+1<p0.size();++j)v1-=(id[p0[j]] && id[p0[j+1]] && id[p0[j]]-1==id[p0[j+1]])*2;
		if(v2)for(j=0;j+1<p0.size();++j)v2-=(id[p0[j]] && id[p0[j+1]] && id[p0[j]]+1==id[p0[j+1]])*2;
		ans+=min(v1,v2);
	}
	sort(ep.begin(),ep.end());
	printf("%d %d %lld\n",ep[0],ep[1],ans);
	return 0;
}