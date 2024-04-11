#include<iostream>
#include<cstdio>
using namespace std;
long long a,b,x,i;
int main(){
	cin>>a>>b;
	if(b-a>20)return puts("0"),0;
	for(i=a+1,x=1;i<=b;++i)x=x*(i%10)%10;
	return cout<<x<<endl,0;
}