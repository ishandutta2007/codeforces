#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N =306;

int dx[4] = {1,-1,0,0},dy[4]={0,0,1,-1};
int a[MAX_N][MAX_N];

int main () {
	int n,m,k;
	while (scanf("%d %d %d",&n,&m,&k) != EOF) {
		deque<pii> tmp;
		int _=1,__=1;
		int cnt=0;
		memset(a,-1,sizeof(a));
		for (int i=1;n>=i;i++) {
			for (int j=1;m>=j;j++) {
				a[i][j]=0;
			}
		}
		while (cnt!=n*m) {
			cnt++;
			tmp.push_back(make_pair(_,__));
			a[_][__]=1;
			for (int i=0;4>i;i++) {
				int ala=_+dx[i],lal=__+dy[i];
				if (a[ala][lal]==0) {
					_=ala;
					__=lal;
					break;
				}
			}
		}
		for (int i=1;k>=i;i++) {
			if (i==k) {
				printf("%d",n*m-2*(k-1));
				while (tmp.size()) {
					cout<<' '<<tmp[0].first<<' '<<tmp[0].second;
					tmp.pop_front();
				}
			}
			else {
				printf("2");
				int _=2;
				while (_--) {
					cout<<' '<<tmp[0].first<<' '<<tmp[0].second;
					tmp.pop_front();
				}
				
			}
			puts("");
		}
	}
}