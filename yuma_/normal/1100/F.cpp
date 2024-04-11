#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
const int MAX_SIZE=20;
struct query {
	int id;
	int l;
	int r;
};
int N;
vector<int>v;
vector<int>answers;

vector<int> add(vector<int>v, int num) {
	for (int i = MAX_SIZE - 1; i >= 0; --i) {
		if ((num&(1 << i)) != 0) {
			if (v[i] == 0) {
				v[i]=num;
				return v;
			}
			else {
				num^=v[i];
			}
		}
	}
	return v;
}

int getans(vector<int>v) {
	int answer=0;
	for (int i = MAX_SIZE - 1; i >= 0; --i) {
		if (v[i] != 0) {
			if ((answer&(1 << i)) == 0) {
				answer^=v[i];
			}
		}
	}
	return answer;
}
int check(vector<int>l, vector<int>r) {
	for (auto k : r) {
		l=add(l,k);
	}
	return getans(l);
}

void solve(int l, int r, vector<query>&all_querys) {
	if(all_querys.empty())return ;
	int m=(l+r)/2;

	vector<query>l_querys,r_querys,m_querys;
	if (l + 1 != r) {
		for (auto q : all_querys) {
			if (q.r <= m)l_querys.push_back(q);
			else if (m <= q.l)r_querys.push_back(q);
			else m_querys.push_back(q);
		}
		solve(l, m, l_querys);
		solve(m, r, r_querys);
	}
	else {
		m_querys=all_querys;
	}
	

	vector<vector<int>>r_sums(r-m+1,vector<int>(MAX_SIZE));
	vector<vector<int>>l_sums(m-l+1,vector<int>(MAX_SIZE));
	r_sums[0]=vector<int>(MAX_SIZE);
	l_sums[0]=vector<int>(MAX_SIZE);
	for (int i = 0; i < r - m; ++i) {
		r_sums[i+1]=add(r_sums[i],v[m+i]);
	}
	for (int i = 0; i < m - l; ++i) {
		l_sums[i+1]=add(l_sums[i],v[m-i-1]);
	}
	for (auto mq : m_querys) {
		vector<int>l_sum(l_sums[m-mq.l]);
		vector<int>r_sum(r_sums[mq.r-m]);

		int ans=check(l_sum,r_sum);
		answers[mq.id]=ans;
	}
}

int main()
{
	scanf("%d",&N);
	for (int i = 0; i < N; ++i) {
		int a;scanf("%d",&a);
		v.push_back(a);
	}
	fill(answers.begin(),answers.end(),-1);
	int Q;cin>>Q;
	vector<query>qs;
	answers.resize(Q);

	for (int i = 0; i < Q; ++i) {
		int l,r;
		scanf("%d %d",&l,&r);
		l--;
		qs.push_back(query{ i,l,r });
	}
	solve(0,N,qs);
	for (int i = 0; i < Q; ++i) {
		printf("%d\n",answers[i]);
	}
	return 0;
}