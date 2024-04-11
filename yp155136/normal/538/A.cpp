#include <iostream>
#include <stdio.h>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;

typedef long long LL;
typedef long double ld;
typedef pair<int,int> pii;
const int MAX_N = 1e5 +6;
const int INF = 1e9 + 7;

int main (){
	string s;
	while (cin >> s) {
		//start from first 
		string g="CODEFORCES ";
		int id=0;
		for (auto i:s) {
			if (g[id] == i) id++;
			else break;
		}
		string h="SECROFEDOC ";
		int idd=0;
		for (int x=s.size()-1;x>=0;x--) {
			if (s[x] == h[idd]) idd++;
			else break;
		}
		if (id + idd >= 10) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}