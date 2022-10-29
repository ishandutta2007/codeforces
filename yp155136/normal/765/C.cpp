#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	long long int k,a,b;
	while (cin >>k>>a>>b) {
		if (a>=k && b>=k || a%k==0 && a!=0 || b%k ==0 && b!=0 )cout<<a/k + b/k<<endl;
		else cout<<-1<<endl;
	}
}