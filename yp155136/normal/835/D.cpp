#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 5e3 + 6;
const int MAX_P = 13;

LL p1,p2,p3;
LL mod1,mod2,mod3;

LL pre1[MAX_N],pow1[MAX_N];
LL pre2[MAX_N],pow2[MAX_N];
LL pre3[MAX_N],pow3[MAX_N];
LL rev1[MAX_N];
LL rev2[MAX_N];
LL rev3[MAX_N];

const LL prime[10] = {1000000000+7,1000000000+9,244823041,69522569,410256793
,19131071,112345897,31556923,31622777,32457869};

LL Val(LL val,LL mod) {
	return (val%mod+mod)%mod;
}

int n;

bool same(int L1,int R1,int L2,int R2) {
//	cout<<"1 = "<<Val((pre1[R1]-pre1[L1-1])*pow1[max(0,L1-1 - (n-R2+1-1))],mod1)<<" , 2 = "<<Val((rev1[n-L2+1]-rev1[n-R2+1-1])*pow1[max(0,-(L1-1 - (n-R2+1-1)) )],mod1)<<endl;
	return Val((pre1[R1]-pre1[L1-1])*pow1[max(0,-((L1-1)-(n-(R2+1)+1)))],mod1)==Val((rev1[L2]-rev1[R2+1])*pow1[max(0,((L1-1)-(n-(R2+1)+1)))],mod1) &&
	       Val((pre2[R1]-pre2[L1-1])*pow2[max(0,-((L1-1)-(n-(R2+1)+1)))],mod2)==Val((rev2[L2]-rev2[R2+1])*pow2[max(0,((L1-1)-(n-(R2+1)+1)))],mod2) &&
	       Val((pre3[R1]-pre3[L1-1])*pow3[max(0,-((L1-1)-(n-(R2+1)+1)))],mod3)==Val((rev3[L2]-rev3[R2+1])*pow3[max(0,((L1-1)-(n-(R2+1)+1)))],mod3);
}

int dp[MAX_N][MAX_N];
bool dp_tmp[MAX_N][MAX_N];
int cnt[MAX_N];

int main () {
	srand(time(NULL));
	string s;
	cin >>s;
	s=" "+s;
	n=s.size()-1;
	p1=prime[rand()%10];
	p2=prime[rand()%10];
	p3=prime[rand()%10];
	mod1=prime[rand()%10];
	mod2=prime[rand()%10];
	mod3=prime[rand()%10];
	pow1[0] = 1;
	for (int i=1;n>=i;i++) {
		pow1[i] = pow1[i-1] * p1;
		pow1[i] %= mod1;
		pre1[i] = pre1[i-1] + s[i]*pow1[i];
		pre1[i] %= mod1;
	}
	pow2[0] = 1;
	for (int i=1;n>=i;i++) {
		pow2[i] = pow2[i-1] * p2;
		pow2[i] %= mod2;
		pre2[i] = pre2[i-1] + s[i]*pow2[i];
		pre2[i] %= mod2;
	}
	pow3[0] = 1;
	for (int i=1;n>=i;i++) {
		pow3[i] = pow3[i-1] * p3;
		pow3[i] %= mod3;
		pre3[i] = pre3[i-1] + s[i]*pow3[i];
		pre3[i] %= mod3;
	}
	for (int i=n;i>=1;i--) {
		rev1[i] = rev1[i+1] + s[i]*pow1[n-i+1];
		rev1[i] %= mod1;
	}
	for (int i=n;i>=1;i--) {
		rev2[i] = rev2[i+1] + s[i]*pow2[n-i+1];
		rev2[i] %= mod2;
	}
	for (int i=n;i>=1;i--) {
		rev3[i] = rev3[i+1] + s[i]*pow3[n-i+1];
		rev3[i] %= mod3;
	}
//	for (int i=0;n>=i;i++) {
//		cout<<(pre1[i] == rev1[n-i+1])<<endl;
//	}
//	cout<<"same(1,2,2,3) = "<<same(1,2,2,3)<<endl;
	for (int len=0;n>=len;len++) {
		for (int i=1;n>=i;i++) {
			int j=i+len;
			if (j>n) break;
			if (len==0) {
				dp[i][j] = 1;
			}
			else {
				int t=(j-i+1)/2;
				if (same(i,i+t-1,j-t+1,j)) {
					dp[i][j] = max(dp[i][i+t-1],dp[j-t+1][j]) + 1;
				}
			}
			cnt[dp[i][j]]++;
		}
	}
	
	for (int i=n;i>=1;i--) {
		cnt[i-1] += cnt[i];
	}
	for (int i=1;n>=i;i++) cout<<cnt[i]<<' ';
	cout<<endl;
}