#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
int dx[] = { 0,1 };
int dy[] = { 1,0 };

struct aa {
	bool valid;
	int x;
	int y;
	int a_cnt;
	char pre;
	int prev;
};
bool operator <(const aa&l, const aa&r) {
	if (l.a_cnt == r.a_cnt) {
		return l.pre<r.pre;
	}
	else {
		return r.a_cnt<l.a_cnt;
	}
}
int main()
{
	int N,M;cin>>N>>M;
	vector<string>field(N);
	for (int i = 0; i < N; ++i) {
		char chs[2010];
		scanf("%s",chs);
		string st=chs;
		field[i]=st;
	}

	vector<aa>vs;
	vector<vector<aa>>memo(N,vector<aa>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			memo[i][j].valid=false;
			memo[i][j].a_cnt=-100;
		}
	}
	if (field[0][0] == 'a') {
		memo[0][0]= (aa{ true,0,0,M,'a',-1 });
	}
	else {
		if(M)memo[0][0] = (aa{ true,0,0,M-1,'a',-1 });
		else memo[0][0] = aa{ true,0,0,0,field[0][0],-1 };
	}
	vs.push_back(memo[0][0]);
	
	for (int t = 0; t < N * 2 - 2; ++t) {
		vector<aa>next_vs;
		set<pair<int,int>>vps;
		for (auto v : vs) {
			int now_x=v.x;
			int now_y=v.y;
			int now_a_cnt=v.a_cnt;
			
			for (int way = 0; way < 2; ++way) {
				int next_x=now_x+dx[way];
				int next_y=now_y+dy[way];
				if (next_x < N&&next_y < N) {
					aa next_aa;
					if (field[next_y][next_x] == 'a') {

						next_aa= aa{ true,next_x,next_y, now_a_cnt,'a',way };

					}
					else {
						if (now_a_cnt) {
							next_aa = aa{ true,next_x,next_y,now_a_cnt - 1,'a',way };
						}
						else {
							next_aa = aa{ true,next_x,next_y,0,field[next_y][next_x],way };
						}
					}
					vps.insert(make_pair(next_x,next_y));
					memo[next_y][next_x] = min(memo[next_y][next_x], next_aa);
				}
			}
		}

		for(auto nv:vps)next_vs.push_back(memo[nv.second][nv.first]);
		char ch=next_vs[0].pre;
		for (auto ne : next_vs) {
			ch=min(ch,ne.pre);
		}
		vector<aa>avs;
		for (auto ne : next_vs) {if (ch==ne.pre) {
				avs.push_back(ne);
			}
		}
		vs = avs;
	}
	string answer;

	int ax=N-1;
	int ay=N-1;
	while (true) {
			auto me=memo[ay][ax];

			answer.push_back(memo[ay][ax].pre);
			if (ax + ay == 0)break;
			ax-=dx[me.prev];
			ay-=dy[me.prev];
		
	}
	reverse(answer.begin(),answer.end());
	printf("%s",answer.c_str());
	return 0;
}