#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

int n,m;
char c[502][502];

void solve(){
	for(int j=0;j<m;j++)c[0][j]='X';
	if(n>=2){
		if(m%3==1){
			for(int j=0;j<m;j++){
				if(j%3==0){
					for(int i=0;i<n;i++)c[i][j]='X';
				}
				else if(j%3==1){
					if(c[1][j]=='X'||c[1][j+1]=='X'){
						c[0][j]=c[0][j+1]='.';
						c[1][j]=c[1][j+1]='X';
					}
				}
			}
		}
		else if(m%3==2){
			for(int j=0;j<m;j++){
				if(j%3==0){
					for(int i=0;i<n;i++)c[i][j]='X';
				}
				else if(j==m-1){
					if(c[1][j]=='X'){
						c[0][j]='.';
					}
				}
				else if(j%3==1){
					if(c[1][j]=='X'||c[1][j+1]=='X'){
						c[0][j]=c[0][j+1]='.';
						c[1][j]=c[1][j+1]='X';
					}
				}
			}
		}
		else {
			for(int j=0;j<m;j++){
				if(j%3==1){
					for(int i=0;i<n;i++)c[i][j]='X';
				}
				else if(j==0||j==m-1){
					if(c[1][j]=='X'){
						c[0][j]='.';
					}
				}
				else if(j%3==2){
					if(c[1][j]=='X'||c[1][j+1]=='X'){
						c[0][j]=c[0][j+1]='.';
						c[1][j]=c[1][j+1]='X';
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%c",c[i][j]);
		}
		puts("");
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("\n");
			for(int j=0;j<m;j++){
				scanf("%c",&c[i][j]);
			}
		}
		solve();
	}
}