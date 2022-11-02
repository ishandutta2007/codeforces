#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int a[4];
		for(int i=0;i<4;i++)cin>>a[i];
		if(a[0]==a[1]||a[2]==a[3])cout<<"NO"<<endl;
		else{
			sort(a,a+4);
			if(a[3]==a[2]&&a[0]+a[1]==a[2])cout<<"YES"<<endl;
			else cout<<"No"<<endl;
		}
	}
}