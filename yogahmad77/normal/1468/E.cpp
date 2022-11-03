#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	cin >> a[1];
    	cin >> a[2];
    	cin >> a[3];
    	cin >> a[4];
    	sort(a + 1, a + 1 + 4);
    	cout << a[1] * a[3] << "\n";
    }
}