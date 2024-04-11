#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,r;
	cin>>n>>m>>r;
	int x=2000,y=0;
	for(int i=0,u;i<n;i++){
		cin>>u;
		x=min(x,u);
	}
	for(int i=0,u;i<m;i++){
		cin>>u;
		y=max(y,u);
	}
	if(x<y){
		cout<<r-r/x*x+r/x*y<<endl;
	}
	else
		cout<<r<<endl;
}