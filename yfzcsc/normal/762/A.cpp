#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000100],top;
int main(){
	cin>>n>>k;
	for(long long i=1;i*i<=n;++i)if(n%i==0){
		a[++top]=i;
		if(i*i!=n)a[++top]=n/i;
	}
	if(top<k)cout<<-1;
	else nth_element(a+1,a+k,a+top+1),cout<<a[k];
}