#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"


int main() {	
	long long int a,b,c,d,e;cin>>a>>b>>c>>d>>e;
	bool ok=false;
	for (int i = a; i <= b; ++i) {
		if (i%e== 0) {
			if(c<=i/e&&i/e<=d)ok=true;
		}
	}
	if(ok)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

	return 0;
}