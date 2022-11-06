#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

int out(int l, int r) {
	l++;r++;
	cout<<"? "<<l<<" "<<r<<endl;
	fflush(stdout);
	int ans;cin>>ans;
	if(ans==-1)exit(0);
	return ans;
}

vector<int>anss;
int N, K;
int check(int l,int r,int expect) {
	int answer=-1;
	while (true) {

		out(l, r);
		int x = out(l, r);
		if (x == K) {

		}
		else {
			if (x == expect + 1) {
				answer=0;
			}
			else {
				assert(x==expect-1);
				answer=1;
			}
			while (true) {
				out(l,r);
				int x=out(l,r);
				if (x == K) {
					return answer;
				}
			}
		}
	}

}

int main() {
	cin>>N>>K;
	anss.resize(N);
	int expect=0;
	for (int i = 0; i < N/2; ++i) {
		anss[i]=check(1+i,N-1-i,K+expect);
		anss[N-i-1]=check(i,N-2-i,K+expect);
		expect-=anss[i]?1:-1;
		expect-=anss[N-i-1]?1:-1;
	}
	if (N % 2 == 1) {
		int sum=accumulate(anss.begin(),anss.end(),0);
		if(sum==K-1)anss[N/2]=1;
		else {
			assert(sum==K);
			anss[N/2]=0;
		}
		
	}
	cout << "! ";
	for (int i = 0; i < N; ++i) {
		cout << anss[i];
	}
	cout << endl;
	return 0;
}