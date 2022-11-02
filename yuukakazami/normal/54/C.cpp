#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <numeric>
#include <climits>
#include <complex>
#define REP(i,n) for(int i=0;i<n;i++)
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define FOREACH(e,x) for(typeof(x.begin()) e=x.begin();e!=x.end();e++)
#define FOR(i,a,b) for(int i=a;i<b;i++)//for i in [a,b)
#define MP make_pair
#define SIZE(x) int(x.size())
#define SORT(x) sort(ALL(x))
#define UNIQUE(x) x.resize(unique(ALL(x))-x.begin())
#define CLR(x,t) memset(x,t,sizeof x)
#define ACM accumulate
#define MC(a,b) memcpy(a,b,sizeof a) //memcpy
#define TWO(a) (1<<(a))
#define CONTAIN(s,a) (((s)&TWO(a))!=0)
using namespace std;
typedef long long int64;
typedef pair<int,int> ipair;
typedef vector<int> vi;
typedef stringstream SS;
template<class T> inline void checkmin(T&x,T c){if(c<x)x=c;}
template<class T> inline void checkmax(T&x,T c){if(c>x)x=c;}
//Finished

template<class It>
string toString(It l,It r){
	SS ss;
	ss<<"[";
	for(It i=l;i!=r;i++)
	{
		ss<<*i;
		if(i+1!=r)
			ss<<",";
	}
	ss<<"]";
	return ss.str();
}

int N;
int K;
int64 L[2000],R[2000];
double prob[2000];
int firstDigit(int64 x){
	stringstream ss;
	ss<<x;
	string s;ss>>s;
	return s[0]-'0';
}
double getProb(int64 l,int64 r){
	double p=1.0/(r-l+1);
	double prob=0;

	while(l<=r){
		int64 pow=1;
		for(;;){
			int64 nextPow=pow*10;
			if(l+nextPow-1<=r&&l%nextPow==0)
				pow=nextPow;
			else
				break;
		}
		if(firstDigit(l)==1)
			prob+=pow*p;
		l+=pow;
	}
	return prob;
}

double Cur[2000];
double Next[2000];

int main(){
	cin>>N;
	REP(i,N)cin>>L[i]>>R[i];
	cin>>K;K=ceil((K/100.0)*N);
	REP(i,N)
		prob[i]=getProb(L[i],R[i]);

	CLR(Next,0);
	Next[0]=1;
	REP(i,N){
		MC(Cur,Next);
		CLR(Next,0);
		REP(j,N+1){
			Next[j+1]+=Cur[j]*prob[i];
			Next[j]+=Cur[j]*(1-prob[i]);
		}
	}
	double res=0;
	REP(i,N+1)if(i>=K)
		res+=Next[i];
	printf("%0.15lf\n",res);
}