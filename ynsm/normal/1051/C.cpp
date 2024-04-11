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
int n, cnt[N], ans[N], x, y, a[N];
int main(){    
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	for(int i = 0; i < 150; i++){
		if(cnt[i] == 1)
			x++;
		if(cnt[i] > 2)
			y++;
	}
	if((x&1) && y==0){
		cout << "NO";
		return 0;
	}
	
	for(int i = 0, j = 0; i < 150; i++){
		if(cnt[i] == 1)
			ans[i] = j % 2, j++;		
	}
	if(x&1){
		for(int i = 0; i < 150; i++){
			if(cnt[i] > 2){
				ans[i] = 2;
				break;
			}	
		}
	}
	cout << "YES" << endl;
	for(int i = 0; i < n; i++){
		int x = a[i];
		if(ans[x] == 0)
			cout << "A";  
        if(ans[x] == 1)
			cout << "B";
        if(ans[x] == 2){
			cout << "B";
			ans[x] = 0;
		}
	}

	
	return 0;
}