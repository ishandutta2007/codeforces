#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second

int main(){
	static string s;
	static int cnt[30][200010];
	cin >> s;
	for(int i = 0 ; i < 26 ; i ++){
		cnt[i][0] = 0;
		for(int j = 1 ; j <= s.size() ; j ++){
			cnt[i][j] = cnt[i][j-1];
			if(s[j-1] == 'a'+i)cnt[i][j] ++;
		}
	}
	
	int q;
	scanf("%d",&q);
	for(;q>0;q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int CNT = 0;
		for(int i = 0 ; i < 26 ; i ++){
			if(cnt[i][r]-cnt[i][l-1] > 0)CNT ++;
		}
		if(CNT == 1){
			if(l<r)puts("No");
			else puts("Yes");
		}
		else if(CNT == 2){
			if(s[l-1] == s[r-1])puts("No");
			else puts("Yes");
		}
		else puts("Yes");
	}
}