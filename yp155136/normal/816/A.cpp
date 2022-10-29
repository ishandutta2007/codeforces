#include <iostream>
#include <stdio.h>
using namespace std;

bool okay(int hh,int mm) {
	int tmp1=(mm%10)*10+mm/10;
	int tmp2=(hh%10)*10+hh/10;
	return tmp1==hh&&tmp2==mm;
}

int main () {
	string s;
	cin >>s;
	int hh=(s[0]-'0')*10+s[1]-'0';
	int mm=(s[3]-'0')*10+s[4]-'0';
	int cnt=0;
	while (!okay(hh,mm)) {
		cnt++;
		mm++;
		if (mm==60) mm=0,hh++;
		if (hh==24) hh=0;
	}
	cout<<cnt<<endl;
}