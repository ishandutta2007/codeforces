#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

const int B=500;
const int inf=1000000000;

int n,m;
int a[200010];
int l[200010],r[200010];
vector<int> id[200010];
int id_l[200010],id_r[200010];
int R[200010];
void solve(){
	if(1){
		vector<int> v;
		for(int i=0;i<n;i++)v.push_back(a[i]);
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		for(int i=0;i<n;i++)a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin();
		for(int i=0;i<v.size();i++){
			id[i].clear();
			id_l[i]=id_r[i]=0;
		}
		for(int i=0;i<n;i++)id[a[i]].push_back(i);
		for(int i=0;i<n;i++)R[i]=i;
	}
	vector<pair<int,int>> Q;
	for(int i=0;i<m;i++)Q.push_back(mp(l[i]-1,r[i]));
	sort(Q.begin(),Q.end(),[](auto x,auto y){
		if(x.fr/B!=y.fr/B)return x.fr/B<y.fr/B;
		else return x.sc<y.sc;
	});
	int c=0,d=0;
	for(auto p: Q){
		while(c<p.fr){
			id_l[a[c]]++;
			c++;
		}
		while(d>p.sc){
			d--;
			id_r[a[d]]--;
		}
		while(c>p.fr){
			c--;
			id_l[a[c]]--;
			int t=a[c];
			if(id_r[t]-id_l[t]>=2){
				chmax(R[0],id[t][id_r[t]-2]+1);
				chmax(R[id[t][id_l[t]]+1],id[t][id_r[t]-1]+1);
				chmax(R[id[t][id_l[t]+1]+1],inf);
			}
		}
		while(d<p.sc){
			id_r[a[d]]++;
			int t=a[d];
			if(id_r[t]-id_l[t]>=2){
				chmax(R[0],id[t][id_r[t]-2]+1);
				chmax(R[id[t][id_l[t]]+1],id[t][id_r[t]-1]+1);
				chmax(R[id[t][id_l[t]+1]+1],inf);
			}
			d++;
		}
	}
	int ret=inf,r=0;
	for(int i=0;i<n;i++){
		chmax(r,R[i]);
		ret=min(ret,r-i);
	}
	cout<<ret<<endl;
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		for(int i=0;i<m;i++)scanf("%d%d",&l[i],&r[i]);
		solve();
	}
}