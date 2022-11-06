#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
//for CodeForces
#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ll=long long ;

int out(int l, int r, int u, int d,bool ok=false) {
	if (!ok) {
		cout << "? " << l << " " << u << " " << r << " " << d << endl;
		cout.flush();
		int num; cin >> num;
		return num;
	}
	else {
		cout << "! " << l << " " << u << " " << r << " " << d << endl;
		return 0;
	}
}
int main() {
	int N;cin>>N;
	vector<int>xs,ys;
	for (int x = 0; x < N; ++x) {
		int l=x,r=x+1,u=0,d=N;
		int num=out(l+1,r,u+1,d);
		if(num%2)xs.emplace_back(x);
	}
	for (int y = 0;y < N; ++y) {
		int l=0,r=N,u=y,d=y+1;
		int num = out(l + 1, r, u + 1, d);
		if (num % 2)ys.emplace_back(y);
	}
	if(xs.empty()&&ys.empty())assert(false);
	else if (xs.empty()) {
		
		int y1=ys[0],y2=ys[1];
		int x=-1;
		{
			int l=0;
			int r=N;
			while (l + 1 != r) {
				int m=((l+r)/2);
				int num=out(l+1,m,y1+1,y1+1);
				if (num % 2) {
					r=m;
				}
				else {
					l=m;
				}
			}
			x=l;
		}
		out(x+1,x+1, y1 + 1, y2+1,true);
		
	}
	else if (ys.empty()) {
		int x1 = xs[0], x2 = xs[1];
		int y = -1;
		{
			int l = 0;
			int r = N;
			while (l + 1 != r) {
				int m = ((l + r) / 2);
				int num = out(x1 + 1, x1+1,l+1,m);
				if (num % 2) {
					r = m;
				}
				else {
					l = m;
				}
			}
			y = l;
		}
		out(x1+1,x2+1,y+1,y+1,true);
	}
	else {
		int x1=xs[0],x2=xs[1];
		int y1=ys[0],y2=ys[1];

		int num=out(x1+1,x1+1,y1+1,y1+1);
		if (num % 2) {
			
		}
		else {
			swap(y1,y2);
		}
		out(x1+1,x2+1,y1+1,y2+1,true);
	}
	return 0;
}