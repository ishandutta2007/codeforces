#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"

const int X=0b00001111;
const int Y=0b00110011;
const int Z=0b01010101;

void chmin(string&a, const string b) {
	if(a.size()>b.size())a=b;
	else if (a.size() == b.size()) {
		a=min(a,b);
	}
}
int main() {
	vector<vector<string>>memo(256,vector<string>(3,string(100,'c')));
	memo[X][2]="x";
	memo[Y][2]="y";
	memo[Z][2]="z";

	for (int k = 0; k < 5; ++k) {

		vector<vector<string>>p_memo(memo);
		for (int i = 0; i < 256; ++i) {
			for (int x = 0; x < 3; ++x) {
				if(memo[i][x].size()>15)continue;


				//"!"
				{
					const int num=255^i;

					string nst;
					if (x ==2) {
						nst = "!" + memo[i][x];
					}
					else {
						 nst="!("+memo[i][x]+")";
					}
					chmin(memo[num][2], nst);
				}

				for (int j = 0; j < 256; ++j) {
					for (int y = 0; y < 3; ++y) {
						if(memo[j][y].size()>15)continue;

						//"|"
						{
							const int num=i|j;
							{
								const string nst=memo[i][x]+"|"+memo[j][y];

								chmin(memo[num][0], nst);
							}
						}

						//"&"
						{
							const int num=i&j;
							{
								
							}

							{
								string lst, rst;
								if (x == 0) {
									lst = "(" + memo[i][x] + ")";
								}
								else {
									lst = memo[i][x];
								}
								if (y == 0) {
									rst = "(" + memo[j][y] + ")";
								}
								else {
									rst = memo[j][y];
								}
								const string nst = lst+ "&" +rst;

								chmin(memo[num][1], nst);
							}
						}
					}
				}
			}
		}
		if (memo == p_memo) {
			break;
		}
	}

	int Q;cin>>Q;
	while (Q--) {
		int num=0;
		string st;cin>>st;
		for (auto c : st) {
			num*=2;
			num+=c=='1';
		}
		string ans=string(100,'c');
		for (int i = 0; i < 3; ++i) {
			chmin(ans,memo[num][i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}