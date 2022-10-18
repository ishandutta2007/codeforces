#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		string s;
		cin >> s;
		
		int b = 0, res = 0;
		for(int i = (int)s.size() - 1; i >= 0; i--){
			if(s[i] == 'B')b++;
			else{
				if(b > 0){
					b--;
				}else{
					res++;
				}
			}
		}
		res += b % 2;
		
		printf("%d\n", res);
	}
	
	return 0;
}