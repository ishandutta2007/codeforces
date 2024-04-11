#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;

int op(vector<int>&used) {
	int a;
	scanf("%d",&a);
	used[a-1]=true;
	return a-1;
}
void my(int take,vector<int>&used) {
	cout<<take+1<<endl;
	used[take]=true;
	cout.flush();
}

struct hero {
	int power;
	int id;
	int need=-1;
	hero() {

	}

};

int main() {
	int N,M;scanf("%d %d",&N,&M);
	//vector<int>powers(2*N);
	vector<hero>heros(2*N);
	for (int i = 0; i < 2 * N; ++i) {
		int a;
		scanf("%d",&a);
		heros[i].power=a;
		heros[i].id=i;
	}
	vector<pair<int,int>>pairs(M);
	for (int i = 0; i < M; ++i) {
		int a,b;scanf("%d %d",&a,&b);
		a--;b--;
		pairs.push_back(make_pair(a,b));
		heros[a].need=b;
		heros[b].need=a;
	}
	int fst;scanf("%d",&fst);
	int needed_id=-1;
	vector<int>used(2*N);
	for (int i = 0; i < 2 * N; ++i) {
		if (fst == 1) {
			if (needed_id == -1) {
				int anext=-1;
				for (int j = 0; j < 2 * N; ++j) {
					if (!used[j]) {
						if (heros[j].need != -1) {
							if (!used[j]&&heros[j].power >= heros[heros[j].need].power) {
								needed_id=j;
								break;
							}
						}
					}
				}
				if(needed_id==-1){
					pair<int,int>pai(-1,-1);
					for (int j = 2 * N - 1; j >= 0; --j) {
						if (!used[j]) {
							pai=max(pai,make_pair(heros[j].power,j));
						}
					}
					needed_id=pai.second;
				}
				
			}
			{
				my(needed_id,used);
				needed_id=-1;
			}
		}
		else {
			int k=op(used);
			if (heros[k].need != -1 && !used[heros[k].need]) {
				needed_id= heros[k].need;
			}
			else {
				needed_id=-1;
			}
		}
		fst=3-fst;
	}

	return 0;
}