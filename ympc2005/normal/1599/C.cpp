#include<bits/stdc++.h>
using namespace std;
long long n;double p;
double ck(long long x){
	long long y=n-x;
	long long s=n*(n-1)*(n-2)/6;
	double d[4];
	d[0]=y*(y-1)*(y-2)/6;
	d[1]=y*(y-1)/2*x;
	d[2]=y*x*(x-1)/2;
	d[3]=x*(x-1)*(x-2)/6;
	return (d[3]+d[2]+d[1]/2)/s;
}
int main(){
	cin>>n>>p;
	for(long long i=0;i<n;i++)
		if(ck(i)>=p){
			cout<<i;
			return 0;
		}
	return 0;
}