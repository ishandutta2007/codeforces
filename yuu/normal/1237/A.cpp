#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n;
	for(int i=1, a, cnt=0; i<=n; i++){
		cin>>a;
		if(a%2==0){
			cout<<a/2<<'\n';
		}
		else{
			int x=a/2;
			if(x*2+1!=a) x--;
			if(cnt){
				cnt=0;
				cout<<x+1<<'\n';
			}
			else{
				cnt=1;
				cout<<x<<'\n';
			}
		}
	}
	
}