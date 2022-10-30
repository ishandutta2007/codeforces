/*
 * D. Beautiful numbers.cpp
 *
 *  Created on: 2011-2-26
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
const int MOD=252;
const int NSTATE=48;
const int MAX_LEN=21;
const int MAX_DIGIT=10;
typedef long long int64;
vector<int> factors;

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int lcm(int a,int b){
	return a/gcd(a,b)*b;
}

int idInFactors(int factor){
	return lower_bound(factors.begin(),factors.end(),factor)-factors.begin();
}

int64 memo[NSTATE][MOD][MAX_LEN];
int nextState[NSTATE][MAX_DIGIT];

int64 rec(int factorId,int mod2520,int len){
	if(len==0){
		int curFactor=factors[factorId];
		if(mod2520%curFactor == 0)
			return 1;
		else
			return 0;
	}
	int mod252=mod2520%252;
	int64&ans=memo[factorId][mod252][len];
	if(ans != -1)
		return ans;
	ans=0;
	for (int nextDigit = 0; nextDigit < 10; ++nextDigit) {
		int nextFactorId=nextState[factorId][nextDigit];
		int nextMod2520=mod252*10+nextDigit;
		ans+=rec(nextFactorId,nextMod2520,len-1);
	}
	return ans;
}

int64 countWithPrefix(int64 l,int64 pow){
	//count [l,l+pow)
	int64 prefix=l/pow;
	int64 x=prefix;
	int64 Lcm=1;
	while(x){
		int digit=x%10;
		x/=10;
		if(digit > 0)
			Lcm=lcm(digit,Lcm);
	}

	int factorId=idInFactors(Lcm);
	x=pow;
	int len=0;while(x/=10)len++;
	return rec(factorId,prefix%2520,len);
}

int64 countLower(int64 r){
	int64 l=0;++r;//[l,r)
	int64 ans=0;
	while(l<r){
		int64 pow=1;
		for(;;){
			if(pow>r/10)break;
			int64 nextPow=pow*10;
			if(l + nextPow <= r && l % nextPow == 0)
				pow=nextPow;
			else
				break;
		}
		ans+=countWithPrefix(l,pow);
		l+=pow;
	}

	return ans;
}

int64 countBeautiful(int64 l,int64 r){
	return countLower(r)-countLower(l-1);
}

void prepare(){
	int allLcm=1;
	for (int digit = 1; digit < 10; ++digit) {
		allLcm=lcm(allLcm,digit);
	}
	factors.clear();
	for (int x = 1; x <= allLcm; ++x) {
		if(allLcm % x == 0)
			factors.push_back(x);
	}

	for (int factorId = 0; factorId < factors.size(); ++factorId) {
		int curFactor=factors[factorId];
		for (int nextDigit = 0; nextDigit < 10; ++nextDigit) {
			int nextFactor;
			if(nextDigit == 0)
				nextFactor=curFactor;
			else
				nextFactor=lcm(curFactor,nextDigit);
			nextState[factorId][nextDigit]=idInFactors(nextFactor);
		}
	}
}

bool isBeautiful(int64 x){
	int64 cur=x;
	while(cur){
		int digit=cur%10;
		if(digit && x%digit != 0)
			return false;
		cur/=10;
	}
	return true;
}

int64 bruteCount(int64 l,int64 r){
	int64 ans=0;
	for(int64 x = l; x <= r; ++x)
		if(isBeautiful(x))
			++ans;
	return ans;
}

void solve(){
	prepare();
	memset(memo,-1,sizeof memo);
	int nTests;cin>>nTests;
	for (int cur = 0; cur < nTests; ++cur) {
		int64 l,r;
		cin>>l>>r;
		printf("%I64d\n",countBeautiful(l,r));
	}
}

void runTest(){
	prepare();
	memset(memo,-1,sizeof memo);
	int64 l,r;cin>>l>>r;
	cout<<countBeautiful(l,r)<<endl;
	cout<<bruteCount(l,r)<<endl;
}

void runSpeedTest(){
	prepare();
	memset(memo,-1,sizeof memo);
}

int main(){
//	runTest();
	solve();
//	runSpeedTest();
}