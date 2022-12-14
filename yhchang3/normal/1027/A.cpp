#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		string s;
		int n;
		cin>>n;
		cin>>s;
		for(int i=0;i<n/2;i++){
			if(abs(s[i]-s[n-i-1])!=0&&abs(s[i]-s[n-i-1])!=2){
				cout<<"NO"<<endl;
				break;
			}
			if(i==n/2-1)
				cout<<"YES"<<endl;
		}
	}
}