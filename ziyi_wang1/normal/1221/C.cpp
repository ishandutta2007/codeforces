#include<bits/stdc++.h>
using namespace std;
int n,m,w,T;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>w;
		if(n>m)swap(n,m);
		w+=(m-n);m=n;
		if(w>=n)cout<<n<<endl;
		else cout<<((n+m+w)/3)<<endl;
	}
    return 0;
}