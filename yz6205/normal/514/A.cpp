#include <bits/stdc++.h>
using namespace std;

int main(){
	stringstream ss;
	char a[100];
	scanf("%s",a);
	int len = strlen(a);
	for (int i=0;i<len;i++){
		int t = a[i] - '0';
		if (t > 4 && (t !=9 || i != 0)){
			t = 9 - t;
		}
		ss << t;
	}
	long long ans;
	ss >> ans;
	if (ans == 0){
		ans = 9;
	}
	printf("%lld\n",ans);
	return 0;
}