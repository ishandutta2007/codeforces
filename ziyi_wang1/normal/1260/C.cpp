#include<bits/stdc++.h>
using namespace std;
#define re register int
#define IN inline int
int n,m,T,p,k;
IN Gcd(int x,int y){
	return !y?x:Gcd(y,x%y);
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		if(n<m)swap(n,m);
		p=Gcd(n,m);
		n/=p;m/=p;
		if(n%m==0)p=(n-1)/m;
		else {
			if((n-1)%m==0)p=(n-1)/m;
			else p=((n-1)/m)+1;
		}
		if(p>=k)cout<<"REBEL"<<endl;
		else cout<<"OBEY"<<endl;
	}
    return 0;
}