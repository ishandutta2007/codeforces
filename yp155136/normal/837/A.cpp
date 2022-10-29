#include <iostream>
#include <stdio.h>
#include <cstring>
#include <sstream>

using namespace std;

int main () {
	int n;
	cin >>n;
	string s;
	getchar();
	getline(cin,s);
	stringstream ss;
	ss.str(s);
	string x;
	int mx=0;
	while (ss >> x) {
		int cnt=0;
		for (char i:x) cnt += (i<='Z');
		mx = max(mx,cnt);
	}
	cout<<mx<<endl;
}