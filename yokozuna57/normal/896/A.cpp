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
	string S = "What are you doing at the end of the world? Are you busy? Will you save us?";
	
	string S1 = "What are you doing while sending ";
	string S2 = "? Are you busy? Will you send ";
	string S3 = "?";
	
	ll n1 = S1.size();
	ll n2 = S2.size();
	ll n3 = S3.size();
	
	static ll l[100010] = {};
	l[0] = S.size();
	rep1(i,100009){
		l[i] = n1 + 1 + l[i-1] + 1 + n2 + 1 + l[i-1] + 1 + n3;
		if(l[i] > 1000000000000000000)l[i] = 1000000000000000001;
	}
	
	int q;
	cin >> q;
	rep(ppp,q){
		ll n,k;
		cin >> n >> k;
		
		while(1){
			if(l[n] < k){
				printf(".");
				break;
			}
			if(n == 0){
				printf("%c",S[k-1]);
				break;
			}
			if(1 <= k && k <= n1){
				printf("%c",S1[k-1]);
				break;
			}
			if(k == n1+1 || k == n1+1+l[n-1]+1 || k == n1+1+l[n-1]+1+n2+1 || k == n1+1+l[n-1]+1+n2+1+l[n-1]+1){
				printf("\"");
				break;
			}
			if(n1+1+l[n-1]+1+1 <= k && k <= n1+1+l[n-1]+1+n2){
				printf("%c",S2[k-(n1+1+l[n-1]+1+1)]);
				break;
			}
			if(k == n1+1+l[n-1]+1+n2+1+l[n-1]+2){
				printf("?");
				break;
			}
			if(n1+1+1 <= k && k <= n1+1+l[n-1]){
				k -= n1+1;
				n --;
			}
			else {
				k -=  n1 + 1 + l[n-1] + 1 + n2 + 1;
				n --;
			}
		}
	}
}