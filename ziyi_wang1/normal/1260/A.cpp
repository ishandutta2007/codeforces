#include<bits/stdc++.h>
using namespace std;
int n,m,T,p,w,x,y,ans;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		p=m/n;
		w=p+1;
		y=m-(p*n);
		x=n-y;
		ans=(x*p*p)+(y*w*w);
		cout<<ans<<endl;
	}
    return 0;
}