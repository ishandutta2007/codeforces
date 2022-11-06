#include "bits/stdc++.h"
using namespace std;

int main() {
	string st;cin>>st;
	int num=0;
	set<string>aset=set<string>{ "Danil", "Olya", "Slava", "Ann" , "Nikita" };
	for (auto name : aset) {
		for (int l = 0; l<=int(st.size()) - int(name.size()); ++l) {
			if(st.substr(l,name.size())==name)num++;
		}
	}
	if(num==1)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}