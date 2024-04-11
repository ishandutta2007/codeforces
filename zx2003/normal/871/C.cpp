#include<cstdio> 
#include<vector>
#include<set>
#include<map>
using namespace std;
const int N=100500,mo=1000000007;
int x[N],y[N],i,n,m,ans=1,f[N],sz[N],z,j,mi[N];
map<int,set<pair<int,int> > > a,b;
set<pair<int,int> >::iterator it;
vector<int> v[N];
map<int,int> aa,bb;
map<int,int>::iterator it2;
int gfa(int x){
	return f[x]==x?x:f[x]=gfa(f[x]);
}
inline void Un(int x,int y){
	x=gfa(x),y=gfa(y);
	if(x!=y)f[x]=y,sz[y]+=sz[x];
}
int main(){
	scanf("%d",&n);
	for(i=*mi=1;i<N;++i)mi[i]=1ll*mi[i-1]*2%mo;
	for(i=1;i<=n;++i){
		scanf("%d%d",x+i,y+i);
		a[x[i]].insert(make_pair(y[i],i));
		b[y[i]].insert(make_pair(x[i],i));
		//++aa[x[i]],++bb[y[i]];
		sz[i]=1;f[i]=i;
	}
	for(i=1;i<=n;++i){
		it=a[x[i]].lower_bound(make_pair(y[i],i));
		if(it!=a[x[i]].begin())--it,Un(i,it->second);
		it=a[x[i]].upper_bound(make_pair(y[i],i));
		if(it!=a[x[i]].end())Un(i,it->second);
		it=b[y[i]].lower_bound(make_pair(x[i],i));
		if(it!=b[y[i]].begin())--it,Un(i,it->second);
		it=b[y[i]].upper_bound(make_pair(x[i],i));
		if(it!=b[y[i]].end())Un(i,it->second);
	}
	for(i=1;i<=n;++i)v[gfa(i)].push_back(i);
	for(i=1;i<=n;++i)
		if(gfa(i)==i){
			z=0;
			aa.clear(),bb.clear();
			for(j=0;j<int(v[i].size());++j){
				++aa[x[v[i][j]]];
				++bb[y[v[i][j]]];
			}
			for(it2=aa.begin(),z=0;it2!=aa.end();++it2)z+=it2->second-1;
			for(it2=bb.begin();it2!=bb.end();++it2)z+=it2->second-1;
			if(z<sz[i])ans=1ll*ans*(mi[sz[i]+1]-1+mo)%mo;
				else ans=1ll*ans*(mi[sz[i]-(z-sz[i])])%mo;
		}
	return printf("%d\n",ans),0;
}