#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int p[1000001];
ll f[1000001];
ll last[1000001];
ll gain[1000001];
vector <pair <int, int>> nx[1000001];
ll k;
bool done[1000001];
vector <int> primes;
queue <int> q;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=2; i<=1000000; i++) if(p[i]==0){
		for(int j=i; j<=1000000; j+=i) if(p[j]==0) p[j]=i;
		primes.push_back(i);
	}
	for(int i=1000000; i>=2; i--){
		int k=i-1;
		while(k>1){
			nx[i].push_back({p[k], 0});
			while(k%nx[i].back().first==0){
				k/=nx[i].back().first;
				nx[i].back().second++;
			}
		}
	}
	int m;
	cin>>m;
	for(int i=0; i<m; i++){
		ll p, a;
		cin>>p>>a;
		f[p]+=a;
		if(!done[p]){
			q.push(p);
			done[p]=1;
		}
	}
	while(!q.empty()){
		auto u=q.front();
		q.pop();
		for(auto v: nx[u]) if(!done[v.first]){
			done[v.first]=1;
			q.push(v.first);
		}
	}
	cin>>k;
	int t=min(k, 20LL);
	while(t){
		k--;
		t--;
		for(int x: primes) if(f[x]){
			f[x]--;
			for(auto v: nx[x]) f[v.first]+=v.second;
		}
	}
	if(k){
		k--;
		for(int x: primes) if(f[x]){
			f[x]--;
			for(auto v: nx[x]) f[v.first]+=v.second;
		}
	}
	if(k){
		set <pair <ll, int>> s;
		ll now=0;
		ll end=k;
		for(int x: primes) if(f[x]) for(auto v: nx[x]) gain[v.first]+=v.second;
		for(int x: primes) if(f[x]&&(gain[x]==0)) s.insert(make_pair(now+f[x], x));
		while(!s.empty()){
			auto p=*s.begin();
			s.erase(s.begin());
			now=p.first;
			if(now>end) now=end;
			f[p.second]-=now-last[p.second];
			last[p.second]=now;
			for(auto v: nx[p.second]){
				f[v.first]+=(now-last[v.first])*(gain[v.first]-1);
				last[v.first]=now;
				gain[v.first]-=v.second;
				if(gain[v.first]==0) s.insert(make_pair(now+f[v.first], v.first));
			}
			if(now==end) break;
		}
		for(int x: primes) if(f[x]) f[x]+=(gain[x]-1)*(now-last[x]);
	}
	vector <pair <int, ll>> ans;
	for(int x: primes) if(f[x]) ans.push_back(make_pair(x, f[x]));
	cout<<ans.size()<<'\n';
	for(auto x: ans) cout<<x.first<<' '<<x.second<<'\n';
}