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
	static int n;
	static int a[2002];
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i ++){
		scanf("%d",&a[i]);
	}
	
	static int cnt1[2002] = {};
	static int cnt2[2002] = {};
	for(int i = 1 ; i <= n ; i ++){
		if(a[i] == 1)cnt1[i] ++;
		else cnt2[i] ++;
	}
	for(int i = 1 ; i+1 <= n ; i ++){
		cnt1[i+1] += cnt1[i];
	}
	for(int i = n ; i-1 >= 1 ; i --){
		cnt2[i-1] += cnt2[i];
	}
	
	int ret = 0;
	for(int l = 1 ; l <= n ; l ++){
		int dp1 = 0;
		int dp2 = 0;
		for(int r = l ; r <= n ; r ++){
			if(a[r] == 1){
				dp1 = max( dp1 , dp2 ) + 1;
			}
			else dp2 ++;
			ret = max( ret , max( dp1 , dp2 ) + cnt1[l-1] + cnt2[r+1] );
		}
	}
	printf("%d\n",ret);
}