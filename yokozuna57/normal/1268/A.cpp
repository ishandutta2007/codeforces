#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

int main(){
	int n,k;
	string s;
	cin >> n >> k >> s;
	
	cout << n << endl;
	
	for(int i = 0 ; i+k < n ; i ++){
		if(s[i] > s[i+k]){
			for(int j = 0 ; j < n ; j ++){
				printf("%c",s[j%k]);
			}
			cout << endl;
			return 0;
		}
		if(s[i] < s[i+k]){
			/*for(int j = i+1 ; j < k ; j ++){
				s[j] = '0';
			}*/
			for(int j = k-1 ; j >= 0 ; j --){
				if(s[j] == '9')s[j] = '0';
				else {
					s[j] ++;
					break;
				}
			}
			for(int j = 0 ; j < n ; j ++){
				printf("%c",s[j%k]);
			}
			cout << endl;
			return 0;
		}
		if(i+k == n-1){
			for(int j = 0 ; j < n ; j ++){
				printf("%c",s[j%k]);
			}
			cout << endl;
			return 0;
		}
	}
}