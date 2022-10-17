#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define Pair pair<int,int>
#define ll long long
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
#define MAXN 2005
int n, m;
int a[MAXN][MAXN], b[MAXN][MAXN]; 
struct Node {
	int x, y;
};
//bool cmp1(Node x, Node y) {
//	return x.x < y.x;
//}
//bool cmp2(Node x, Node y) {
//	return x.y < y.y;
//}
struct Square {
	int sx, sy, ex, ey;
};
vector < Node > pos[30];
vector < Square > ans;
int main()
{
    int T; cin >> T;
    while(T--) {
    	For(i, 1, 29) pos[i].clear();
    	ans.clear();
    	cin >> n >> m;
    	int maxi = 0;
    	For(i, 1, n)
    		For(j, 1, m)
    			a[i][j] = b[i][j] = 0;
    	For(i, 1, n) {
    		string s; cin >> s;
    		For(j, 1, m)
    			if(s[j-1] != '.')  {
    				a[i][j] = s[j-1] - 'a' + 1;
    				pos[a[i][j]].push_back((Node) {i, j});
    				maxi = max(maxi, a[i][j]);
				}
		}
		int num = 0;
		For(k, 1, maxi) {
			if(pos[k].size() == 0) {
				int X = pos[maxi][0].x, Y = pos[maxi][0].y;
				ans.push_back((Square) {X, Y, X, Y});
			} else if(pos[k].size() == 1) {
				int X = pos[k][0].x, Y = pos[k][0].y;
				ans.push_back((Square) {X, Y, X, Y});
			} else {
				int X1 = pos[k][0].x, Y1 = pos[k][0].y;
				int X2 = pos[k][1].x, Y2 = pos[k][1].y;
				if(X1 != X2 && Y1 != Y2) {
					puts("NO");
					goto end;
				}
				if(X1 == X2) {
					for(int i = 2; i < pos[k].size(); i++) {
						if(pos[k][i].x != X1) {
							puts("NO");
							goto end;
						}
					}
				}
				if(Y1 == Y2) {
					for(int i = 2; i < pos[k].size(); i++) {
						if(pos[k][i].y != Y1) {
							puts("NO");
							goto end;
						}
					}
				}
				ans.push_back((Square) {X1, Y1, pos[k][pos[k].size()-1].x, pos[k][pos[k].size()-1].y});
			}
		}
		for(int i = 0; i < maxi; i++) {
			For(j, ans[i].sx, ans[i].ex) {
				For(k, ans[i].sy, ans[i].ey) {
					b[j][k] = i+1;
				}
			}
		}
		For(i, 1, n) {
			For(j, 1, m) {
				if(a[i][j] != b[i][j]) {
					puts("NO");
					goto end;
				}//
			}
		}
		printf("YES\n");
		printf("%d\n", maxi);
		for(int i = 0; i < maxi; i++) {
			printf("%d %d %d %d\n", ans[i].sx, ans[i].sy, ans[i].ex, ans[i].ey);
		}
		end:;
	}
    return 0;
}