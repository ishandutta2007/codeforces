#include<bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	map<int,int> m;
	for(int i=1;i<=k+1;i++){
		cout<<"?";
		for(int j=1;j<=k+1;j++)
			if(i!=j)
				cout<<' '<<j;
		cout<<endl;
		int p,x;
		cin>>p>>x;
		m[x]++;
	}
	cout<<"! "<<prev(m.end())->second<<endl;
}