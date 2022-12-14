#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		int a = 0, b = 0, res = 0;
		for(char c:s)
			if(c == '(')
				a++;
			else if(c == '[')
				b++;
			else if(c == ')'){
				if(a != 0)
					res++, a--;
			}
			else{
				if(b != 0)
					res++, b--;
			}
		cout << res << '\n';
	}
}