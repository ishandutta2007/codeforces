#include <bits/stdc++.h>


using namespace std;


vector <int> s[4] , sum[4];
int n , opt = 0 , v;
int S[4];
int ans = 0 , res = 0;
char tmp[20];
int main(){
	scanf("%d",&n);
	s[0].push_back(0);
	s[1].push_back(0);
	s[2].push_back(0);
	s[3].push_back(0);
	sum[0].push_back(0);
	sum[1].push_back(0);
	sum[2].push_back(0);
	sum[3].push_back(0);
	
	for (int i = 1;i <= n;i++)
	{
		scanf("%s",tmp);
		scanf("%d",&v);
		opt = (  ( tmp[0] - '0' ) << 1) + tmp[1] - '0';
		
		s[opt].push_back(v);
		if (opt == 3) ans += v;
	}
	
	for (int i = 0;i < 4;i++){
		if (s[i].size() - 1 >= 1) {
			sort  (s[i].begin() , s[i].end());
			
			for (int j = 1;j < s[i].size();j++){
				int k = s[i].size() - j;
				if (k > j) swap(s[i][j] , s[i][k]);
			}
		}
//		printf("%d %d\n",i,s[i].size()-1);
//		for (int j = 0;j < s[i].size();j++) printf("%d ",s[i][j]);puts("");
	}
	
	for (int j = 0;j < 4;j++){
		sum[j].resize(s[j].size());
		for (int i = 1;i < s[j].size();i++){
			sum[j][i] = sum[j][i-1] + s[j][i];
		}
		S[j] = s[j].size() - 1;
	}
	
	if ( s[3].size()==1 && ( s[1].size()==1 || s[2].size()==1 ) ){
		 return puts("0") , 0; 
	}
	
//	cout<<S[0]<<endl<<S[1]<<endl<<S[2]<<endl<<S[3];
	int a10 , a01;
	for (int a00 = 0;a00 <= S[0];a00++){
		int del = S[3] - a00;
		
		
		
		a10 = max( 0 , min(  S[2] , S[1] + del ) ) , a01 = S[1];
		
		if (a10 + del >= a01 && a01 + del >= a10){
			res = max(res , sum[2][a10] + sum[1][a01] + sum[0][a00]);
		}
		
		
		a10 = S[2] , a01 = min(S[1] , max( 0  , S[2] - del ));
		
		if (a10 + del >= a01 && a01 + del >= a10){
			res = max(res , sum[2][a10] + sum[1][a01] + sum[0][a00]);
		}
		
		a10 = S[2] , a01 = max(0 , min(  S[1] , S[2] + del ) );
		
		if (a10 + del >= a01 && a01 + del >= a10){
			res = max(res , sum[2][a10] + sum[1][a01] + sum[0][a00]);
		}
		
		a10 = min(S[2] , max( 0  , S[1] - del ) ), a01 = S[1];
		
		if (a10 + del >= a01 && a01 + del >= a10){
			res = max(res , sum[2][a10] + sum[1][a01] + sum[0][a00]);
		}
		
	}
	printf("%d\n",res + ans);
		
	return 0;
}