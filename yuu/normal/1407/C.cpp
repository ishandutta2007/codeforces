#include <bits/stdc++.h>
using namespace std;
int n;
int res[10001];
int main(){
	cin>>n;
	int mx=1;
	for(int i=2, a, b; i<=n; i++){
		cout<<"? "<<i<<' '<<mx<<endl;
		cin>>a;
		cout<<"? "<<mx<<' '<<i<<endl;
		cin>>b;
		if(a>b) res[i]=a;
		else{
			res[mx]=b;
			mx=i;
		}
	}
	res[mx]=n;
	cout<<"! ";
	for(int i=1; i<=n; i++) cout<<res[i]<<" \n"[i==n];
	cout.flush();
}