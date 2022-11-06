#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
int dx[] = { 0,1 };
int dy[] = { 1,0 };
struct query {
	int l;
	int sz;
};

void say(const vector<query>&qs) {
	cout<<qs.size()<<endl;
	for (auto q : qs) {
		int sz=q.sz;
		int a=q.l+1;
		int b=a+sz/2;
		int c=b+sz/2;
		printf("%d %d %d\n",a,b,c);
	}
}
void add(vector<query>&anss, vector<int>&v, query q) {
	anss.push_back(q);
	int a=q.l;
	int b=q.l+q.sz/2;
	int c=b+q.sz/2;

	v[a]=!v[a];
	v[b]=!v[b];
	v[c]=!v[c];
}
int main()
{
	vector<vector<int>>all_oks(14);
	vector<vector<vector<query>>>all_anss(14);
	for (int x = 3; x < 14; ++x) {
		vector<int>oks(1<<x);
		vector<vector<query>>anss(1 << x);
		oks[0]=true;
		queue<int>que;
		que.push(0);
		while (!que.empty()) {
			int now=que.front();
			que.pop();
			for (int sz = 3; sz <= x;sz+=2) {
				for (int a = 0; a <= x - sz; ++a) {
					int next=now;
					int b=a+sz/2;
					int c=b+sz/2;
					next^=(1<<a);
					next^=(1<<b);
					next^=(1<<c);

					if (!oks[next]) {
						oks[next]=true;
						anss[next]=anss[now];
						anss[next].push_back(query{ a,sz });
						que.push(next);
					}
				}
			}
		}
		all_oks[x]=oks;
		all_anss[x]=anss;
		//cout<<count(oks.begin(),oks.end(),1)<<endl;
	}

	int N;scanf("%d",&N);
	vector<int>v(N);
	for(int i=0;i<N;++i)scanf("%d",&v[i]);

	vector<query>my_answer;
	if (N < 14) {
		int num=0;
		for (int i = 0; i < N; ++i) {
			num+=(1<<i)*v[i];
		}
		if (all_oks[N][num]) {
			my_answer=all_anss[N][num];
			cout<<"YES"<<endl;
			say(my_answer);
		}
		else {
			cout<<"NO"<<endl;
		}
	}
	else {
		int offset=0;
		while (N-offset >= 14) {
			string st;
			for (int i = 0; i < 6; ++i) {
				if(v[i+offset]==1)st.push_back('1');
				else st.push_back('0');
			}
			string pre=st.substr(0,3);
			int one_cnt=count(pre.begin(),pre.end(),'1');
			if (one_cnt == 3) {
				add(my_answer, v, query{ offset,3 });
			}
			else if (one_cnt == 0) {

			}
			else if (one_cnt == 1) {
				int place=st.find('1');
				add(my_answer, v, query{ offset + place,7 });
			}
			else if (one_cnt == 2) {
				if (pre == "110") {
					string nex=st.substr(3,3);
					int nex_one_cnt=count(nex.begin(),nex.end(),'1');
					if (nex_one_cnt == 3) {
						add(my_answer, v, query{ offset ,9 });
						add(my_answer, v, query{ offset + 1,5 });
					}
					else if (nex_one_cnt == 2) {
						int aa,bb;
						
						if (nex == "110") {
							aa=0;
							bb=1;
						}
						else if (nex == "101") {
							aa=0;
							bb=2;
						}
						else if (nex == "011") {
							aa=1;
							bb=2;
						}
						add(my_answer, v, query{ offset ,(aa+3)*2+1 });
						add(my_answer, v, query{ offset+1,(bb + 2) * 2 + 1 });
					}
					else if (nex_one_cnt == 1) {
						int aa=nex.find('1');
						add(my_answer, v, query{ offset,(aa + 3) * 2 + 1 });
						add(my_answer, v, query{ offset + 1,11 });
					}
					else if (nex_one_cnt == 0) {
						add(my_answer, v, query{ offset,13 });
						add(my_answer, v, query{ offset + 1,11 });
					}
					offset+=3;
				}
				else if (pre == "101") {
					add(my_answer, v, query{ offset,5 });
				}
				else if (pre == "011") {
					add(my_answer, v, query{ offset + 1,3 });
				}
			}
			offset+=3;
		}
		int num = 0;
		for (int i = 0; i < N-offset; ++i) {
			num += (1 << i)*v[offset+i];
		}
		assert(all_oks[N-offset][num]);
		vector<query>add_answer=all_anss[N-offset][num];
		for(auto&a_ans:add_answer)a_ans.l+=offset;

		my_answer.insert(my_answer.end(),add_answer.begin(),add_answer.end());
		cout << "YES" << endl;
		say(my_answer);
	}
	return 0;
}