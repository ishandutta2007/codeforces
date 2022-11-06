#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"


int main() {	
	int A,B;cin>>A>>B;
	B=A-B;
	int ans=0;
	int Q;cin>>Q;
	while (Q--) {
		int x,y,r;cin>>x>>y>>r;
		int a=x*x+y*y;
		double sa=sqrt(a);
		if(B<=sa-r+eps&&sa+r-eps<=A)ans++;
	}
	
	cout<<ans<<endl;
	return 0;
}