#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
 
typedef long long LL;
const int MAX_N = 2e5 + 6;
const int MAX_T = 102;
const LL mod = 1e9+7;
 
LL dp[2][MAX_N]; //using slicing window XD
 
inline int f(int x) {
	return x+100001;
}
 
int main () {
	int a,b,k,t;
	while (scanf("%d %d %d %d",&a,&b,&k,&t) != EOF) {
		memset(dp,0,sizeof(dp));
		int low=-k;
		int high=k;
		dp[0][f(0)]=1;
		for (int i=1;t>=i;i++) {
			LL tmp=0; //for slicing window
			for (int j=low;high>=j;j++) {
				//cout<<"i="<<i<<" , j="<<j<<" ,tmp="<<tmp<<endl;
				if (0<=f(j-(k+1)) && f(j-(k+1)) < MAX_N) {
					tmp -= dp[(i-1)%2][f(j-(k+1))];
				}
				if (0<=f(j+k) && f(j+k)<MAX_N) {
					tmp += dp[(i-1)%2][f(j+k)];
				}
				tmp+=mod;
				dp[i%2][f(j)] = tmp%mod;
				tmp%=mod;
			}
			low-=k;
			high+=k;
		}
		/*for (int x=-2;2>=x;x++) {
		    cout<<dp[t%2][f(x)]<<endl;
		}*/
		LL ans=0;
		LL tmpa=a+k*t;
		LL tmpb=b-k*t;
		LL tmp=0;
		for (int i=tmpa;i>tmpb;i--) {
			//cout<<"i-a="<<i-a<<" , dp="<<dp[t%2][f(i-a)]<<endl;;
			if (0<=f(i-a) && f(i-a)<MAX_N) {
				tmp += dp[t%2][f(i-a)];
				ans += dp[t%2][f(i-a)];
			}
			ans %= mod;
			tmp %= mod;
		}
		tmpb++;
//		cout<<"tmp="<<tmp<<endl;
		while (tmpb<tmpa && tmpb<=b+k*t) {
//			cout<<"tmpb = "<<tmpb<<endl;
			if (0<=f(tmpb-a) && f(tmpb-a)<MAX_N)tmp -= dp[t%2][f(tmpb-a)];
			tmp += mod;
			tmp %= mod;
//			cout<<"tmp = "<<tmp<<endl;
			if (0<=f(b-tmpb) && f(b-tmpb)<MAX_N)ans += tmp*dp[t%2][f(b-tmpb)];
			ans %= mod;
			tmpb++;
		} 
		printf("%I64d\n",ans);
	}
}