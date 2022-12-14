#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=1e9;;i/=10)
		if(n/i){
			cout<<(n/i+1)*i-n<<endl;
			break;
		}
}