#include<bits/stdc++.h>
using namespace std;
int n,m,T;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		if(n==m){
			cout<<"Alice"<<endl;
			continue;
		}
		if(n<m){
			if(n%3==0){
				cout<<"Bob"<<endl;
			}
			else cout<<"Alice"<<endl;
			continue;
		}
		if(m==3){
			if(n%4==0){
				cout<<"Bob"<<endl;
			}
			else cout<<"Alice"<<endl;
			continue;
		}
		if(m%3==1||m%3==2){
			if(n%3==0){
				cout<<"Bob"<<endl;
			}
			else cout<<"Alice"<<endl;
			continue;
		}
		if(n<=(m<<1)){
			if(n%3==1)cout<<"Bob"<<endl;
			else cout<<"Alice"<<endl;
			continue;
		}
		n-=(m<<1);
		n%=(m+1);
		if(n%3==2)cout<<"Bob"<<endl;
		else cout<<"Alice"<<endl;
	}
    return 0;
}