#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int r,b,g;
		cin>>r>>g>>b;
		if(r<=g+b+1&&b<=r+g+1&&g<=r+b+1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}