#include <bits/stdc++.h>
using namespace std;
long long count(long long x){
	if(x<10) return x+1;
	long long ans=10;
	if(x<100){
		ans+=x/11;
		return ans;
	}
	ans+=9;
	for(int len=3; len<=18; len++){
		for(int d=1; d<10; d++){
			long long low=0, high=1, mid, res=-1;
			for(int i=2; i<len; i++) high*=10;
			high--;
			while(low<=high){
				mid=(low+high)/2;
				long long now=d;
				for(int i=2; i<len; i++) now=now*10;
				now+=mid;
				now=now*10+d;
				if(now<=x){
					res=mid;
					low=mid+1;
				}
				else high=mid-1;
			}
			ans+=res+1;
		}
	}
	return ans;
}
int main(){
	long long l, r;
	cin>>l>>r;
	cout<<count(r)-count(l-1)<<'\n';
}