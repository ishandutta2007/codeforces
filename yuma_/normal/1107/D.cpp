#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

map<long long int, int>soinnsuu(long long int a) {
	map<long long int, int>ans;
	for (long long i = 2; i*i <= a; ++i) {
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;


	return ans;
}
vector<bitset<5200>>h_field(5200);
vector<bitset<5200>>w_field(5200);
int to_in(char ch) {
	if (isdigit(ch)){
		return ch-'0';
	}
	else {
		return 10+(ch-'A');
	}
}
int main() {
	int N;scanf("%d",&N);
	map<long long int,int>mp;
	for (int i = 0; i < N; ++i) {
		char chs[1310];
		scanf("%s",chs);
		for (int j = 0; j < N / 4; ++j) {
			int num=to_in(chs[j]);
			for (int w = 0; w < 4; ++w) {
				bool bo=((num&(1<<(3-w)))!=0);
				h_field[i][j*4+w]=bo;
				w_field[j*4+w][i]=bo;
			}
		}
	}
	mp=soinnsuu(N);
	int answer=1;
	for (auto m : mp) {
		int len=m.first;
		for(int t=0;t<m.second;++t){
			bool ok=true;
			for (int k = 0; k < N / len; ++k) {
				for (int j = 0; j < m.first - 1; ++j) {
					int a_place=k*len+j*(len/m.first);
					int b_place=k*len+(j+1)*(len/m.first);

					ok&=h_field[a_place]==h_field[b_place];
					ok&=w_field[a_place]==w_field[b_place];
				}
			}
			len*=m.first;
			if (!ok) {
				break;
			}
			else {
				answer*=m.first;
			}
		}
	}
	cout<<answer<<endl;
	return 0;
}