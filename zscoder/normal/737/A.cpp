#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

typedef pair<ll, ll> ii;

vector<ll> gas;
ii car[200100];

long long walk(int cap){
	long long ans = 0;
	for(int i = 1; i < gas.size(); i++){
		long long dist = gas[i] - gas[i-1];
		if(dist > cap){
			return ll(1e10);
		}
		
		if(cap >= 2LL*dist)
			ans += dist;
		else
			ans += 2LL*dist - (cap - dist);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, station, s, time_limit;
	cin >> n >> station >> s >> time_limit;
	
	for(int i = 0; i < n; i++)
	{
		cin >> car[i].first >> car[i].second;
	}
	sort(car, car + n);
	
	gas.push_back(0);
	for(int i = 0; i < station; i++)
	{
		int x; cin >> x;
		gas.push_back(x);
	}
	gas.push_back(s);
	
	sort(gas.begin(), gas.end());
	
	for(int i = 1; i < n; i++)
	{
		if(car[i].second < car[i-1].second)
		{
			car[i].second = car[i-1].second;
		}
	}
	
	int hi = n-1;
	int lo = 0;
	int ans = -1;
	while(lo<=hi)
	{
		int mid = (hi+lo)/2;
		if(walk(car[mid].second) <= time_limit)
		{
			ans = car[mid].first;
			hi = mid-1;
		}
		else
		{
			lo = mid+1;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}