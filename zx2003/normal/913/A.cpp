#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	cin>>m>>n;
	if(m<=40)n&=(1ll<<m)-1;
	cout<<n<<endl;
	return 0;
}