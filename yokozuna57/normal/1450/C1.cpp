#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define fr first
#define sc second

int n;
char c[302][302];

void solve(){
	int a[2][3]={};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(c[i][j]=='O'){
				a[0][(i+j)%3]++;
			}
			else if(c[i][j]=='X'){
				a[1][(i+j)%3]++;
			}
		}
	}
	int k=0;
	for(int i=0;i<2;i++)for(int j=0;j<3;j++)k+=a[i][j];
	int t[2]={0,1};
	while(1){
		if(a[0][t[0]]+a[1][t[1]]<=k/3){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(c[i][j]=='O'&&(i+j)%3==t[0])c[i][j]='X';
					else if(c[i][j]=='X'&&(i+j)%3==t[1])c[i][j]='O';
				}
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					printf("%c",c[i][j]);
				}
				printf("\n");
			}
			break;
		}
		t[0]++;
		t[1]++; if(t[1]==3)t[1]=0;
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("\n");
			for(int j=0;j<n;j++){
				scanf("%c",&c[i][j]);
			}
		}
		solve();
	}
}