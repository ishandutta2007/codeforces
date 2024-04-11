//Solution by Tima
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
using namespace std;    

const int N = 2000, mod = int(1e9)  + 7; 


int n, a[N];
int main () {
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];	
	for(int i = 0; i < (1 << n); i++){
		int cur = 0;
		for(int j = 0; j < n; j++)
			if((1 << j) & i)
				cur += a[j];
			else
				cur -= a[j];
		if(cur % 360 == 0){
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}