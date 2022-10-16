#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int k, n, m;
int a[100001];
pair <int, int> mx[100001];
class item{
public:
	double value;
	int id;
	item(ll top, ll bot, int id): id(id){value=((double)top)/bot;}
	bool operator < (item I){
		return value>I.value;
	}
};
vector <item> all;
vector <pair <int, int>> add[100001];
int type[100001];
vector <int> chosen;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>k>>n>>m;
	for(int i=1; i<=k; i++) cin>>a[i];
	for(int j=1, t, i, b; j<=n; j++){
		cin>>t>>i>>b;
		type[j]=t;
		if(t==3) all.push_back(item(b, 1, j));
		else if(t==2)	add[i].push_back({b, j});
		else mx[i]=max(mx[i], make_pair(b, j));
	}
	for(int i=1; i<=k; i++){
		if(mx[i].first>a[i]) add[i].push_back({mx[i].first-a[i], mx[i].second});
		sort(add[i].begin(), add[i].end());
		reverse(add[i].begin(), add[i].end());
		ll temp=a[i];
		for(auto &x: add[i]){
			all.push_back(item(temp+x.first, temp, x.second));
			temp+=x.first;
		}
	}
	sort(all.begin(), all.end());
	for(int i=0; i<m; i++){
		if(i>=all.size()) break;
		chosen.push_back(all[i].id);
	}
	sort(chosen.begin(), chosen.end(), [](int a, int b){
		return type[a]<type[b];
	});
	cout<<chosen.size()<<'\n';
	for(auto &x: chosen) cout<<x<<' ';
	
}