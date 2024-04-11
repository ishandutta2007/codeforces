#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];
int b[100010];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	sort(a,a+n);
	int sum=0;
	for(int i=0;i<n;i++)sum+=a[i];
	
	for(int i=0;i<sum%n;i++){
		b[n-1-i]=sum/n+1;
	}
	for(int i=sum%n;i<n;i++){
		b[n-1-i]=sum/n;
	}
	
	int cnt=0;
	for(int i=0;i<n;i++){
		cnt+=abs(a[i]-b[i]);
	}
	cout<<cnt/2<<endl;
}