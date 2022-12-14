#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	int n;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(i==n-1){
			s[i]='0';
			break;
		}
		if(s[i]>s[i+1]){
			s[i]='0';
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]!='0')
			cout<<s[i];
	}
	cout<<endl;
}