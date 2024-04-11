#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 1000;

vector<vector<int>> nodes;
vector<int> ch[10];

typedef pair<int,int> P;
int main(){
	int n;
	scanf("%d",&n);
	
	int a[10][10];
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= n ; j ++){
			scanf("%d",&a[i][j]);
			if(i != j && a[i][j] == 0){
				a[i][j] = 100;
			}
		}
	}
	for(int k = 1 ; k <= n ; k ++){
		for(int i = 1 ; i <= n ; i ++){
			for(int j = 1 ; j <= n ; j ++){
				a[i][j] = min( a[i][j] , a[i][k]+a[k][j] );
			}
		}
	}
	
	//vector<vector<int>> nodes;
	vector<int> cnt;
	bool used[10];
	for(int i = 0 ; i < 10 ; i ++)used[i] = false;
	for(int i = 1 ; i <= n ; i ++){
		if(used[i])continue;
		vector<int> nodes_;
		for(int j = i ; j <= n ; j ++){
			if(a[i][j] < 100 && a[j][i] < 100){
				nodes_.push_back(j);
				used[j] = true;
			}
		}
		nodes.push_back(nodes_);
		int cnt_ = 0;
		for(int j = 1 ; j <= n ; j ++){
			if(a[i][j] < 100){
				cnt_ ++;
			}
		}
		cnt.push_back(cnt_);
	}
	
	int V = nodes.size();
	for(int i = 0 ; i < V ; i ++){
		for(int j = V-2 ; j >= i ; j --){
			if(cnt[j] > cnt[j+1]){
				swap(cnt[j],cnt[j+1]);
				swap(nodes[j],nodes[j+1]);
			}
		}
	}
	char board[200][3][31];
	for(int i = 0 ; i < 200 ; i ++){
		for(int j = 0 ; j < 3 ; j ++){
			for(int k = 0 ; k < 31 ; k ++){
				board[i][j][k] = '.';
			}
		}
	}
	for(int t = 0 ; t < V ; t ++){
		for(int i = 0 ; i < 200 ; i ++){
			board[i][0][29-3*t] = '#';
		}
		for(int x = 0 ; x < V ; x ++){
			for(int y = 0 ; y < V ; y ++){
				board[2*(x*V+y)][1][29-3*t] = '#';
				if(x == t || y == t){
					board[2*(x*V+y)][2][29-3*t] = '#';
				}
				else {
					board[2*(x*V+y)][1][28-3*t] = '#';
					board[2*(x*V+y)][1][27-3*t] = '#';
				}
				if(x == t && a[nodes[x][0]][nodes[y][0]] < 100){
					board[2*(x*V+y)][2][29-3*t] = '.';
				}
			}
		}
		for(int i = 0 ; i < nodes[t].size() ; i ++){
			board[i][0][28-3*t] = '0'+nodes[t][i];
		}
	}
	printf("%d %d %d\n",200,3,31);
	for(int k = 0 ; k < 31 ; k ++){
		for(int j = 0 ; j < 3 ; j ++){
			for(int i = 0 ; i < 200 ; i ++){
				printf("%c",board[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}