#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	string i;
	while (cin >> i) {
		int check=0;
		int len=i.size();
		string ans="";
		for (int x=0;len>x;x++) {
			ans+=" ";
		}
		for (int x=0;len>x;x++) {
			if (check==1 && i[x]!='a') ans[x]=char(i[x]-1);
			else if (check==1 && i[x]=='a') {
				ans[x]=i[x];
				check=2;
			}
			else if (check==2) ans[x]=i[x];
			else if (check==0 && i[x]=='a') ans[x]=i[x];
			else {
				ans[x]= char(i[x]-1);
				check=1;
			}
		}
		if (check==0) {
			for (int x=0;len-1>x;x++) cout<<"a";
			cout<<"z";
			cout<<endl;
		}
		else cout<<ans<<endl;
	}
}