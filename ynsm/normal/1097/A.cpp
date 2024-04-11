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


int main () {
	string s, t;
	cin >> s;
	while(cin >> t){
		if(s[0] == t[0] || s[1] == t[1]){
			cout << "YES";
			return 0;
		}
	}		
	cout << "NO";
}