#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

map<int,int> fen[100001];

int type[100001];
int t[100001];
int x[100001];

const int N = 100001;

vi times;

void add(int idx ,int val){
    while (idx <= N){
        fen[idx][val]++;
        idx += (idx & -idx);
    }
}

void remove(int idx ,int val){
    while (idx <= N){
        fen[idx][val]--;
        idx += (idx & -idx);
    }
}

int read(int idx, int val){
    int sum = 0;
    while (idx > 0){
        sum += fen[idx][val];
        idx -= (idx & -idx);
    }
    return sum;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; 
	cin >> n;
	int a, b, c;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		type[i] = a;
		t[i] = b;
		x[i] = c;
		times.pb(b);
	}
	sort(times.begin(), times.end());
	for(int i = 0; i < n; i++)
	{
		a = type[i];
		b = lower_bound(times.begin(), times.end(), t[i]) - times.begin() + 1;
		c = x[i];
		if(a == 1) add(b, c);
		if(a == 2) remove(b, c);
		if(a == 3) cout << read(b, c) << '\n';
	}
	return 0;
}