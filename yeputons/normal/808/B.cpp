#include<bits/stdc++.h>
using namespace std;
int n,k;
double a[333333];
int main(){
	std::ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		a[i] += a[i-1];
	}
	double res=0;
	for(int i=k; i<=n; i++){
		res += (a[i] - a[i-k])/(n-k+1);
	}
	printf("%.12lf\n",res);
	return 0;
}