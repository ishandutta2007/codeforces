#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main () {
	int n;
	while (cin >> n ){ 
		int ans=0;
		int tmp=-1;
		for (int i=1;n>=i;i++) {
			int a;
			cin >>a;
			if (tmp == -1) tmp=a;
			else tmp = __gcd(tmp,a);
		}
		cout<<tmp*n<<endl;
	}
}