#include <iostream>
#include <string>
#include <vector>
#define SS ;
typedef long long ll;

using namespace std;
ll n;
vector<ll> g;
int main() {
	cin >> n;
	if (n <= 2) {
		cout << "1\n1 1";
		SS
		return 0;
	}
	ll q = n*(n + 1) / 2;
	cout << q % 2 << endl;
	ll sum = 0;
	for (size_t i = n; i > 0; i--){
		if (sum + i > q / 2) {
			g.push_back(q / 2 - sum);
			cout << g.size();
			for (size_t j = 0; j < g.size(); j++)
			{
				cout << " " << g[j];
			}
			SS
			return 0;
		}
		g.push_back(i);
		sum += i;
		if (sum == q / 2) {
			cout << g.size();
			for (size_t j = 0; j < g.size(); j++){
				cout << " "<<g[j];
			}
			SS
			return 0;
		}
	}
	cout << g.size();
	for (size_t i = 0; i < g.size(); i++)
	{
		cout << " " << g[i];
	}
	SS
	return 0;
}