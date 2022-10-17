#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

const int BIT_SIZE = 30;

int main(){
	string ret = "";
	for(int i = 0 ; i < BIT_SIZE ; i ++){
		ret += "l";
	}
	for(int i = 0 ; i < BIT_SIZE ; i ++){
		ret += "srt";
	}
	for(int i = 0 ; i < BIT_SIZE ; i ++){
		ret += "0l";
	}
	for(int i = 0 ; i < 2*BIT_SIZE+1 ; i ++){
		ret += "r";
	}
	for(int i = 0 ; i < BIT_SIZE ; i ++){
		ret += "slt";
	}
	ret += "l";
	ret += "u";
	for(int i = 0 ; i < BIT_SIZE ; i ++){
		ret += "l";
	}
	for(int i = 0 ; i < BIT_SIZE ; i ++){
		ret += "srt";
	}
	for(int i = 0 ; i < BIT_SIZE ; i ++){
		ret += "0l";
	}
	for(int i = 0 ; i < 2*BIT_SIZE+1 ; i ++){
		ret += "r";
	}
	for(int i = 0 ; i < BIT_SIZE ; i ++){
		ret += "slt";
	}
	ret += "l";
	ret += "d";
	for(int i = 0 ; i < BIT_SIZE ; i ++){
		for(int x = 0 ; x < i ; x ++){
			ret += "l";
		}
		ret += "u";
		for(int j = i ; j < BIT_SIZE+1 ; j ++){
			ret += "u10dt";
			ret += "u10dt";
			ret += "ddl";
		}
		for(int j = i ; j < BIT_SIZE+1 ; j ++){
			ret += "r";
		}
		ret += "d";
		ret += "u10dt";
		ret += "u10dt";
		for(int j = i ; j < BIT_SIZE+1 ; j ++){
			ret += "r10lt";
			ret += "l";
			ret += "0ut";
			ret += "l10rt";
			ret += "rr";
			ret += "l10rt";
			ret += "u";
			ret += "u10dt";
			ret += "u10dt";
			ret += "ddd";
			ret += "u10dt";
			ret += "u10dt";
			ret += "l10rt";
			ret += "r";
			ret += "r10lt";
			ret += "l";
			ret += "u";
			ret += "l10rt";
			ret += "r";
			ret += "r10lt";
			ret += "l";
			ret += "d";
			ret += "ul";
			ret += "1dt";
			ret += "r10lt";
			ret += "dr";
			ret += "1ut";
			ret += "l10rt";
			ret += "0ut";
			ret += "d01ut";
			ret += "dl";
		}
		ret += "u";
		for(int j = BIT_SIZE ; j >= i ; j --){
			ret += "r";
			ret += "d10ut";
			ret += "d10ut";
			ret += "uu";
		}
		ret += "ddd";
		for(int j = i ; j > 0 ; j --){
			ret += "r";
		}
	}
	ret += "u";
	ret += "rel";
	for(int i = 0 ; i < BIT_SIZE+1 ; i ++){
		ret += "l";
	}
	ret += "e";
	for(int i = 0 ; i < BIT_SIZE ; i ++){
		ret += "rste";
	}
	ret += "r";
	cout << ret << endl;
}