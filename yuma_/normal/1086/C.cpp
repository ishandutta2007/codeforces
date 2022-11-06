#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;


char a[1000010], b[1000010], c[1000010];
int K;
int kk;
bool dfs(int id, vector<int>&tos, vector<int>&froms, int flag) {
	if (id ==kk) {
		return true;
	}
	else {
		int a_ch=a[id]-'a';
		int b_ch=b[id]-'a';
		for (int i = 0; i < K; ++i) {
			if (tos[a_ch] != -1) {
				if (i == tos[a_ch]) {

				}
				else {
					continue;
				}
			}
			else {
				if(froms[i]!=-1)continue;
			}
			if (flag) {
				if (b_ch < i) {
					int f_to=tos[a_ch];
					int f_fr=froms[i];

					tos[a_ch] = i;
					froms[i] = a_ch;
					bool ok=dfs(id+1,tos,froms,false);
					if(ok)return true;
					tos[a_ch] = f_to;
					froms[i] = f_fr;
				}
				else if (b_ch == i) {
					int f_to = tos[a_ch];
					int f_fr = froms[i];

					tos[a_ch] = i;
					froms[i] = a_ch;
					bool ok = dfs(id+1, tos, froms,true);
					if (ok)return true;
					tos[a_ch] = f_to;
					froms[i] = f_fr;

				}
				else {

				}
			}
			else {
				int f_to = tos[a_ch];
				int f_fr = froms[i];

				tos[a_ch] = i;
				froms[i] = a_ch;
				bool ok = dfs(id+1, tos, froms, false);
				if (ok)return true;
				tos[a_ch] = f_to;
				froms[i] = f_fr;
			}
		}

		return false;
	}
}
int main()
{
	int T;cin>>T;
	while (T--) {
		scanf("%d",&K);
		string ast, bst, cst;
		{
			scanf("%s",a);
			scanf("%s",b);
			scanf("%s",c);
			ast=a;
			bst=b;
			cst=c;
		}
		kk=ast.size();
		vector<int>tos(K,-1),froms(K,-1);
		dfs(0,tos,froms,true);

		{
			int j=0;
			for (int i = 0; i < K; ++i) {
				if (tos[i] == -1) {
					while (true) {
						if (froms[j] == -1) {
							tos[i]=j;
							froms[j]=i;
							j++;
							break;
						}
						j++;
					}
				}
			}
		}
		string after_ast;
		for(auto as:ast)after_ast.push_back(tos[as-'a']+'a');
		if (after_ast <= cst&&bst<=after_ast) {
			printf("YES\n");
			for (int i = 0; i < K; ++i) {
				char ch='a'+tos[i];
				printf("%c",ch);
			}
			printf("\n");
			continue;
		}
		 {
			printf("NO\n");

		}
	}
	return 0;
}