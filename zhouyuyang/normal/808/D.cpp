#include<map>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 1000005
#define ll long long 
using namespace std;
int n;
ll a[100005],b[100005],half;
map<ll,int> mp;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	half=b[n]/2;
	if (2*half!=b[n]){
		puts("NO");
		return 0;
	}
	for (int i=1;i<=n;i++) mp[a[i]]++;
	mp[0]++;
	for (int i=1;i<=n;i++){
		mp[a[i]]--;
		mp[-a[i]]++;
		if (mp[half-b[i]]){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}