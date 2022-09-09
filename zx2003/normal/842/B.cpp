#include<iostream>
using namespace std;
int r,d,i,n,x,y,ans,rr,dd;
int main(){
	cin>>r>>d>>n;
	d=r-d;
	for(i=1;i<=n;++i){
		cin>>x>>y>>rr;
		dd=x*x+y*y;
		ans+=(d+rr)*(d+rr)<=dd && dd<=(r-rr)*(r-rr);
	}
	cout<<ans<<endl;
	return 0;
}