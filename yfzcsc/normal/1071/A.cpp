#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>A,B;
ll a,b;
int chk(ll n){
//	printf("[%lld]",n);
	A.clear(),B.clear();
	ll xa=a,xb=b;
	while(xa>n&&n>0){
		xa-=n;
		A.push_back(n);
		n--;
	}
	if(!n)return 1;
	if(xa)A.push_back(xa);
	while(n){
		if(n!=xa)xb-=n,B.push_back(n);
		n--;
	}
	if(xb>=0)return 1;
	return 0;
}
int main(){
	cin>>a>>b;
	if(a==0&&b==0){
		printf("0\n0");
		return 0;
	}
	ll n=1;
	while((n+1)*(n+2)/2<=a+b)n++;
	while(!chk(n))n--;
	printf("%d\n",A.size());
	for(auto a:A)printf("%d ",a);
	printf("\n%d\n",B.size());
	for(auto b:B)printf("%d ",b);
}