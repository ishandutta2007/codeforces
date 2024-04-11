#include<iostream>
using namespace std;

long long int gcd(long long int x,long long int y){
	if(y==0)return x;
	return gcd(y,x%y);
}

long long int lcm(long long int x,long long int y){
	y/=gcd(x,y);
	return x*y;
}

int main(){
	long long int x,y,a,b,ans,l;
	scanf("%I64d%I64d%I64d%I64d",&x,&y,&a,&b);
	l=lcm(x,y);
	ans=b/l-(a-1)/l;
	printf("%I64d\n",ans);
}