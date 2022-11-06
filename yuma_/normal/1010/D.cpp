#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

#include<unordered_map>
struct node {
	int pa;
	int type;

	vector<int>chs;
};

bool calc(bool l, bool r, int type) {
	bool value;
	if (type == 0)value = l and r;
	else if (type == 1)value = l xor r;
	else if (type == 2)value = l or r;

	return value;
}

bool setvalue(const int now, const vector<node>&nodes, vector<bool>&values) {
	node no(nodes[now]);
	bool now_value;
	if (no.type == 3) {
		bool  k=setvalue(no.chs[0],nodes,values);
		now_value=!k;
	}
	else if (no.type == 4) {
		return values[now];
	}
	else {
		bool l=setvalue(no.chs[0],nodes,values);
		bool r=setvalue(no.chs[1],nodes,values);

		now_value=calc(l,r,no.type);
	}

	values[now]=now_value;
	return values[now];
}

bool dfs(const int now, const bool value,vector<int>&anss, const vector<node>&nodes, const vector<bool>&values) {
	if(value==values[now])return values[0];
	else {
		if(anss[now]!=-1)return anss[now];
		if (nodes[now].pa == -1) {
			anss[now]=!values[now];
		}
		else {
			int pa_id=nodes[now].pa;

			bool res;
			if (nodes[pa_id].type == 3) {
				res=dfs(pa_id,!values[pa_id],anss,nodes,values);
			}
			else {
				int l_id = nodes[pa_id].chs[0];
				int r_id = nodes[pa_id].chs[1];

				bool l_ans = values[l_id];
				bool r_ans = values[r_id];

				if (l_id == now)l_ans = !l_ans;
				else r_ans = !r_ans;

				bool pa_ans = calc(l_ans, r_ans, nodes[pa_id].type);

				res = dfs(pa_id, pa_ans, anss, nodes, values);

			}
			
			anss[now]=res;
		}

		return anss[now];
	}
}
int main() {
	int N;cin>>N;
	vector<node>nodes(N);
	vector<bool>values(N,false);

	vector<int>input_ids;

	nodes[0].pa=-1;
	int id=0;
	for (int i = 0; i < N; ++i) {
		char chs[33];
		scanf("%s",chs);
		char ch(chs[0]);

		int a,b;
		node no(nodes[i]);
		switch (ch) {
		case 'A':
			no.type=0;
			scanf("%d %d",&a,&b);a--;b--;
			nodes[a].pa=i;
			nodes[b].pa=i;
			no.chs = vector<int>{ a,b };
			break;
		case 'X' :
			no.type=1;
			scanf("%d %d",&a,&b);a--;b--;
			nodes[a].pa=i;
			nodes[b].pa=i;
			no.chs = vector<int>{ a,b };
			break;
		case 'O':
			no.type=2;
			scanf("%d %d",&a,&b);a--;b--;
			nodes[a].pa=i;
			nodes[b].pa=i;
			no.chs = vector<int>{ a,b };
			break;
		case 'N':
			no.type=3;
			scanf("%d",&a);a--;
			nodes[a].pa=i;
			no.chs = vector<int>{ a };
			break;
		case 'I':
			no.type=4;
			scanf("%d",&a);
			values[i]=a==1;
			no.chs = vector<int>{ id++ };
			input_ids.push_back(i);
			break;
		}
		nodes[i]=no;
	}
	setvalue(0,nodes,values);

	vector<int>anss(N,-1);
	for (auto id : input_ids) {
		dfs(id,!values[id],anss,nodes,values);
		printf("%d",anss[id]);
	}
	cout<<endl;
	return 0;
}