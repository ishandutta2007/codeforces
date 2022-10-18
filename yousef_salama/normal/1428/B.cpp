#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		string s;
		
		cin >> n >> s;
		
		vector <bool> v(n, false);
		
		int a = 0, b = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '>'){
				a++;
			}else if(s[i] == '<'){
				b++;
			}else{
				v[i] = true;
				v[(i + 1) % n] = true;
			}
		}
		
		if(a == 0 || b == 0){
			printf("%d\n", n);
			continue;
		}
		
		int cnt = 0;
		for(int i = 0; i < n; i++)cnt += v[i];
		
		printf("%d\n", cnt);
	}
	return 0;
}