#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

const int MAX_N = 3e5 +6;

deque<int> note[MAX_N];
int mp[MAX_N];
int used[MAX_N];

int main () {
	int n,q;
	while (scanf("%d %d",&n,&q) != EOF) {
		int sum=0;
		int id=0;
		int num=0;
		for (int x=0;q>x;x++) {
			int i,j;
			scanf("%d %d",&i,&j);
			if (i==1) {
				mp[num] = j;
				note[j].push_back(num);
				sum++;
				num++;
			}
			else if (i==2) {
				while (note[j].empty() == false) {
					int tmp=note[j].front();
					note[j].pop_front();
					if (used[tmp]==1) continue;
					used[tmp]=1;
					sum--;
				}
			}
			else if (i==3) {
				if (id>j) {
					printf("%d\n",sum);
					continue;
				}
				for (int y=id;j>y;y++) {
					if (used[y]==1) continue;
					if (note[mp[y]].front() == y)note[mp[y]].pop_front();
					used[y]=1;
					sum--;
				}
				id=j;
			}
			printf("%d\n",sum);
		}
	}
}