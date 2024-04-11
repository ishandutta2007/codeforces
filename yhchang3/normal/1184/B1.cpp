#include<bits/stdc++.h>
using namespace std;

int sp[100000];
vector<int> v;
pair<int,int> base[100000];
map<int,int> m;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int s,b;
	cin>>s>>b;
	for(int i=0;i<s;i++)
		cin>>sp[i];
	for(int i=0;i<s;i++)
		v.emplace_back(sp[i]);
	sort(v.begin(),v.end());
	for(int i=0;i<b;i++)
		cin>>base[i].first>>base[i].second;
	sort(base,base+b);
	int p=0;
	int ans=0;
	for(int i=0;i<s;i++){
		while(p!=b&&v[i]>=base[p].first)
			ans+=base[p++].second;
		m[v[i]]=ans;
	}
	for(int i=0;i<s;i++)
		cout<<m[sp[i]]<<' ';
	cout<<endl;
}