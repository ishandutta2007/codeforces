#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXM = 2000005;

int n, ki, xi;
string s[MAXN];

vector <int> ev[MAXM];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;

	int len = 0;
	for(int i = 0; i < n; i++){
		cin >> s[i] >> ki;
		for(int j = 0; j < ki; j++){
			cin >> xi;
			xi--;

			len = max(len, xi + (int)s[i].size());
			ev[xi].push_back(i);
		}
	}

	int k = -1, j = 0;
	for(int i = 0; i < len; i++){
		if(k != -1 && j == (int)s[k].size()){
			k = -1;
			j = 0;
		}

		for(int x : ev[i]){
			if(k == -1 || ((int)s[k].size() - j) < (int)s[x].size()){
				k = x;
				j = 0;
			}
		}

		if(k == -1)cout << 'a';
		else{
			cout << s[k][j];
			j++;
		}
	}
	cout << endl;

	return 0;
}