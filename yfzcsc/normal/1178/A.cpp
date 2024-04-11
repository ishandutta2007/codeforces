#include<bits/stdc++.h>
using namespace std;
int n,a[100100];
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	int sum=0,sum2=0;
	for(int i=1;i<=n;++i)sum+=a[i];
	sum2+=a[1];
	for(int i=2;i<=n;++i)if(a[i]*2<=a[1])sum2+=a[i];
	if(sum2*2<=sum){
		printf("0");
	} else {
		vector<int> v;
		v.push_back(1);
		for(int i=2;i<=n;++i)if(a[i]*2<=a[1])v.push_back(i);
		printf("%d\n",v.size());
		for(auto a:v)printf("%d ",a);
	}
}