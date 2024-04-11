#include<bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int r,c;
	cin>>r>>c;
	if(r==1&&c==1){
		cout<<0<<endl;
	}
	else if(c==1){
		for(int i=1;i<=r;i++)
			cout<<i+1<<'\n';
	}
	else if(r==1){
		for(int i=1;i<=c;i++)
			cout<<i+1<<' ';
		cout<<endl;
	}
	else{
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++)
				cout<<i*(r+j)<<' ';
			cout<<'\n';
		}
	}
}