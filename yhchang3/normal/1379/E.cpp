#include<bits/stdc++.h>
using namespace std;

int p[100010];
int cnt;

int solve0(int n){
	if(n==1)	return ++cnt;
	int l = solve0(n/2), r = solve0(n/2);
	p[l]=p[r]=cnt+1;
	return ++cnt;
}

int solve1(int n){
	int base = 1 << (31 - __builtin_clz(n)), l, r;
	if(n+1 == base * 3 / 2)
		l = solve0(base-1), r = solve0(base/2-1);
	else if((base/2)&n)
		l = solve0(base-1), r = solve1(n-base);
	else
		l = solve0(base/2-1), r = solve1(n-base/2);
	p[l]=p[r]=cnt+1;
	return ++cnt;
}

int solve(int n,int k){
	if(k==1)	return solve1(n);
	int rem = n - (k-1)*2;
	if(rem&(rem+1)){
		int s=solve(n-2,k-1);
		p[s]=cnt+1;
		p[cnt+2]=cnt+1;
		cnt+=2;
		return p[s];
	}
	else{
		int s=solve(n-4,k-1);
		p[s]=cnt+1;
		p[cnt+2]=cnt+1;
		p[cnt+3]=p[cnt+4]=cnt+2;
		cnt+=4;
		return p[s];
	}
}

void fail(){
	cout<<"NO"<<endl;
	exit(0);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	if(n==9&&k==2)	fail();
	if(n%2==0)	fail();
	if(k==0){
		if(n&(n+1))	fail();
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
			cout<<(i/2)<<' ';
		return 0;
	}
	if(k==1&&!(n&(n+1)))	fail();
	if((n-3)/2<k)	fail();
	cout<<"YES"<<endl;
	solve(n,k);
	for(int i=1;i<=n;i++)
		cout<<p[i]<<' ';
	cout<<endl;
}