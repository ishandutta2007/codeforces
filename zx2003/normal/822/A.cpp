#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll a,b,i,ans;
int main(){
	cin>>a>>b;
	if(a>b)swap(a,b);
	for(i=ans=1;i<=a;++i)ans*=i;
	cout<<ans<<endl;
	return 0;
}