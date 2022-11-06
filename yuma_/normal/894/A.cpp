#include "bits/stdc++.h"
using namespace std;

int main() { 
	string st;cin>>st;
	int l=0;
	int r=count(st.begin(),st.end(),'Q');
	int ans=0;
	for (int i = 0; i < st.size(); ++i) {
		if (st[i] == 'Q') {
			l++;
			r--;
		}
		else if (st[i] == 'A') {
			ans+=l*r;
		}
	}
	cout<<ans<<endl;
	return 0;
}