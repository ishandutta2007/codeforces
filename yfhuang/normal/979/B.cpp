#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5;
char s[3][maxn];

int cnt[3][300];
int ans[3];

int main(){
	int n;
	cin >> n;
	int m;
	for(int i = 0;i < 3;i++){
		scanf("%s",s[i]);
		int len = strlen(s[i]);
		m = len;
		for(int j = 0;j < len;j++){
			cnt[i][s[i][j]]++;
		}
	}	
	for(int i = 0;i < 3;i++){
		for(char j = 'a';j <= 'z';j++){
			int left = m - cnt[i][j];
			if(n <= left){
				ans[i] = max(ans[i],min(m,n + cnt[i][j]));
			}else{
				if(n == 1 && left == 0){
					ans[i] = max(ans[i],m - 1);
				}else{
					ans[i] = max(ans[i],min(m,n + cnt[i][j]));
				}
			}
		}
		for(char j = 'A';j <= 'Z';j++){
			int left = m - cnt[i][j];
			if(n <= left){
				ans[i] = max(ans[i],min(m,n + cnt[i][j]));
			}else{
				if(n == 1 && left == 0){
					ans[i] = max(ans[i],m - 1);
				}else{
					ans[i] = max(ans[i],min(m,n + cnt[i][j]));
				}
			}
		}
	}
	if(ans[0] > ans[1] && ans[0] > ans[2]){
		cout << "Kuro" << endl;
		return 0;
	}
	if(ans[1] > ans[0] && ans[1] > ans[2]){
		cout << "Shiro" << endl;
		return 0;
	}
	if(ans[2] > ans[0] && ans[2] > ans[1]){
		cout << "Katie" << endl;
		return 0;
	}
	cout << "Draw" << endl;
	return 0;
}