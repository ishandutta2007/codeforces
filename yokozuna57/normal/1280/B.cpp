#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		int n,m;
		char a[62][62];
		scanf("%d%d",&n,&m);
		for(int i = 0 ; i < n ; i ++){
			scanf("\n");
			for(int j = 0 ; j < m ; j ++){
				scanf("%c",&a[i][j]);
			}
		}
		
		int cnt_A = 0;
		for(int i = 0 ; i < n ; i ++){
			for(int j = 0 ; j < m ; j ++){
				if(a[i][j] == 'A')cnt_A ++;
			}
		}
		if(cnt_A == 0){
			puts("MORTAL");
			continue;
		}
		if(cnt_A == n*m){
			puts("0");
			continue;
		}
		
		cnt_A = 0;
		for(int j = 0 ; j < m ; j ++){
			if(a[0][j] == 'A')cnt_A ++;
		}
		if(cnt_A == m){
			puts("1");
			continue;
		}
		cnt_A = 0;
		for(int j = 0 ; j < m ; j ++){
			if(a[n-1][j] == 'A')cnt_A ++;
		}
		if(cnt_A == m){
			puts("1");
			continue;
		}
		cnt_A = 0;
		for(int i = 0 ; i < n ; i ++){
			if(a[i][0] == 'A')cnt_A ++;
		}
		if(cnt_A == n){
			puts("1");
			continue;
		}
		cnt_A = 0;
		for(int i = 0 ; i < n ; i ++){
			if(a[i][m-1] == 'A')cnt_A ++;
		}
		if(cnt_A == n){
			puts("1");
			continue;
		}
		
		if(a[0][0] == 'A' || a[0][m-1] == 'A' || a[n-1][0] == 'A' || a[n-1][m-1] == 'A'){
			puts("2");
			continue;
		}
		bool ans2 = false;
		for(int i = 0 ; i < n ; i ++){
			cnt_A = 0;
			for(int j = 0 ; j < m ; j ++){
				if(a[i][j] == 'A')cnt_A ++;
			}
			if(cnt_A == m)ans2 = true;
		}
		for(int j = 0 ; j < m ; j ++){
			cnt_A = 0;
			for(int i = 0 ; i < n ; i ++){
				if(a[i][j] == 'A')cnt_A ++;
			}
			if(cnt_A == n)ans2 = true;
		}
		if(ans2){
			puts("2");
			continue;
		}
		
		bool ans3 = false;
		for(int i = 0 ; i < n ; i ++){
			if(a[i][0] == 'A' || a[i][m-1] == 'A')ans3 = true;
		}
		for(int j = 0 ; j < m ; j ++){
			if(a[0][j] == 'A' || a[n-1][j] == 'A')ans3 = true;
		}
		if(ans3){
			puts("3");
			continue;
		}
		puts("4");
	}
}