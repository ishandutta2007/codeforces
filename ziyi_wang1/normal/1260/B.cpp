#include<bits/stdc++.h>
using namespace std;
int n,m,T;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		if(n<m)swap(n,m);
		if(((n+m)%3!=0)||((n*2-m)%3!=0)||((m*2-n)%3!=0)||(m*2-n<0))cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
    return 0;
}