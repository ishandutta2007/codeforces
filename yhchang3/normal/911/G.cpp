#include<bits/stdc++.h>
using namespace std;

const int M = 2e5+10;

vector<pair<int,pair<int,int>>> in[M],out[M];

int a[M];

int f[610000][101];
int base;
int q;
void modify(int Q,int x,int y){
	int idx=Q+base;
	f[idx][x]=y;
	idx>>=1;
	while(idx){
		int lson=idx<<1,rson=idx<<1|1;
		for(int i=1;i<=100;i++)
			f[idx][i]=f[rson][f[lson][i]];
		idx>>=1;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l,r,x,y;
	for(int i=1;i<=100;i++)
		for(int j=1;j<=600000;j++)
			f[j][i]=i;
	cin>>q;
	base=1;
	while(base<q)	base*=2;
	for(int i=1;i<=q;i++){
		cin>>l>>r>>x>>y;
		in[l].emplace_back(make_pair(i-1,make_pair(x,y)));
		out[r].emplace_back(make_pair(i-1,make_pair(x,x)));
	}
	for(int i=1;i<=n;i++){
		for(auto& it:in[i])
			modify(it.first,it.second.first,it.second.second);
		cout<<f[1][a[i]]<<' ';
		for(auto& it:out[i])
			modify(it.first,it.second.first,it.second.second);
	}
	cout<<endl;
}