#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int r;
	cin>>r;
	for(long long int x=1;x<=1000000;x++){
		if((r-x*x-x-1)>0&&(r-x*x-x-1)%(2*x)==0){
			cout<<x<<' '<<(r-x*x-x-1)/2/x<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
}