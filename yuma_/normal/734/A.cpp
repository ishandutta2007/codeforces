#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;


int main() {
	int N; cin >> N;
	string st; cin >> st;
	int a = count(st.begin(), st.end(), 'A');
	int d = count(st.begin(), st.end(), 'D');
	if (a > d)cout << "Anton" << endl;
	else if (a == d)cout << "Friendship" << endl;
	else cout << "Danik" << endl;
	return 0;
}