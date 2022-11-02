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

int main(){
	int N,K;
	int C;vi h;int x;
	cin>>N>>K>>C;REP(i,C)cin>>x,h.push_back(x);
	int res=0;
	vi m(N+1,0);
	FOREACH(e,h)m[*e]=true;
	int pre=0;
	for(int i=1;i<=N;i++){
		if(m[i])pre=i,res++;
		if(i-pre>=K){
			pre=i;res++;
		}
	}
	cout<<res<<endl;
}