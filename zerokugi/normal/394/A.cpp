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
main(){
	string s;
	while(cin >> s){
		int A=0, B=0, C=0, i=0;
		while(s[i++] != '+') A ++;
		while(s[i++] != '=') B ++;
		while(i++<s.size()) C ++;
		if(A+B == C-2 && C > 2) A++, C--;
		else if(A+B == C+2 && A+B>2){
			if(A>1) A--,C++;
			else B--,C++;
		}else if(A+B != C){
			cout << "Impossible" << endl;
			continue;
		}
		cout << string(A, '|') << "+" <<  string(B, '|') << "=" <<  string(C, '|') << endl;
	}
	return 0;
}