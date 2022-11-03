#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
#define MOD 1000000007 
#define mx 100003

int main(){
	int n, jaw = 0;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = -1; i < n; i++){
		map<int, int> cnt;
		for(int j = 0; j < n; j++)
			cnt[a[j]] += 1;
		for(int j = i + 1; j < n; j++){
			if(sz(cnt) == i + 1 + n - j)
				jaw = max(jaw, i + 1 + n - j);
			cnt[a[j]] -= 1;
			if(cnt[a[j]] == 0)
				cnt.erase(a[j]);
		}
		if(sz(cnt) == i + 1)
			jaw = max(jaw, i + 1);
	}	
	cout << n - jaw << endl;
}