#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector <pair <int, int>> v[100001];
class segment_tree{
public:
	using pointer=segment_tree*;
	int l, r, m;
	vector <pair <int, int>> key;
	pointer left, right;
	void merge(vector <pair <int, int>> &a, vector <pair <int, int>> &b, vector <pair <int, int>> &c){
		c.clear();
		int i=0, j=0;
		while((i<a.size())&&(j<b.size())){
			if(a[i].first<b[j].first){
				c.push_back(a[i]);
				c.back().second=max(c.back().second, b[j].second);
				i++;
			}
			else{
				c.push_back(b[j]);
				c.back().second=max(c.back().second, a[i].second);
				if(a[i].first==b[j].first) i++;
				j++;
			}
		}
	}
	segment_tree(int l, int r): l(l), r(r){
		m=(l+r)/2;
		if(l==r){
			sort(v[l].begin(), v[l].end(), [](pair <int, int> A, pair <int, int> B){
				return (A.first<B.first)||((A.first==B.first)&&(A.second>B.second));
			});
			for(auto p: v[l]){
				while((!key.empty())&&(key.back().second>=p.second)) key.pop_back();
				key.push_back(p);
			}
		}
		else{
			left=new segment_tree(l, m);
			right=new segment_tree(m+1, r);
			merge(left->key, right->key, key);
		}
	}
	bool test(int x, int y){
		if(key.back().first<x) return 0;
		auto it=lower_bound(key.begin(), key.end(), make_pair(x, -1));
		return it->second<=y;
	}
	bool check(int u, int v, int x, int y){
		if(l>v||r<u) return 1;
		if(u<=l&&v>=r) return test(x, y);
		else{
			if(left->check(u, v, x, y)) return right->check(u, v, x, y);
			return 0;
		}
	}
};
segment_tree::pointer tree;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1, l, r, p; i<=k; i++){
		cin>>l>>r>>p;
		v[p].push_back({l, r});
	}
	tree=new segment_tree(1, n);
	for(int i=1, a, b, x, y; i<=m; i++){
		cin>>a>>b>>x>>y;
		auto res=tree->check(a, b, x, y);
		if(res) cout<<"yes\n";
		else cout<<"no\n";
		cout.flush();
	}
}