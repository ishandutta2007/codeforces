#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int d;
		cin>>d;
		if(d==1||d==3||d==2){
			cout<<'N'<<endl;
		}
		else{
			cout<<'Y'<<' '<<fixed<<setprecision(10)<<(d+sqrt(d*d-d*4))/2<<' '<<(d-sqrt(d*d-d*4))/2<<endl;
		}
	}
}