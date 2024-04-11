#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main () {
	string n;
	while (cin >> n){
		long long int x=(n[0]-48)*10000+(n[2]-48)*1000+(n[4]-48)*100+(n[3]-48)*10+(n[1]-48);
		long long int tmp=x;
		for (int i=0;4>i;i++) {
			x*=tmp;
			x%=100000;
		}
		string ans="00000";
		ans[4]=x%10 + 48;
		x/=10;
		ans[3]=x%10 + 48;
		x/=10;
		ans[2]=x%10 + 48;
		x/=10;
		ans[1]=x%10 + 48;
		x/=10;
		ans[0]=x + 48;
		cout << ans << endl;
	}
}