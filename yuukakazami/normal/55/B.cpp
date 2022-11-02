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
#define two(a) (1<<(a))
#define contain(s,a) (((s)&TWO(a))!=0)
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

char opt[4];
int64 search(vector<int64> v){
	if(v.size()==1)
		return v[0];
	int at=4-v.size();

	int64 res=1LL<<60;
	for(int a=0;a<v.size();a++)
		for(int b=a+1;b<v.size();b++){
			vector<int64> next=v;
			if(opt[at]=='+'){
				next[a]+=next[b];
			} else {
				next[a]*=next[b];
			}
			swap(next[b],next.back());
			next.pop_back();
			checkmin(res,search(next));
		}
	return res;
}
int main(){
	vector<int64> a;int x;
	REP(i,4)cin>>x,a.push_back(x);
	REP(i,3){
		scanf(" ");
		scanf("%c",&opt[i]);
	}
	cout<<search(a)<<endl;
}