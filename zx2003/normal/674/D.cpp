#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,q,a[N],o,i,j,x,d[N];
ll b[N],e[N],cc[N];
multiset<ll>s,s2[N];
inline void add(int x){
	if(!s2[x].empty())s.insert(*s2[x].begin()+e[x]),s.insert(*s2[x].rbegin()+e[x]);
}
inline void remove(int x){
	if(!s2[x].empty())s.erase(s.find(*s2[x].begin()+e[x])),s.erase(s.find(*s2[x].rbegin()+e[x]));
}
inline void ins(int x){
	s2[a[x]].insert(cc[x]);
}
inline void del(int x){
	s2[a[x]].erase(s2[a[x]].find(cc[x]));
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(i=1;i<=n;++i)cin>>b[i],d[i]=2;
	for(i=1;i<=n;++i)cin>>a[i],++d[a[i]];
	for(i=1;i<=n;++i)cc[a[i]]+=e[i]=b[i]/d[i];
	for(i=1;i<=n;++i)cc[i]+=b[i]%d[i]+e[i],ins(i);
	for(i=1;i<=n;++i)add(i);
	while(q--){
		cin>>o;
		if(o==1){
			cin>>i>>j;if(a[i]==j)continue;x=a[i];
			static vector<int>z,zz;
			z.clear();
			z.push_back(x);z.push_back(a[x]);z.push_back(a[a[x]]);
			z.push_back(j);z.push_back(a[j]);z.push_back(a[a[j]]);
			sort(z.begin(),z.end());z.erase(unique(z.begin(),z.end()),z.end());
			for(int k=0;k<z.size();++k)remove(z[k]);
			zz.clear();
			zz.push_back(x);zz.push_back(a[x]);zz.push_back(i);
			zz.push_back(j);zz.push_back(a[j]);
			sort(zz.begin(),zz.end());zz.erase(unique(zz.begin(),zz.end()),zz.end());
			for(int k=0;k<zz.size();++k)del(zz[k]);
			cc[a[x]]-=e[a[i]];cc[a[j]]-=e[j];
			cc[x]-=e[i]+e[x]+b[x]%d[x];e[x]=b[x]/(--d[x]);cc[x]+=e[x]+b[x]%d[x];
			cc[j]+=e[i]-e[j]-b[j]%d[j];e[j]=b[j]/(++d[j]);cc[j]+=e[j]+b[j]%d[j];
			cc[a[x]]+=e[a[i]];cc[a[j]]+=e[j];
			a[i]=j;
			for(int k=0;k<zz.size();++k)ins(zz[k]);
			for(int k=0;k<z.size();++k)add(z[k]);
		}
		if(o==2)cin>>i,cout<<cc[i]+e[a[i]]<<'\n';
		if(o==3)cout<<*s.begin()<<' '<<*s.rbegin()<<'\n';
	}
	return 0;
}