#include <bits/stdc++.h>
using namespace std;
int n, m, s, d;
vector <pair <int, int>> p;
int a[200001];
int main(){
	cin>>n>>m>>s>>d;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1, a+n+1);
	int pos=0;
	for(int i=1; i<=n; i++){
		p.push_back({0, a[i]-pos-1});
		if(p.back().second<s){
			cout<<"IMPOSSIBLE\n";
			return 0;
		}
		pos=a[i]-1;
		///jump
		int j=i;
		while((j<n)&&(a[j+1]-a[j]-2<s)) j++;
		p.push_back({1, a[j]+1-pos});
		if(p.back().second>d){
			cout<<"IMPOSSIBLE\n";
			return 0;
		}
		pos=a[j]+1;
		i=j;
	}
	if(pos<m) p.push_back({0, m-pos});
	for(auto &x: p){
		if(x.first) cout<<"JUMP ";
		else cout<<"RUN ";
		cout<<x.second<<'\n';
	}
}