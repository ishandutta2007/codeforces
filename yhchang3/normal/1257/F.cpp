#include<bits/stdc++.h>
using namespace std;

int u[100],d[100];

map<vector<int>,int> m;

int cnt[1<<15];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0,x;i<n;i++){
		cin>>x;
		u[i]=x>>15;
		d[i]=x&((1<<15)-1);
	}
	for(int i=0;i<1<<15;i++){
		int x=i;
		while(x){
			if(x&1)	cnt[i]++;
			x>>=1;
		}
	}
	for(int i=0;i<1<<15;i++){
		vector<int> v(n);
		for(int j=0;j<n;j++)
			v[j]=cnt[i^d[j]];
		m[v]=i;
	}
	for(int i=0;i<1<<15;i++){
		vector<int> v(n);
		for(int sum=0;sum<=30;sum++){
			for(int j=0;j<n;j++)
				v[j]=sum-cnt[i^u[j]];
			if(m.find(v)!=m.end()){
				cout<<(i<<15|m[v])<<endl;
				return 0;
			}
		}
	}
	
	cout<<-1<<endl;
}