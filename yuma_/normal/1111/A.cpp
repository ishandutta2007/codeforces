#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;



int main() {
	string st="aiueo";
	string a,b;cin>>a>>b;
	bool ok=true;
	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); ++i) {
			int x=st.find(a[i])!=string::npos;
			int y=st.find(b[i])!=string::npos;

			if(x!=y)ok=false;
		}
	}
	else {
		ok=false;
	}
	if(ok)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}