#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	string s;
	cin >>s;
	int d;
	cin >> d;
	string tmp=s;
	for (int i=0;d>i;i++) tmp+=" ";
	int ans=0;
	for (int i=0;tmp.size()>i;i++) {
		//see i
		for (int j=1;tmp.size()>j;j++) {
			if (i+(2*j)-1 > tmp.size()) break;
			int ala=i+j;
			int k=j;
			bool check=true;
			int _=i;
			while (k--) {
				if (tmp[i] == tmp[ala]) ;
				else if (tmp[ala]==' ');
				else {
					check=false;
					break;
				}
				i++;
				ala++;
			}
			i=_;
			if (check) ans = max(ans,j);
		}
	}
	cout<<ans*2<<endl;
}