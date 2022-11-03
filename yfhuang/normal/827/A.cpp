#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int maxn = 1e6 + 6;

vector<int> g[2 * maxn];
const int maxm = 1e5 + 5;
string s[maxm];
int len[maxm];

char a[maxn];
char b[10 * maxn];

int main(){
	int n;
	cin >> n;
	int mx = 0;
	for(int i = 1;i <= n;i++){
		scanf("%s",a);
		len[i] = strlen(a);
		string ss = "";
		for(int j = 0;j < len[i];j++){
			ss += a[j];
		}
		s[i] = ss;
		int k;
		scanf("%d",&k);
		for(int j = 1;j <= k;j++){
			int x;
			scanf("%d",&x);
			g[x].push_back(i);
			mx = max(mx,x + len[i] - 1);
		}
	}
	//int now = 1;
	int front = 0,rear = 0;
	string ans = "";
	for(int i = 1;i <= mx;i++){
		if(g[i].size() > 0){
			int id = g[i][0];
			int mxl = len[g[i][0]];
			for(int j = 1;j < g[i].size();j++){
				if(len[g[i][j]] > mxl) mxl = len[g[i][j]],id = g[i][j];
			}
			if(mxl > rear - front){
				int now = rear - front;
				for(int j = now;j < len[id];j++){
					b[rear++] = s[id][j];
				}
			}
		}
		if(front == rear){
			ans += "a";
		}
		else ans += b[front++];
	}
	cout << ans << endl;
	return 0;
}