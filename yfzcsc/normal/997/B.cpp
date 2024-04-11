#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
long long cal(int n){
	set<int>st;
	int ans=0;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
			for(int k=0;k<=n;++k)
				if(i+j+k<=n)ans++,st.insert(i*5+10*j+50*k+(n-i-j-k));
	return st.size();
}
typedef pair<int,int> pii;
long long sol(int n){
	long long ans=0;
	for(int i=0;i<9;++i)
		for(int j=0;j<9;++j)
			ans+=max(0,n-i-j+1);
	return ans;
}
int main(){
	scanf("%d",&n);
	if(n<=30)printf("%lld",cal(n));
	else {
		long long gt=cal(30)-sol(30);
//		printf("[%lld]",cal(n));
		printf("%lld",sol(n)+gt-32ll*(n-30));
	}
}