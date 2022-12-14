#include<bits/stdc++.h>
using namespace std;

vector<int> v[2][2];
int x[1000],y[1000];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>x[i]>>y[i];
	while(true){
		vector<int> v[2][2];
		for(int i=0;i<n;i++){
			v[abs(x[i])%2][abs(y[i])%2].emplace_back(i);
		}
		if(v[0][0].size()==n){
			for(int i=0;i<n;i++)
				x[i]/=2,y[i]/=2;
			continue;
		}
		if(v[0][1].size()==n){
			for(int i=0;i<n;i++)
				x[i]/=2,y[i]=(y[i]+1)/2;
			continue;
		}
		if(v[1][0].size()==n){
			for(int i=0;i<n;i++)
				x[i]=(x[i]+1)/2,y[i]/=2;
			continue;
		}
		if(v[1][1].size()==n){
			for(int i=0;i<n;i++)
				x[i]=(x[i]+1)/2,y[i]=(y[i]+1)/2;
			continue;
		}
		if(v[0][0].size()+v[1][1].size()==n){
			cout<<v[0][0].size()<<'\n';
			for(int it:v[0][0])
				cout<<it+1<<' ';
			cout<<'\n';
			return 0;
		}
		if(v[1][0].size()+v[0][1].size()==n){
			cout<<v[1][0].size()<<'\n';
			for(int it:v[1][0])
				cout<<it+1<<' ';
			cout<<'\n';
			return 0;
		}
		cout<<v[0][0].size()+v[1][1].size()<<'\n';
		for(int it:v[0][0])
			cout<<it+1<<' ';
		for(int it:v[1][1])
			cout<<it+1<<' ';
		cout<<'\n';
		return 0;
	}
	
}