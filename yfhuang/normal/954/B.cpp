#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1005;

char s[maxn];

int main(){
	int n;
	cin >> n;
	scanf("%s",s + 1);
	int ans = n;
	for(int i = 1;2 * i <= n;i++){
		bool flag = true;
		for(int j = 1;j <= i;j++){
			if(s[j] != s[j + i]) flag = false;
		}
		if(flag){
			ans = min(ans,n - i + 1);
		}
	}
	cout << ans << endl;
	return 0;
}