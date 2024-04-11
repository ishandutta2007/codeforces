#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

int n;
char p[100005];
char s[100005];
main(){
	scanf("%d", &n);
	REP(i, n){
		if(!i) scanf("%s", p);
		else{
			scanf(" %s", s);
			for(int j=0;s[j];j++){
				if(p[j]!=1 && p[j]!=s[j] && p[j] != '?' && s[j] != '?') p[j] = 1;
				if(p[j] == '?' && s[j] != '?') p[j] = s[j];
			}
		}
	}
	for(int j=0;p[j];j++) putchar(p[j]==1?'?':p[j]=='?'?'a':p[j]);
	return 0;
}