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

int n, m;
main(){
	while(cin >> n >> m){
		int a=0, b=0, c=0;
		REP(i, n)REP(i, m){
			int t;
			cin >> t;
			if(t == 11) a++;
			else if(t == 0) c++;
			else  b++;
			
		}
		int a1 = a%n;
		int a2 = a/n;
		int b1 = b%n;
		int b2 = b/n;
		int f = 0;
		int k = 0;
		REP(i, n){
			REP(j, m){
				if(a){
					cout << "11";
					a --;
					f = j;
					k = i;
				}else if(c && k == i-1 && j <= f){
					cout << "00";
					c --;
				}else if(b){
					cout << (i&1?"01":"10");
					b --;
				}else if(c){
					cout << "00";
					c --;
				}
				if(j==m-1) cout << endl;
				else cout << " ";
			}
		}
	}
	return 0;
}