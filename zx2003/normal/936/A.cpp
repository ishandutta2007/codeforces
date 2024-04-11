#include<bits/stdc++.h>
using namespace std;
long long k,d,t,z,y,w;
int main(){
	cin>>k>>d>>t;
	z=(k-1)/d+1;z=d*z-k;
	y=2*t/(2*k+z);w=2*t%(2*k+z);
	if(w<=2*k)printf("%.10f\n",y*1.0*(k+z)+w/2.0);
		else printf("%.10f\n",y*1.0*(k+z)+k+(w-2*k));
	return 0;
}