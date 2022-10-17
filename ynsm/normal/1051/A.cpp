//BOOOOOOOOOOOOM 
#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, mod = (int)1e9 + 7, inf = (int)1e9;

int get(char a){ 
	if('0' <= a && a <='9')
		return 0;
	if('a' <= a && a <='z')
		return 1;
	return 2;
}
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	int ans = inf;
	int cnt[] = { 0, 0, 0};
	for(int i = 0; i < n; i++)
		cnt[get(s[i])]++;
	
	if(cnt[0] != 0 && cnt[1] != 0 && cnt[2] != 0){
		cout << s << endl;
		return;
	}

	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			cnt[get(s[j])]--;
			int x = 0;
			for(int q = 0; q < 3; q++)
				if(cnt[q] == 0)
					x++;
			if(x <= j - i + 1)
				ans = min(ans, j - i + 1);
		}
		
		for(int j = i; j < n; j++)
			cnt[get(s[j])]++;
	}

	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			cnt[get(s[j])]--;
			int x = 0;
			for(int q = 0; q < 3; q++)
				if(cnt[q] == 0)
					x++;
			if(x <= j - i + 1){
				
				if(ans == j - i + 1){
					for(int q = 0; q < i; q++)
						cout << s[q];
					for(int q = i; q <= j; q++){
						if(cnt[0] == 0){
							cnt[0]++;
							cout<<'1';
						}else if(cnt[1] == 0){
							cnt[1]++;
							cout<<'a';
						}else{
							cnt[2]++;
							cout<<'A';
						}
					}
					for(int q = j + 1; q < n; q++)
						cout << s[q];
					cout << endl;
					return;
				}
			}
		}
		
		for(int j = i; j < n; j++)
			cnt[get(s[j])]++;
	}


}
int main(){    
	int t;
	cin >> t;
	while(t--)
		solve();	
	return 0;
}