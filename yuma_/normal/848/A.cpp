#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;
const long long int x=1200;
int main() {
	vector<int>v(1000);
	v[0]=0;
	for (int i = 1; i < 1000; ++i) {
		v[i]=v[i/2]+v[(i+1)/2]+(i/2)*((i+1)/2);
	}
	int rest;cin>>rest;
	string answer;
	for (char ch = 'a'; ch <= 'z'; ++ch) {
		if (rest) {
			for (int i = 999; i >= 1; --i) {
				if (rest >= v[i]) {
					for (int x = 0; x < i; ++x) {
						answer.push_back(ch);
					}
					rest-=v[i];
					break;
				}
			}
		}
	}
	if(answer.empty())answer="x";
	cout<<answer<<endl;
	return 0;
}