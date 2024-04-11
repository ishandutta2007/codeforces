#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

int say(char ch,int a) {

	cout<<ch<< " "<<a<<endl;
	cout.flush();

	int b;cin>>b;
	return b;
}

long long int gcd(long long int l, long long int r) {
	if (l > r)return gcd(r, l);
	else {
		if (r%l) {
			return gcd(l, r%l);

		}
		else {
			return l;
		}
	}
}
#include<random>

int main() {
	std::mt19937 rnd(323);
	std::uniform_int_distribution<> rn(1,10000000);
	int N;cin>>N;
	int amin=-1;
	int amax=1e9;

	while (amin + 1 != amax) {
		int amid((amin+amax)/2);
		if (say('>',amid)==1) {
			amin=amid;
		}
		else {
			amax=amid;
		}
	}

	int max_num=amax;

	vector<int>v;
	v.push_back(max_num);
	const int TIME=29;
	for (int i = 0; i < TIME; ++i) {
		int id=1+rn(rnd)%N;
		int x=say('?',id);
		v.push_back(x);
	}

	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());

	int sa_g=v[1]-v[0];
	for (int i =1; i < int(v.size())-1; ++i) {
		int sa=v[i+1]-v[i];
		sa_g=gcd(sa,sa_g);
	}
	int min_num=max_num-(N-1)*sa_g;

	cout<<"! "<<min_num<<" "<<sa_g<<endl;

	return 0;
}