#include<bits/stdc++.h>
using namespace std;
int cnt1,cnt2;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;

	for(int i=0,x;i<n;i++){
		cin>>x;
		if(x==1)
			cnt1++;
		else
			cnt2++;
	}
	if(cnt1==0||cnt2==0){
		for(int i=0;i<cnt1;i++)
			cout<<1<<' ';
		for(int i=0;i<cnt2;i++)
			cout<<2<<' ';
		cout<<endl;
	}
	else{
		cout<<2<<' '<<1<<' ';
		for(int i=1;i<cnt2;i++)
			cout<<2<<' ';
		for(int i=1;i<cnt1;i++)
			cout<<1<<' ';
		cout<<endl;
	}
		
}