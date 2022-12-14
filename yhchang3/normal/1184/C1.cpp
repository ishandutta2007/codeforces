#include<bits/stdc++.h>
using namespace std;

int x[50],y[50];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int l=51,u=-1,r=-1,d=51;
	for(int i=1;i<=4*n+1;i++){
		cin>>x[i]>>y[i];
		l=min(l,x[i]);
		u=max(u,y[i]);
		d=min(d,y[i]);
		r=max(r,x[i]);
	}
	for(int i=1;i<=4*n+1;i++){
		int l=51,u=-1,r=-1,d=51;
		for(int j=1;j<=4*n+1;j++){
			if(i==j)	continue;
			l=min(l,x[j]);
			u=max(u,y[j]);
			d=min(d,y[j]);
			r=max(r,x[j]);
		}
		bool ok=true;
		for(int j=1;j<=4*n+1;j++){
			if(i==j)	continue;
			if(x[j]!=l&&x[j]!=r&&y[j]!=u&&y[j]!=d)
				ok=false;
		}
		if(u-d!=r-l)
			ok=false;
		if(ok){
			cout<<x[i]<<' '<<y[i]<<endl;
		}
	}
}