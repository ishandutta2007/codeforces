#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int main(){
	cin>>n;
	for (int i=1;i<n;i++){
		for (int j=i+1;j<=n;j++){
			if (i*i+j*j>n*n){
				break;
			}
			int t=sqrt(i*i+j*j);
			if (t*t==i*i+j*j){
				ans++;
			}
		}
	}
	cout<<ans;
}