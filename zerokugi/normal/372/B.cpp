#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

int w, h, q;
int memo[50][50][50][50]; // [x1][y1][x2][y2]
main(){
	int i,j;
	while(scanf("%d%d%d", &h, &w, &q)!=EOF){
		memset(memo, 0, sizeof(memo));
		REP(i, h)REP(j, w){
			char c;
			scanf(" %c", &c);
			memo[j][i][j][i] = (c=='0');
		}
		REP(x1, w)REP(y1, h){
			int mx = w;
			for(int y2=y1;y2<h;y2++){
				for(int x2=x1;x2<w;x2++){
					if(mx == x2 || !memo[x2][y2][x2][y2]){
						mx = x2;
						break;
					}else if(x1!=x2 || y1!=y2)memo[x1][y1][x2][y2] ++;
				}
				
			}
		}
		REP(y1, h)REP(x1, w){
			for(int y2=y1;y2<h;y2++){
				for(int x2=x1;x2<w;x2++){
					if(y2 == y1 && x2 == x1) continue;
					else if(y2 == y1) memo[x1][y1][x2][y2] += memo[x1][y1][x2-1][y2];
					else if(x2 == x1) memo[x1][y1][x2][y2] += memo[x1][y1][x2][y2-1];
					else memo[x1][y1][x2][y2] += memo[x1][y1][x2-1][y2] + memo[x1][y1][x2][y2-1] - memo[x1][y1][x2-1][y2-1];
				}
			}
		}
/*		REP(y1, h)REP(x1, w){
			REP(y2, h)REP(x2, w){
				printf("(%d, %d)-(%d, %d) = %d\n", x1, y1, x2, y2, memo[x1][y1][x2][y2]);
			}
		}
*/
		REP(i, q){
			int a,b,x2,y2,ans=0;
			scanf("%d%d%d%d", &b, &a, &y2, &x2);
			a--;b--;x2--;y2--;
			for(int x1=a;x1<=x2;x1++)for(int y1=b;y1<=y2;y1++){
				ans += memo[x1][y1][x2][y2];
//				printf("memo[%d][%d][%d][%d] = %d\n", x1, y1, x2, y2, memo[x1][y1][x2][y2]);
			}
			printf("%d\n", ans);
		}
//		cout << ans << endl;
	}
	return 0;
}