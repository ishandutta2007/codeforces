#include<bits/stdc++.h>
using namespace std;

int ok(int x){
	if(x%400==0)	return 2;
	if(x%4==0){
		if(x%100)	return 2;
		else	return 1;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int cnt=0;
	for(int i=n+1;;i++){
		cnt+=ok(i);
		cnt%=7;
		if(cnt==0&&ok(i)==ok(n)){
			cout<<i<<endl;
			return 0;
		}
	}
}