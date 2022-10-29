#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 510;

vector<int> edg[MAX_N];
int w[MAX_N][MAX_N];
char ans[MAX_N];

struct DisjointSet {
	int p[3*MAX_N];
	void init(int n) {
		for (int x=0;3*MAX_N>x;x++) p[x]=x;
	}
	int Find(int x) {
		return p[x]==x?x:p[x]=Find(p[x]);
	}
	void Union(int x,int y) {
		p[Find(x)] = Find(y);
	}
} djs;

int main (){
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		memset(w,-1,sizeof(w));
		for (int x=0;n>=x;x++) {
			edg[x].clear();
			ans[x] = 'x';
		}
		djs.init(n);
		for (int x=0;m>x;x++) {
			int i,j;
			scanf("%d %d",&i,&j);
			edg[i].push_back(j);
			edg[j].push_back(i);
			w[i][j] = w[j][i] = 1;
		}
		bool check=true;
		for (int i=1;n>=i;i++) {
			for(int j=i+1;n>=j;j++) {
				if (w[i][j]==-1) {
//					cout<<"i="<<i<<" , j="<<j<<endl;
//					cout<<"ans[i] = "<<ans[i]<< " , ans[j] = "<<ans[j]<<endl;
					if (ans[i]=='x' && ans[j]=='x') {
						ans[i]='a';
						ans[j]='c';
					}
					else if(ans[j]=='x') {
						ans[j]=('c'-ans[i] + 'a');
					}
					else if (ans[i]=='x') {
						ans[i]=('c'-ans[j]+'a');
					}
					else if (ans[i]==ans[j]) {
						check=false;
						break;
					}
				}
			}
		}
		if (!check) puts("No");
		else {
			
			for (int x=1;n>=x;x++) {
				if (ans[x]=='x' )ans[x]='b';
			}
			check=true;
			for (int i=1;n>=i;i++) {
				for (int j=i+1;n>=j;j++) {
					if (w[i][j] == 1) {
						if (ans[i]=='a' && ans[j]=='c') check=false;
						if (ans[j]=='a' && ans[i]=='c') check=false;
					}
				}
			}
			if (check) {
				puts("Yes");
				for (int x=1;n>=x;x++) printf("%c",ans[x]);
				puts("");
			}
			else puts("No");
		}
		
	}
}