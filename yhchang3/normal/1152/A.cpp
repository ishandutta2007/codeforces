#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,cnt1=0,cnt2=0;
	cin>>n>>m;
	for(int i=0,x;i<n;i++){
		cin>>x;
		if(x&1)	cnt1++;
	}
	for(int i=0,x;i<m;i++){
		cin>>x;
		if(x&1)	cnt2++;
	}
	cout<<min(cnt1,m-cnt2)+min(n-cnt1,cnt2)<<endl;
}