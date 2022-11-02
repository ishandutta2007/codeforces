#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

bool vis[30];

int main(){
	vis['a' - 'a'] = 1;
	vis['e' - 'a'] = 1;
	vis['i' - 'a'] = 1;
	vis['o' - 'a'] = 1;
	vis['u' - 'a'] = 1;
	char s[55];
	scanf("%s",s + 1);
	int n = strlen(s + 1);
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			if((s[i] - '0') % 2 == 1) ans++;
		}
		else{
			if(vis[s[i] - 'a']) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}