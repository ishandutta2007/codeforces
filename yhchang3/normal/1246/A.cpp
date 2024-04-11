#include<bits/stdc++.h>
using namespace std;

int c(int x){
	int cnt=0;
	while(x){
		if(x&1)
			cnt++;
		x>>=1;
	}
	return cnt;
}

int main(){
	int n,p;
	cin>>n>>p;
	for(int i=1;i<=32;i++)
		if(n-i*p>=0&&c(n-i*p)<=i&&n-i*p>=i){
			cout<<i<<endl;
			return 0;
		}
	cout<<-1<<endl;
}