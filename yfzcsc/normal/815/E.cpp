#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
int main(){
	scanf("%lld%lld",&n,&k);
	if(k==1)return printf("1"),0;
	if(k==2)return printf("%lld",n),0;
	n-=2,k-=3;
	map<ll,ll>f,g,nxt;
	g[n]=1;
	while(g.size()){
		nxt.clear();
		for(auto s:g)if(s.first)
			f[-((s.first-1)>>1)]+=s.second,
			nxt[(s.first)>>1]+=s.second,
			nxt[(s.first-1)>>1]+=s.second;
		g=nxt;
	}
	for(auto s:f){
		//printf("[%d]",s.first);
		if(s.second>k){
			ll l=1,r=n,len=-s.first;
//			printf("[%d]",len);
			while(true){
				if(((r-l)>>1)==len&&k==0)
					return printf("%lld",((r-l)>>1)+1+l),0;
				map<ll,ll>A,B,C;
				ll mid=l+r>>1;
				A[mid-l]=1;
				B[(r-l)>>1]=1;
				while(A.size()){
					C.clear();
					for(auto qs:A)if(qs.first)
						B[(qs.first-1)>>1]+=qs.second,
						C[(qs.first)>>1]+=qs.second,
						C[(qs.first-1)>>1]+=qs.second;
					A=C;
				}
			//	printf("[%d]",B[len]);
				if(B[len]>k)r=mid-1;
				else l=mid+1,k-=B[len];
			}
		} else k-=s.second;
	}
}