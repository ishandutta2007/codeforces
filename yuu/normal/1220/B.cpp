#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000][1000];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>a[i][j];
	long long t=a[0][1];
	t*=a[0][2];
	t/=a[1][2];
	long long p=sqrt(t);
	if(p<0) p=0;
	while(p*p<t) p++;
	cout<<p<<' ';
	for(int i=1; i<n; i++) cout<<a[0][i]/p<<" \n"[i==n];
}