#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

#define forn(a, n) for(int a = 0; a<(n); ++a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)

int k;
string str;

int main()
{
	cin >> k >> str;
	map<char, int> letra;
	
	forn(i, str.size()) letra[str[i]]++;
	
	vector<string> ret(k, "");
	forall(it, letra) {
		//cout << it->first << " " << it->second << endl;
		if(it->second % k != 0) {
			cout << "-1" << endl;
			return 0;
		}
		forn(i, k) forn(j, it->second/k) {
			
			ret[i] += it->first;
		}
	}
	
	forn(i, ret.size()) cout << ret[i];
	cout << endl;
	return 0;
}