#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

int lens[1002][1002][4];
struct aa {
	int x;
	int y;
	int len;
};
int main() {
	int H,W;cin>>H>>W;
	vector<vector<int>>fst_field(H+2,vector<int>(W+2));
	vector<vector<int>>snd_field(H + 2, vector<int>(W + 2));

	for (int i = 0; i < H; ++i) {
		char chs[1010];
		scanf("%s",chs);
		string st=chs;
		for (int j = 0; j < W; ++j) {
			fst_field[i+1][j+1]=st[j]=='*';
		}
	}
	for (int i = 1; i <= H; ++i) {
		for (int j = 1; j <= W; ++j) {
			if(fst_field[i][j])lens[i][j][0]=lens[i][j-1][0]+fst_field[i][j];
		}
		for (int j = W; j >= 1; --j) {
			if (fst_field[i][j])lens[i][j][2]=lens[i][j+1][2]+fst_field[i][j];
		}
	}
	for (int j = 1; j <= W; ++j) {
		for (int i = 1; i <= H; ++i) {
			if (fst_field[i][j])lens[i][j][3]=lens[i-1][j][3]+fst_field[i][j];
		}
		for (int i = H; i >= 1; --i) {
			if (fst_field[i][j])lens[i][j][1]=lens[i+1][j][1]+fst_field[i][j];
		}
	}

	vector<vector<int>>anss(H,vector<int>(W,10000));
	for (int y = 1; y <= H; ++y) {
		for (int x = 1; x <= W; ++x) {
			for (int way = 0; way < 4; ++way) {
				anss[y-1][x-1]=min(anss[y-1][x-1],lens[y][x][way]);
			}
		}
	}
	for (int y = 1; y <= H; ++y) {
		int rest=0;
		for (int x = 1; x <= W; ++x) {
			rest=max(rest, anss[y - 1][x - 1] == 1 ? 0 : anss[y - 1][x - 1]);
			if (rest) {
				snd_field[y][x]=true;
				rest--;
			}
		}
		for (int x=W;x>=1;--x) {
			rest = max(rest, anss[y - 1][x - 1] == 1 ? 0 : anss[y - 1][x - 1]);
			if (rest) {
				snd_field[y][x] = true;
				rest--;
			}
		}
	}
	for (int x = 1; x <= W; ++x) {
		int rest = 0;
		for (int y = 1; y <= H; ++y) {
			rest = max(rest, anss[y - 1][x - 1] == 1 ? 0 : anss[y - 1][x - 1]);
			if (rest) {
				snd_field[y][x] = true;
				rest--;
			}
		}
		for (int y =H; y >=1;--y) {

			rest = max(rest,anss[y-1][x-1]==1?0: anss[y - 1][x - 1]);
			if (rest) {
				snd_field[y][x] = true;
				rest--;
			}
		}
	}
	bool ok=true;
	for (int y = 1; y <= H; ++y) {
		for (int x = 1; x <= W; ++x) {
			if (fst_field[y][x] != snd_field[y][x]) {
				ok=false;
			}
		}
	}
	if (ok) {
		vector<aa>answers;
		for (int y = 1; y <= H; ++y) {
			for (int x = 1; x <= W; ++x) {
				if (anss[y-1][x-1] >= 2) {
					answers.push_back(aa{ x,y,anss[y-1][x-1] - 1 });
				}
			}
		}
		cout<<answers.size()<<endl;
		for (auto an : answers) {
			printf("%d %d %d\n",an.y,an.x,an.len);
		}
	}
	else {
		cout<<-1<<endl;
	}
	return 0;
}