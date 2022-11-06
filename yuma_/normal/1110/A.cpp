#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;


struct status {
	int id;
	long long int a;
	long long int b;
	long long int now_a_cnt;
	long long int now_b_cnt;

	long long int get_cost()const {
		return a*now_a_cnt+b*now_b_cnt;
	}
	bool operator<(const status&r)const {
		if(get_cost()!=r.get_cost()) return get_cost()<r.get_cost();
		else {
			return id<r.id;
		}
	}
};



int X, Y, N;
int M;
void tt(set<status>&aset,int &x_sum) {
	if (x_sum > X) {

	}
}
int main() {
	int N,K;cin>>N>>K;
	vector<int>as(K);
	for(int i=0;i<K;++i)scanf("%d",&as[i]);

	bool odd=false;
	for (int i = 0; i < K; ++i) {
		bool aa=as[i]%2!=0;
		if(N%2==0&&i!=K-1)aa=false;
		odd^=aa;
	}
	if(!odd)cout<<"even"<<endl;
	else cout<<"odd"<<endl;
	return 0;
}