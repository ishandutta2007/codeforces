#include<bits/stdc++.h>
using namespace std;

string s[20],t[20];

string ans[1000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<m;i++)
		cin>>t[i];
	for(int i=0;i<n*m;i++)
		ans[i]=s[i%n]+t[i%m];
	int q;
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		x--;
		cout<<ans[x%(n*m)]<<'\n';
	}
}