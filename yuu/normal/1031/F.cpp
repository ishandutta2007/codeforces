#include <bits/stdc++.h>
using namespace std;
int p[1000001];
vector <int> base={1, 2, 4, 6, 8, 12, 16, 24, 30, 32, 36, 48, 60, 64, 72, 96, 120, 128, 144, 180, 192, 210, 216, 240, 256, 288, 360, 384, 420, 432, 480, 512, 576, 720, 768, 840, 864, 900, 960, 1024, 1080, 1152, 1260, 1296, 1440, 1536, 1680, 1728, 1800, 1920, 2048, 2160, 2304, 2310, 2520, 2592, 2880, 3072, 3360, 3456, 3600, 3840, 4096, 4320, 4608, 4620, 5040, 5184, 5400, 5760, 6144, 6300, 6480, 6720, 6912, 7200, 7560, 7680, 7776, 8192, 8640, 9216, 9240, 10080, 10368, 10800, 11520, 12288, 12600, 12960, 13440, 13824, 13860, 14400, 15120, 15360, 15552, 16384, 17280, 18432, 18480, 20160, 20736, 21600, 23040, 24576, 25200, 25920, 26880, 27000, 27648, 27720, 28800, 30030, 30240, 30720, 31104, 32400, 32768, 34560, 36864, 36960, 37800, 38880, 40320, 41472, 43200, 44100, 45360, 46080, 46656, 49152, 50400, 51840, 53760, 54000, 55296, 55440, 57600, 60060, 60480, 61440, 62208, 64800, 65536, 69120, 69300, 73728, 73920, 75600, 77760, 80640, 82944, 83160, 86400, 88200, 90720, 92160, 93312, 98304, 100800, 103680, 107520, 108000, 110592, 110880, 115200, 120120, 120960, 122880, 124416, 129600, 131072, 138240, 138600, 147456, 147840, 151200, 155520, 161280, 162000, 165888, 166320, 172800, 176400, 180180, 181440, 184320, 186624, 189000, 194400, 196608, 201600, 207360, 215040, 216000, 221184, 221760, 226800, 230400, 233280, 240240, 241920, 245760, 248832, 259200, 262144, 264600, 272160, 276480, 277200, 279936, 294912, 295680, 302400, 311040, 322560, 324000, 331776, 332640, 345600, 352800, 360360, 362880, 368640, 373248, 378000, 388800, 393216, 403200, 414720, 415800, 430080, 432000, 442368, 443520, 453600, 460800, 466560, 480480, 483840, 485100, 491520, 497664, 498960, 510510, 518400, 524288, 529200, 544320, 552960, 554400, 559872, 589824, 591360, 604800, 622080, 645120, 648000, 663552, 665280, 691200, 705600, 720720, 725760, 737280, 746496, 756000, 777600, 786432, 806400, 810000, 829440, 831600, 860160, 864000, 884736, 887040, 900900, 907200, 921600, 933120, 960960, 967680, 970200, 972000, 983040, 995328, 997920};
// const int sz=base.size();
const int sz=289;
int n;
map <vector <int>, int> id;
vector <vector <int>> a;
set <vector <int>> s;
const int morlim=10;//should be enough
vector <vector <int>> all;
vector <int> temp;
vector <vector <int>> k;
vector <vector <int>> g;
vector <int> divs;
map <int, int> pdivs;
void backtrack(int now, int lim){
	if(lim>now){
		all.push_back(temp);
	}
	else{
		backtrack(now, lim+1);
		temp.push_back(lim);
		backtrack(now-lim, lim);
		temp.pop_back();
	}
}
vector <int> f[sz];
map <vector <int>, int> m;
vector <int> d;
vector <int> done;
queue <int> q;
void bfs(int u){
	for(auto &x: d) x=0;
	done=d;
	done[u]=1;
	for(auto &x: d) x=1e9;
	d[u]=0;
	q.push(u);
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(int v: g[u]) if(!done[v]){
			done[v]=1;
			d[v]=d[u]+1;
			q.push(v);
		}
	}
}
int ans[sz][sz];
void prepare(){
	for(int i=2; i<=1000000; i++) if(p[i]==0) for(int j=i; j<=1000000; j+=i) if(p[j]==0) p[j]=i;
	a.resize(sz);
	for(int i: base){
		int ans=0;
		int u=i;
		vector <int> now;
		while(u>1){
			int x=p[u];
			now.push_back(0);
			while(u%x==0){
				u/=x;
				now.back()++;
			}
		}
		sort(now.begin(), now.end());
		int pos=id.size();
		id[now]=pos;
		a[pos]=now;
	}
	backtrack(morlim, 1);
	for(auto x: a){
		for(auto y: all){
			auto z=x;
			z.resize(x.size()+y.size());
			merge(x.begin(), x.end(), y.begin(), y.end(), z.begin());
			k.push_back(z);
		}
		for(int j=0; j<x.size(); j++){
			auto z=x;
			for(int f=1; f<=5; f++){
				z[j]++;
				k.push_back(z);
			}
		}
	}
	sort(k.begin(), k.end());
	d.resize(k.size());
	k.erase(unique(k.begin(), k.end()), k.end());
	long long mx=0;
	g.resize(k.size());
	for(auto a: k){
		long long res=1;
		for(auto x: a) res*=x+1;
		divs.push_back(res);
		pdivs[res]=1;
		int pos=m.size();
		m[a]=pos;
	}
	{
		int cnt=0;
		for(auto &x: pdivs){
			x.second=cnt;
			cnt++;
		}
	}
	for(int i=0; i<k.size(); i++) divs[i]=pdivs[divs[i]];
	for(auto a: k){
		int pos=m[a];
		for(int i=0; i<a.size(); i++){
			auto temp=a;
			temp[i]++;
			sort(temp.begin(), temp.end());
			auto res=m.find(temp);
			if(res!=m.end()){
				g[pos].push_back(res->second);
				g[res->second].push_back(pos);
			}
		}
		auto temp=a;
		temp.push_back(1);
		sort(temp.begin(), temp.end());
		auto res=m.find(temp);
		if(res!=m.end()){
			g[pos].push_back(res->second);
			g[res->second].push_back(pos);
		}
	}
	for(int i=0; i<sz; i++){
		int u=m[a[i]];
		bfs(u);
		f[i].resize(pdivs.size());
		for(auto &x: f[i]) x=100;
		for(int j=0; j<k.size(); j++)	f[i][divs[j]]=min(f[i][divs[j]], d[j]);		
	}
	for(int i=0; i<sz; i++){
		for(int j=0; j<sz; j++){
			ans[i][j]=1e9;
			for(int k=0; k<f[i].size(); k++) ans[i][j]=min(ans[i][j], f[i][k]+f[j][k]);
		}
	}
}
void solve(){
	int x, y;
	cin>>x>>y;
	{
		int u=x;
		vector <int> now;
		while(u>1){
			int x=p[u];
			now.push_back(0);
			while(u%x==0){
				u/=x;
				now.back()++;
			}
		}
		sort(now.begin(), now.end());
		x=id[now];
	}
	{
		int u=y;
		vector <int> now;
		while(u>1){
			int x=p[u];
			now.push_back(0);
			while(u%x==0){
				u/=x;
				now.back()++;
			}
		}
		sort(now.begin(), now.end());
		y=id[now];
	}
	cout<<ans[x][y]<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	prepare();
	int t;
	cin>>t;
	while(t--) solve();
}