#include <bits/stdc++.h>
#define left Kafuu
#define right Chino
using namespace std;
int n, k;
int a[1000000];
int left[1000000];
int right[1000000];
deque <int> q;
const int base=1000000007;
int sum[1000003];
int cnt[1000003];
long long get_count(int left, int right){
	if(left>right) swap(left, right);
	//length=0 to left+1 ->counted length time
	long long ans=sum[left+1];
	//length=left+2 to right+1 -> counted left+1
	ans+=(((long long)(cnt[right+1]-cnt[left+1]))*(left+1))%base;
	//length=right+1 to left+right+1 -> counted left+right+1 - len +1
	ans+=(((long long)(cnt[right+left+1]-cnt[right+1]))*(right+left+2))%base;
	ans-=(sum[right+left+1]-sum[right+1])%base;
	ans%=base;
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	k--;
	for(int i=2; i<=n+2; i++){
		sum[i]=sum[i-1];
		if(i%k==1%k) sum[i]+=i;
		while(sum[i]>=base) sum[i]-=base;
	}
	cnt[k+1]=0;
	for(int i=k+1; i<=n+2; i++){
		cnt[i]=cnt[i-1];
		if(i%k==1%k) cnt[i]++;
	}
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<n; i++){
		while((!q.empty())&&(a[i]>a[q.back()])) q.pop_back();
		if(q.empty()) left[i]=0;
		else left[i]=q.back()+1;
		q.push_back(i);
	}
	q.clear();
	for(int i=n-1; i>=0; i--){
		while((!q.empty())&&(a[i]>=a[q.back()])) q.pop_back();
		if(q.empty()) right[i]=n-1;
		else right[i]=q.back()-1;
		q.push_back(i);
	}
	long long ans=0;
	for(int i=0; i<n; i++) ans=(ans+get_count(i-left[i], right[i]-i)*a[i])%base;
	ans=(ans+base)%base;
	cout<<ans<<'\n';
}

/*
a0, a1, a2, ...., an
max(a0, a1) max(a1, a2), ...., max(an-1, an)
max(a0, a1, a2), ...., max(an-2, an-1, an)
every number will be calculated at max of 2, 3, ..., n-1 element

max(a0, a1, a2) max(a1, a2, a3), max(a2, a3, a4)...., max(an-1, an)
[0, 2], [1, 3], [2, 4], ....
[0, 4], [1, 5], [2, 6], ....
[0, 4], [1, 5], ...
each time gain k-1 more element 

max(a0, a1, a2, a3, a4), max(a1, ..., a6) max(a2, .., a7)
max[0, k-1], ...max[k-1, 2k-2]

for each element a[i], suppose the range it is maximum is l[i] to r[i]
*/