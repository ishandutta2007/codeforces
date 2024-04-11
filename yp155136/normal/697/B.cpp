#include <iostream>
using namespace std;
int main () {
	
	string s;
	cin >> s;
	int b=0;
	bool flag=false;
	for (int x=0;s.size()>x;x++) {
		if (s[x]=='e') flag=true;
		else if (flag) {
			b*=10;
			b+=(s[x]-'0');
		}
	}
	if (s[0]=='0' && s[1]=='e')cout<<0<<endl;
	else if (s.size()==5 && s[2]=='0' && s[4]=='0') {
		cout<<s[0]<<endl;
	}
	else {
		int times=0;
		bool flag=false;
		for (int x=0;s.size()>x;x++) {
//				cout<<"x="<<x<<" , times="<<times<<endl;
//				cout<<"b="<<b<<", flag="<<flag<<endl;
			if (s[x]=='.') continue;
			else if (s[x]=='e') break;
			else if (times-b==1&&flag==false) cout<<"0."<<s[x],flag=true;
			else if (times-b==1) cout<<"."<<s[x];
			else if (s[x]=='0' && flag==false) ;
			else if (times<b) cout<<s[x],flag=true;
			else if (times>b) cout<<s[x],flag=true;
			else if (times==b) cout<<s[x],flag=true;
			times++;
		}
		if (times<=b) {
			while (times<=b) {
				cout<<'0';
				times++;
			}
		}
		cout<<endl;
	}
}