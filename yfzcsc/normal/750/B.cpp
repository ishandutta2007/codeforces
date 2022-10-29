#include<bits/stdc++.h>
using namespace std;
string dir;
int main(){
	int n,k,p=0;cin>>n;
	for(int i=1;i<=n;++i){
		cin>>k>>dir;
		if(dir=="North"){
			p=p-k;
			if(p<0){
				cout<<"NO";
				return 0;
			}
			
			
		}
		else if(dir=="South"){
			p=p+k;
			if(p>20000){
				cout<<"NO";
				return 0;
			}
		}
		else if(p==0||p==20000){
			cout<<"NO";
			return 0;
		}
	}
	if(p==0)cout<<"YES";
	else cout<<"NO";
}