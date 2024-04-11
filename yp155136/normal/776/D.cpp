#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 1e5 + 6;

vector<int> ala[MAX_N];
vector<int> num[MAX_N];

struct DisjointSet {
	int p[MAX_N];
	void init(int n) {
		for (int i=0;n>=i;i++) p[i]=i;
	}
	int Find(int x) {
		return p[x]==x?x:p[x]=Find(p[x]);
	}
	void Union(int x,int y) {
		p[Find(x)] = Find(y);
	}
} djs;

int a[MAX_N];
int choice[MAX_N];
int cc[MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		for (int i=0;n>=i;i++) {
			ala[i].clear();
			num[i].clear();
		} 
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
		}
		djs.init(n);
		for (int i=1;m>=i;i++) {
			int x;
			scanf("%d",&x);
			for (int j=0;x>j;j++) {
				int t;
				scanf("%d",&t);
				ala[i].push_back(t);
				num[t].push_back(i);  //number
			}
		}
		string ans="YES";
		//for each union, get the one is started
		memset(choice,-1,sizeof(choice));
		memset(cc,-1,sizeof(cc));
		for (int i=1;m>=i;i++) {
			if (choice[i]==-1) {
				//start the union like things XD
				queue<pii> que;
				choice[i]=1;  //open this
				for (auto j:ala[i]) {
					que.push(make_pair(j,i));  //number, from
				}
				bool half=true;
				while (!que.empty()) {
					pii t=que.front();
					que.pop();
					int tmp=0;
					int cnt=0;
					for (auto k:num[t.first]) {
						if (choice[k]!=-1) tmp+=choice[k],cnt++;
					}
					if (cnt==2 && (a[t.first]+tmp)%2!=1 ) {
						half=false;
					}
					else if (cnt==1){
						for (auto k:num[t.first]) {
							if (choice[k]==-1) {
								choice[k] = (1-(a[t.first]+tmp)+4)%2;
								for (auto l:ala[k]) {
									que.push(make_pair(l,k));
								}
							}
						}
					}
				}
				while (!que.empty()) que.pop();
				cc[i]=0;
				for (auto j:ala[i]) {
					que.push(make_pair(j,i));  //number, from
				}
				bool half2=true;
				while (!que.empty()) {
					pii t=que.front();
					que.pop();
					int tmp=0;
					int cnt=0;
					for (auto k:num[t.first]) {
						if (cc[k]!=-1) tmp+=cc[k],cnt++;
					}
					if (cnt==2 && (a[t.first]+tmp)%2!=1 ) {
						half2=false;
					}
					else if (cnt==1){
						for (auto k:num[t.first]) {
							if (cc[k]==-1) {
								cc[k] = (1-(a[t.first]+tmp)+4)%2;
								for (auto l:ala[k]) {
									que.push(make_pair(l,k));
								}
							}
						}
					}
				}
				if (!half && !half2) ans="NO"; 
			}
		}
		cout<<ans<<endl;
	}
}