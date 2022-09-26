#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int cur[555555]; //cur[x] stores a position which contains the value x

struct DSU {
	vector<int> e;
	vector<int> v;
	DSU(int N) {
		e = vector<int> (N, -1);
		v = vector<int> (N, -1);
	}
	int get(int x) {
		if (e[x] < 0)
			return x;
		else
			return e[x] = get(e[x]);
	}
	bool sameset(int a, int b) {
		return get(a) == get(b);
	}
	int size(int x) {
		return -e[get(x)];
	}
	int value(int x){
		return v[get(x)];
	}
	bool unite(int x, int y) { //change all occurrences of position x's value to position y's value
		x = get(x);
		y = get(y);
		int newval = v[y];
		cur[v[x]]=cur[v[y]]=-1;
		v[x]=v[y]=newval;
		cur[newval]=y;
		if (x == y)
			return false;
		
		if (e[x] > e[y])
			swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q; cin>>q;
	int id=0; DSU dsu(q); memset(cur,-1,sizeof(cur));
	for(int z=0;z<q;z++)
	{
		/*
		cout<<"STEP "<<z<<": ";
		for(int i=0;i<id;i++)
		{
			cout<<dsu.value(i);
			if(i+1<id) cout<<' ';
		}
		cout<<'\n';
		*/
		int t; cin>>t;
		if(t==1)
		{
			int x; cin>>x; 
			dsu.v[id]=x;
			if(cur[x]!=-1){
				dsu.unite(cur[x],id);
			}
			cur[x]=id++; 
		}
		else
		{
			int x,y; cin>>x>>y;
			if(cur[x]==-1) continue;
			if(cur[y]==-1){
				int r = dsu.get(cur[x]);
				cur[dsu.v[r]]=-1; //change value at this position
				dsu.v[r] = y;
				cur[y]=r;
				continue;
			}
			dsu.unite(cur[x],cur[y]);
		}
		
	}
	for(int i=0;i<id;i++)
	{
		cout<<dsu.value(i);
		if(i+1<id) cout<<' ';
	}
	cout<<'\n';
}