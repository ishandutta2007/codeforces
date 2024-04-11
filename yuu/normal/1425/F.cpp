#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n+1];
	a[0]=0;
	for(int i=2; i<=n; i++){
		cout<<"? 1 "<<i<<endl;
		cin>>a[i];
	}
	cout<<"? 2 "<<n<<endl;
	cin>>a[1];
	a[1]=a[n]-a[1];
	for(int i=n; i>=2; i--) a[i]-=a[i-1];
	cout<<"!";
	for(int i=1; i<=n; i++) cout<<" "<<a[i];
	cout<<endl;
}