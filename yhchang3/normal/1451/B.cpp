#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		while(q--) {
			bool ok = false;
			int l, r;
			cin >> l >> r;
			l--, r--;
			for(int mid = 1;mid + 1 < s.size(); mid ++){
				int lidx = l, ridx = r;
				for(int i=0;i<mid && lidx != r + 1;i++)
					if(s[i] == s[lidx])
						lidx ++;
				for(int i=s.size() - 1;i>mid && ridx != l - 1;i--)
					if(s[i] == s[ridx])
						ridx --;
				if(lidx > ridx && lidx != l && ridx != r){
					ok = true;
					break;
				}
			}
			if(ok)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}