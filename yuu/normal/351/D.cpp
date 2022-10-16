#include <bits/stdc++.h>
using namespace std;
class segment_tree{
public:
	using pointer=segment_tree*;
	int l, r, m;
	int cover;
	pointer left, right;
	segment_tree(int l, int r): l(l), r(r){
		m=(l+r)/2;
		cover=0;
		if(l!=r){
			left=new segment_tree(l, m);
			right=new segment_tree(m+1, r);
		}
		else left=right=nullptr;
	}
	void update(int u, int v, int x){
		if(l>v||r<u) return;
		else if(u<=l&&v>=r){
			cover+=x;
		}
		else{
			left->update(u, v, x);
			right->update(u, v, x);
		}
	}
	bool check(int u){
		if(cover) return 0;
		if(l==r) return 1;
		if(m>=u) return left->check(u);
		else return right->check(u);
	}
};
segment_tree::pointer tree;
int ft[100001];
void update(int u, int x){
	for(; u>0; u-=u&-u) ft[u]+=x;
}
int get(int u){
	int res=0;
	for(; u<=100000; u+=u&-u) res+=ft[u];
	return res;
}
int n, q;
#define left Chino
int left[100001];
vector <int> pos[100001];
vector <pair <int, int>> add[100002];
vector <pair <int, int>> del[100002];
vector <pair <int, int>> que[100002];
int ans[100002];
int main(){
	cin>>n;
	tree=new segment_tree(1, n);
	for(int i=1, b; i<=n; i++){
		cin>>b;
		if(!pos[b].empty()) left[i]=pos[b].back();
		pos[b].push_back(i);
	}
	for(int i=1; i<=100000; i++) for(int j=0; j<pos[i].size(); j++){
		int lf=(j?pos[i][j-1]:0)+1;
		int rt=((j+1<pos[i].size())?pos[i][j+1]:(n+1))-1;
		add[pos[i][j]].push_back({lf, pos[i][j]});
		del[rt+1].push_back({lf, pos[i][j]});
	}
	for(int i=1; i<=100000; i++){
		for(int j=0; j+1<pos[i].size(); j++){
			int k=j+1;
			while((k+1<pos[i].size())&&(pos[i][k+1]-pos[i][k]==pos[i][k]-pos[i][k-1])) k++;
			int lf=(j?pos[i][j-1]:0)+1;
			int rt=((k+1<pos[i].size())?pos[i][k+1]:(n+1))-1;
			for(int l=j; l<=k; l++){
				add[pos[i][l]].push_back({lf, pos[i][l]});
				del[rt+1].push_back({lf, pos[i][l]});
			}
			j=k-1;
		}
	}
	cin>>q;
	for(int i=1, l, r; i<=q; i++){
		cin>>l>>r;
		que[r].push_back({l, i});
	}
	for(int r=1; r<=n; r++){
		update(left[r], -1);
		update(r, 1);
		for(auto x: add[r]) tree->update(x.first, x.second, 1);
		for(auto x: del[r]) tree->update(x.first, x.second, -1);
		for(auto x: que[r]){
			ans[x.second]=get(x.first)+tree->check(x.first);
		}
	}
	for(int i=1; i<=q; i++) cout<<ans[i]<<'\n';
}