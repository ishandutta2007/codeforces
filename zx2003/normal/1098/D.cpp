#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
pair<int,int>a[N];
char o[N];
int n,i,x[N],id[N],v[N],st[N],w,ans;
multiset<int>s;
ll bi[N];
inline void add(int x,int v){for(;x<=n;x+=x&-x)bi[x]+=v;}
inline ll sum(int x){ll ans=0;for(;x;x-=x&-x)ans+=bi[x];return ans;}
int main(){
	ios::sync_with_stdio(0);cin.tie();
	cin>>n;for(i=1;i<=n;++i)cin>>o[i]>>x[i],a[i]=make_pair(x[i],i);
	sort(a+1,a+n+1);
	for(i=1;i<=n;++i){
		if(a[i-1].first<a[i].first)w=0;
		if(o[a[i].second]=='+')st[++w]=i,id[a[i].second]=i,v[i]=a[i].first;
			else id[a[i].second]=st[w--];
	}
	for(i=1;i<=n;++i){
		if(o[i]=='+')add(id[i],x[i]),s.insert(x[i]);
			else add(id[i],-x[i]),s.erase(s.find(x[i]));
		if(s.empty()){
			cout<<"0\n";
			continue;
		}
		int z=*s.begin(),ans=s.size()-1;
		for(;;){
			set<int>::iterator it=s.upper_bound(z*2);
			if(it==s.end())break;
			ll su=sum(upper_bound(a+1,a+n+1,make_pair(*it,0))-a-1);
			if(su*2<*it)--ans,z=*it;else{
				if(su*2>=*s.rbegin())break;
				z=su;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}