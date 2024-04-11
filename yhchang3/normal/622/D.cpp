#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	if(n%2==0){
		for(int i=1;i<=n;i+=2)
			cout << i << ' ' ;
		for(int i=n-1;i>=1;i-=2)
			cout << i << ' ' ;
		for(int i=2;i<n;i+=2)
			cout << i << ' ' ;
		cout << n << ' ';
		for(int i=n-2;i>=1;i-=2)
			cout << i << ' ' ;
		cout << n << ' ';
	}
	else{
		for(int i=2;i<=n;i+=2)
			cout << i << ' ' ;
		for(int i=n-1;i>=1;i-=2)
			cout << i << ' ' ;
		for(int i=1;i<n;i+=2)
			cout << i << ' ' ;
		cout << n << ' ';
		for(int i=n-2;i>=1;i-=2)
			cout << i << ' ' ;
		cout << n << ' ';
	}
	cout << endl;
}