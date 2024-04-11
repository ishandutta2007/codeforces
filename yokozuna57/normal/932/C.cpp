#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define pb push_back
#define fr first
#define sc second

int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	
	int sA = 0;
	int tB = n%b;
	for(int s = 0 ; sA <= n ; s ++){
		if(tB == 0){
			vector<int> ret;
			for(int i = 0 ; i < s ; i ++){
				for(int j = i*a+1 ; j < (i+1)*a ; j ++){
					ret.pb(j+1);
				}
				ret.pb(i*a+1);
			}
			for(int i = 0 ; i < (n-sA)/b ; i ++){
				for(int j = s*a+i*b+1 ; j < s*a+(i+1)*b ; j ++){
					ret.pb(j+1);
				}
				ret.pb(s*a+i*b+1);
			}
			for(int i = 0 ; i < n ; i ++){
				if(i != n-1)printf("%d ",ret[i]);
				else printf("%d\n",ret[i]);
			}
			return 0;
		}
		sA += a;
		tB -= a;
		while(tB < 0)tB += b;
	}
	puts("-1");
}