#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	char a[300010];
	int b[300010];
	int k = 0;
	a[0] = s[0];
	int cnt = 1;
	for(int i = 1 ; i < s.size() ; i ++){
		if(s[i] == a[k])cnt ++;
		else {
			b[k] = cnt;
			k ++;
			a[k] = s[i];
			cnt = 1;
		}
	}
	b[k] = cnt;
	
	/*for(int i = 0 ; i <= k ; i ++){
		cout << a[i] << " " << b[i] << endl;
	}*/
	
	if(k%2 == 1)puts("0");
	else {
		int m = k/2;
		if(b[m] <= 1)puts("0");
		else {
			bool ret = true;
			for(int i = 0 ; i < m ; i ++){
				if(a[i] != a[k-i] || b[i]+b[k-i] <= 2)ret = false;
			}
			if(ret)printf("%d\n",b[m]+1);
			else puts("0");
		}
	}
}