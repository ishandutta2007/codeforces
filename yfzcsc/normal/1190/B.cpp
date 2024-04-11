#include<bits/stdc++.h>
using namespace std;
int n,a[100100];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	map<int,int> st;
	for(int i=1;i<=n;++i)st[a[i]]++; 
	int ans1=0,ans2=0;
	for(auto a:st)ans1+=a.second>=2,ans2+=a.second>=3;
	if(st[0]>=2){
		puts("cslnb");
		return 0;
	}
	if(ans1>1||ans2){
		puts("cslnb");
		return 0;
	}
	long long sum=0;
	if(ans1==1){
		for(int i=1;i<=n;++i)sum+=a[i];
		if(!sum){
		    puts("cslnb");
		    return 0;
		}
		for(auto a:st)if(a.second>=2){
			if(st[a.first-1]==1){
			    puts("cslnb");
			    return 0;
			}
		} 
		sum--;
		long long x=sum-1ll*n*(n-1)/2;
		if(x&1)puts("cslnb");
		else puts("sjfnb");
	} else {
		for(int i=1;i<=n;++i)sum+=a[i];
		if(!sum){
		    puts("cslnb");
		    return 0;
		}
		long long x=sum-1ll*n*(n-1)/2;
		if(x&1)puts("sjfnb");
		else puts("cslnb");
	}
}