#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,t;

int main(){
	cin>>n>>k;
	t=n/k;
	if (t&1){
		printf("YES");
	}else{
		printf("NO");
	}
}