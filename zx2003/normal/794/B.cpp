#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
ll a,b,i,n,h;
double x;
int main(){
	cin>>n>>h;
	for(i=1;i<n;++i){
		printf("%.12f ",sqrt(h*h*i*1.0/n));
	}
	return 0;
}