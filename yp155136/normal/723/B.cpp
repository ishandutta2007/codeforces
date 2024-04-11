#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n;
	string i;
	while (cin >> n >> i) {
		int j=0,k=0;
		bool check=false;
		i += "_";
		int tmp=0;
		for (int x=0;i.size()>x;x++) {
			if (i[x]=='_') {
				if (check && tmp) k++;
				else if (!check) j = max(j,tmp);
				tmp=0;
			}
			else if (i[x]=='(') {
				j=max(j,tmp);
				tmp=0;
				check=true;
			}
			else if (i[x] == ')') {
				if (tmp) k++;
				tmp=0;
				check=false;
			}
			else tmp++;
		}
		cout<<j<<' '<<k<<endl;
	}
}