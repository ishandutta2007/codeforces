#include<bits/stdc++.h>
using namespace std;

bitset<401>f[401],ful,a[26][401];
int n,m,nn,mm;
char s[402][402],ss[402][402];

int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	scanf("%d%d",&nn,&mm);
	for (int i=0;i<nn;i++){
		scanf("%s",ss[i]);
	}
	for (int i=0;i<m;i++) ful[i]=1;
	for (int i=0;i<n;i++) f[i]|=ful;
	for (int jj=0;jj<mm;jj++){
		for (int i=0;i<26;i++){
			for (int j=0;j<n;j++){
				a[i][j].reset();
			}
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				a[s[i][j]-'a'][i][(j-jj+m*400)%m]=1;
			}
		}
		for (int ii=0;ii<nn;ii++){
			if (ss[ii][jj]=='?') continue;
			for (int i=0;i<n;i++){
				f[(i-ii+n*400)%n]&=a[ss[ii][jj]-'a'][i];
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			printf("%d",f[i][j]?1:0);
		}printf("\n");
	}
}