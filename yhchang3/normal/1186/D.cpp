#include<bits/stdc++.h>
using namespace std;

double a[100001];
int b[100001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=(int) a[i];
	long long int res = 0;
	for(int i=1;i<=n;i++)
		res+=b[i];
	for(int i=1;i<=n;i++){
		if(res<=0)	break;
		if(b[i]>a[i])	b[i]--,res--;
	}
	for(int i=1;i<=n;i++){
		if(res>=0)	break;
		if(b[i]<a[i])	b[i]++,res++;
	}
	for(int i=1;i<=n;i++)
		cout<<b[i]<<'\n';
}