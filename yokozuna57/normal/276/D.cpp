#include<iostream>
using namespace std;

int main(){
	long long int a,b,e[62],ans=0;
	int c[62],d[62];
	e[0]=1;
	for(int i=1;i<62;i++)e[i]=e[i-1]*2;
	cin>>a>>b;
	for(int i=0;i<62;i++){
		c[i]=a%2;
		d[i]=b%2;
		a=(a-c[i])/2;
		b=(b-d[i])/2;
	}
	for(int i=61;i>-1;i--)if(c[i]!=d[i]){ans=e[i+1]-1; break;}
	cout<<ans<<endl;
}