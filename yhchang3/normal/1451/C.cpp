#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;
		string a, b;
		cin >> a >> b;
		vector<int> ak(26), bk(26);
		for(char c:a)
			ak[c - 'a'] ++;
		for(char c:b)
			bk[c - 'a'] ++;
		bool ok = true;
		for(int i=0;i<26;i++)
			if(ak[i] < bk[i]){
				ok = false;
				break;
			}
			else if(ak[i] > bk[i]){
				if((ak[i] - bk[i]) % k == 0){
					ak[i + 1] += ak[i] - bk[i];
				}
				else{
					ok = false;
					break;
				}
			}
		if(ok)
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
	}
}