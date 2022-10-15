#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (s.size() == 1 || s[0] == s[1]){
		cout << s[0] << s[0] << endl;
		return;
	}
	for (int i=0;i<n;){
		int ii = i;
		for (int j=i;j<=n;++j){
			if (j == n){i = j;break;}
			if (s[j] > s[i]) {i=j-1;break;}
			else if (s[j] < s[i]) {i = j;break;}
		}
		if (ii == i){
			for (int j=0;j<=i;++j){
				printf("%c", s[j]);
			}
			for (int j=i;j>=0;--j){
				printf("%c", s[j]);
			}
			printf("\n");
			return;
		}
	}
	if (s[0] == s.back()){
		cout << s[0] << s[0] << endl;
		return;
	}
	cout << s;
	reverse(s.begin(), s.end());
	cout << s;
	cout << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}