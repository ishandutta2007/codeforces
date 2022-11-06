#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;



int main() {
	int N;cin>>N;
	vector<vector<int>>tos(2,vector<int>(10));
	for(int i=0;i<10;++i)tos[1][i]=1;
	for (int i = 0; i < N; ++i) {

		char ch;
		int n;cin>>ch>>n;
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 10; ++k) {
				int x=(n&(1<<(9-k)))!=0;
				if (ch == '|') {
					tos[j][k] |= x;
				}
				else if (ch == '^') {
					tos[j][k] ^= x;
				}
				else {
					tos[j][k] &= x;
				}
			}
		}
	}
	vector<int>ands,ors,xors;
	for (int i = 0; i < 10; ++i) {
		if (tos[0][i] == 0 && tos[1][i] == 1) {
		}
		else if (tos[0][i] == 0 && tos[1][i] == 0) {
			ands.push_back(i);
		}
		else if (tos[0][i] == 1 && tos[1][i] == 0) {
			xors.push_back(i);
		}
		else if (tos[0][i] == 1 && tos[1][i] == 1) {
			ors.push_back(i);
		}
	}
	cout<<3<<endl;
	{
		vector<int>and_num(10,1);
		for (auto an : ands) {
			and_num[an]=0;
		}
		int num=0;
		for (int i = 0; i < 10; ++i) {
			num*=2;
			if (and_num[i]) {

				num++;
			}
		}
		cout<<"&"<<" "<<num<<endl;
	}
	{
		vector<int>or_num(10, 0);
		for (auto an : ors) {
			or_num[an] = 1;
		}
		int num = 0;
		for (int i = 0; i < 10; ++i) {
			num *= 2;
			if (or_num[i]) {

				num++;
			}
		}
		cout << "|" << " " << num << endl;
	}
	{
		vector<int>xor_num(10, 0);
		for (auto an : xors) {
			xor_num[an] = 1;
		}
		int num = 0;
		for (int i = 0; i < 10; ++i) {
			num *= 2;
			if (xor_num[i]) {

				num++;
			}
		}
		cout << "^" << " " << num << endl;
	}
	return 0;
}