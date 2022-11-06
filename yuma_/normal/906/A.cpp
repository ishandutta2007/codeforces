#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

int main() {
	int N;cin>>N;
	vector<int>kouhos(26,true);
	int ans=0;
	while (N--) {
		char ch;cin>>ch;
		string st;cin>>st;
		if (ch == '.') {
			if (count(kouhos.begin(), kouhos.end(), 1) == 1) {

			}
			else {
				vector<int>used(26);
				for (auto c : st) {
					used[c - 'a'] = true;
				}
				for (int i = 0; i < 26; ++i) {
					if (used[i]) {
						kouhos[i]=false;
					}
				}
			}

		}
		else if (ch == '?') {
			if(N==0)continue;

			if (count(kouhos.begin(), kouhos.end(), 1) == 1)ans++;
			else {
				kouhos[st[0]-'a']=false;
			}
		}
		else if (ch == '!') {
			if (count(kouhos.begin(), kouhos.end(), 1) == 1)ans++;
			else {
				vector<int>used(26);
				for (auto c : st) {
					used[c - 'a'] = true;
				}
				for (int i = 0; i < 26; ++i) {
					if (!used[i]) {
						kouhos[i] = false;
					}
				}
			}
		}
		else {
			assert(false);
		}
	}
	cout<<ans<<endl;
	return 0;
}