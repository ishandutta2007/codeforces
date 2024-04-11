#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

int main(){
	int n,t;
	string s;
	cin >> n >> t >> s;
	
	int k = 0;
	while(s[k] != '.')k ++;
	k ++;
	
	while(1){
		if(k == s.size()){
			cout << s << endl;
			return 0;
		}
		if(s[k] >= '5'){
			if(s[k-1] == '.'){
				if(s[k-2] != '9'){
					s[k-2] ++;
					for(int i = 0 ; i <= k-2 ; i ++){
						cout << s[i];
					}
					cout << endl;
					return 0;
				}
				else {
					int l = k-2;
					while(l > 0){
						s[l] = '0';
						if(s[l-1] != '9'){
							s[l-1] ++;
							for(int i = 0 ; i <= k-2 ; i ++){
								cout << s[i];
							}
							cout << endl;
							return 0;
						}
						l --;
					}
					cout << "1";
					s[l] = '0';
					for(int i = 0 ; i <= k-2 ; i ++){
						cout << s[i];
					}
					cout << endl;
					return 0;
				}
			}
			else {
				if(t == 1 || s[k-1] != '4'){
					s[k-1] ++;
					for(int i = 0 ; i <= k-1 ; i ++){
						cout << s[i];
					}
					cout << endl;
					return 0;
				}
				else {
					s[k-1] = '5';
					k --;
					t --;
					continue;
				}
			}
		}
		k ++;
	}
}