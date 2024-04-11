#include <bits/stdc++.h>
#define SIZE 200005
using namespace std;
typedef long long int ll;

struct BIT{
	int bit[SIZE];
	int sz;
	
	void init(int n){
		sz=n+2;
		for(int i=0;i<sz;i++) bit[i]=0;
	}
	void add(int k,int x){
		k++;
		while(k<sz){
			bit[k]+=x;
			k+=k&-k;
		}
	}
	int get(int k){
		k++;
		int ret=0;
		while(k>0){
			ret+=bit[k];
			k-=k&-k;
		}
		return ret;
	}
	int get(int s,int t){
		return get(t)-get(s-1);
	}
}bit;
int A[SIZE],pos[SIZE];
void solve(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
		A[i]--;
		pos[A[i]]=i;
	}
	bit.init(n);
	ll ret=0;
	for(int i=n-1;i>=0;i--){
		if(i+1<n){
			int d=0;
			if(pos[i]<pos[i+1]){
				d=bit.get(pos[i],pos[i+1]-1);
			} else{
				d=(n-i-1)-bit.get(pos[i+1],pos[i]);
			}
			ret+=(ll) d*(i+1);
		}
		bit.add(pos[i],1);
	}
	printf("%lld\n",ret);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
}