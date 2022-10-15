#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i=0;i<n;++i) scanf("%lld", &a[i]);
	int c = 0;
	for (int i=0;i<n;++i)
	{
		while (a[i]%2==0){
			a[i] /= 2;
			++c;
		}
	}

	sort(a.begin(), a.end());
	long long s = 0;
	for (int i=0;i<n-1;++i)
	{
		s += a[i];
	}

	s += a[n-1] * (1ll << c);

	cout << s << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}