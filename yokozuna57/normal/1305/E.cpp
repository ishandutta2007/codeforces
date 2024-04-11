#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second

int main(){
	int a[5002];
	for(int i=0;i<5002;i++){
		a[i]=4*i+1;
	}
	
	int n,m;
	cin>>n>>m;
	
	if(m==0){
		for(int j=0;j<n;j++){
			printf("%d%c",a[j],(j+1==n)?'\n':' ');
		}
		return 0;
	}
	
	int sum=0;
	int ret[5002];
	for(int i=0;i<n;i++){
		ret[i]=i+1;
		sum+=i/2;
		if(sum>=m){
			sum-=i/2;
			ret[i]=2*i-1-2*(m-sum-1);
			int X=ret[i]+ret[i-1]+1;
			for(int j=i+1;j<n;j++){
				ret[j]=X*a[j-(i+1)];
			}
			for(int j=0;j<n;j++){
				printf("%d%c",ret[j],(j+1==n)?'\n':' ');
			}
			return 0;
		}
	}
	puts("-1");
}