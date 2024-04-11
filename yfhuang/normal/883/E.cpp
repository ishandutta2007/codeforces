#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

char s[1005][55];

bool vis[30];
bool ko[1005];
int main(){
	int n,m;
	cin >> n;
	scanf("%s",s[0] + 1);
	for(int i = 1;i <= n;i++){
		if(s[0][i] == '*') continue;
		vis[s[0][i] - 'a'] = 1;
	}
	cin >> m;
	
	for(int i = 1;i <= m;i++){
		ko[i] = 1;
		scanf("%s",s[i] + 1);
		for(int j = 1;j <= n;j++){
			if(s[0][j] == '*'){
				if(vis[s[i][j] - 'a']) ko[i] = 0;
			}else{
				if(s[i][j] != s[0][j]) ko[i] = 0;
			}
		}
	}
	int ans = 0;
	for(char c = 'a';c <= 'z';c++){
		if(vis[c - 'a']) continue;
		int ok = 0;
		for(int i = 1;i <= m;i++){
			bool flag = 0;
			if(ko[i] == 0){
				ok++;
				continue;
			}
			for(int j = 1;j <= n;j++){
				if(s[0][j] != '*') continue;
				if(s[i][j] == c){
					flag = true;
					break;
				}	
			}
			ok += flag;
		}
		if(ok == m) ans++;
	}
	cout << ans << endl;
	return 0;
}