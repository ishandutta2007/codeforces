#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld PI=2.0*acos((ld)(0.0));

int main(){
	cout.precision(20);
	ld x[2],y[2],r[2];
	for(int i=0;i<2;i++)cin>>x[i]>>y[i]>>r[i];
	if(r[0]>r[1]){
		swap(x[0],x[1]);
		swap(y[0],y[1]);
		swap(r[0],r[1]);
	}
	
	ld d=sqrt((x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0]));
	if(d>=r[0]+r[1]-1e-9){
		puts("0.0");
		return 0;
	}
	else if(d<=r[1]-r[0]+1e-9){
		cout<<PI*r[0]*r[0]<<endl;
		return 0;
	}
	else {
		ld min_x=max(-r[0],d-r[1]),max_x=r[0];
		for(int i=0;i<100;i++){
			ld mid_x=(min_x+max_x)/2.0;
			ld h0=sqrt(r[0]*r[0]-mid_x*mid_x);
			ld h1=sqrt(r[1]*r[1]-(d-mid_x)*(d-mid_x));
			if(h0<h1)max_x=mid_x;
			else min_x=mid_x;
			if(i==99){
				ld theta0=atan2(h0,mid_x);
				ld theta1=atan2(h1,d-mid_x);
				ld ret=0.0;
				//cout<<mid_x<<endl;
				//cout<<theta0<<" "<<theta1<<endl;
				ret+=theta0*r[0]*r[0]-0.5*r[0]*r[0]*sin(2*theta0);
				ret+=theta1*r[1]*r[1]-0.5*r[1]*r[1]*sin(2*theta1);
				cout<<ret<<endl;
			}
		}
	}
}