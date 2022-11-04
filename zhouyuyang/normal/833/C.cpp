#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans,totl,totr;
int a[15],num[15];
int L[25],R[25];
ll l,r;
bool any(int l,int r){
	for (int i=l;i<=r;i++)
		if (num[i]) return 1;
	return 0;
}
bool dfs(int pos,int lf,int rf){
	if (pos==totr) return 1;
	int l=L[pos],r=R[pos];
	if (lf&&rf){
		if (l==r){
			if (num[l]){
				num[l]--;
				if (dfs(pos+1,1,1))
					return 1;
				num[l]++;
			}
			return 0;
		}
		if (any(l+1,r-1))
			return 1;
		if (num[l]){
			num[l]--;
			if (dfs(pos+1,1,0))
				return 1;
			num[l]++;
		}
		if (num[r]){
			num[r]--;
			if (dfs(pos+1,0,1))
				return 1;
			num[r]++;
		}
		return 0;
	}
	if (lf){
		if (any(l+1,9)) return 1;
		if (num[l]){
			num[l]--;
			if (dfs(pos+1,1,0))
				return 1;
			num[l]++;
		}
		return 0;
	}
	if (rf){
		if (any(0,r-1)) return 1;
		if (num[r]){
			num[r]--;
			if (dfs(pos+1,0,1))
				return 1;
			num[r]++;
		}
		return 0;
	}
	return 0;
}
void go(int n,int sum){
	if (n==10){
		memcpy(num,a,sizeof(num));
		num[0]=sum;
		//for (int i=0;i<10;i++)
		//	printf("%d ",num[i]);
		//puts("");
		if (dfs(0,1,1)) ans++;
		return;
	}
	for (int i=0;i<=sum;i++)
		a[n]=i,go(n+1,sum-i);
}
int main(){
	scanf("%lld%lld",&l,&r);
	if (l==r) return puts("1"),0;
	for (;l;l/=10) L[totl++]=l%10;
	for (;r;r/=10) R[totr++]=r%10;
	for (;totl<totr;) L[totl++]=0;
	reverse(L,L+totl); reverse(R,R+totr);
	go(1,totr);
	printf("%d",ans);
}