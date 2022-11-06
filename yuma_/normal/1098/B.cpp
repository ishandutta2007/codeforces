#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

int answer=-1;
vector<vector<int>>answer_field;

vector<vector<int>>rot(const vector<vector<int>>&field) {
	vector<vector<int>>afield(field[0].size(),vector<int>(field.size()));
	for (int i = 0; i < field.size(); ++i) {
		for (int j = 0; j < field[0].size(); ++j) {
			afield[j][i]=field[i][j];
		}
	}
	return afield;
}
void solve(const vector<vector<int>>&field,bool flag) {
	int H = field.size();
	int W = field[0].size();

	vector<vector<vector<int>>>sums(H,vector<vector<int>>(2,vector<int>(4)));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			sums[i][j%2][field[i][j]]++;
		}
	}
	vector<pair<int, int>>ps{
		make_pair(0,1),
		make_pair(0,2),
		make_pair(0,3),
		make_pair(1,2),
		make_pair(1,3),
		make_pair(2,3)
	};

	for (int p=0;p<6;++p) {
		vector<pair<int, int>>pps{
			ps[p],ps[5-p]
		};
		int now_answer=0;
		for (int i = 0; i < H; ++i) {
			int ans1=sums[i][0][pps[i%2].first]+sums[i][1][pps[i%2].second];
			int ans2 = sums[i][0][pps[i % 2].second] + sums[i][1][pps[i % 2].first];
			now_answer+=max(ans1,ans2);
		}
		if (answer < now_answer) {
			answer=now_answer;
			answer_field.clear();
			
			for (int i = 0; i < H; ++i) {
				answer_field.push_back(vector<int>(W));
				int ans1 = sums[i][0][pps[i % 2].first] + sums[i][1][pps[i % 2].second];
				int ans2 = sums[i][0][pps[i % 2].second] + sums[i][1][pps[i % 2].first];
				if (ans1 > ans2) {
					for (int j = 0; j < W; j++) {
						answer_field[i][j]=(j%2)?(pps[i%2].second):(pps[i%2].first);
					}
				}
				else {
					for (int j = 0; j < W; j++) {
						answer_field[i][j] = (j % 2) ? (pps[i % 2].first) : (pps[i % 2].second);
					}
				}
			}
			if (flag)answer_field = rot(answer_field);

		}
	}
}

int main()
{
	char chs[400000];
	int H,W;cin>>H>>W;
	vector<vector<int>>field(H,vector<int>(W));
	string st="AGCT";
	for (int i = 0; i < H; ++i) {
		scanf("%s",chs);
		for (int j = 0; j< W; ++j) {
			field[i][j]=st.find(chs[j]);
		}
	}
	solve(field,false);
	field=rot(field);
	solve(field,true);

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			printf("%c",st[answer_field[i][j]]);
		}
		printf("\n");
	}
	return 0;
}