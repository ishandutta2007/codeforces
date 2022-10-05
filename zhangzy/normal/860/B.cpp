#include<bits/stdc++.h>
using namespace std;

short cnt[100001000];
int ans[71777]={0},anl[71777]={0},n,t;
vector<int>v[71777][10];
char s[23];

void inc(short &x){
	if (x<100) x++;
}
void dec(short &x){
	if (x<100) x--;
}

int main(){
	scanf("%d",&n);
	for (int nnd=1;nnd<=n;nnd++){
		scanf("%s",s+1);
		for (int l=1;l<=9;l++){
			for (int i=1;i+l-1<=9;i++){
				t=0;
				for (int j=i;j<i+l;j++){
					t=t*10+s[j]-'0';
				}
				v[nnd][l].push_back(t);
			}
		}
	}
	for (int l=1;l<=8;l++){
		memset(cnt,0,sizeof cnt);
		for (int i=1;i<=n;i++){
			for (int j=0;j<(int)v[i][l].size();j++){
				inc(cnt[v[i][l][j]]);
			}
		}
		for (int i=1;i<=n;i++){
			if (anl[i]) continue;
			for (int j=0;j<(int)v[i][l].size();j++){
				dec(cnt[v[i][l][j]]);
			}
			for (int j=0;j<(int)v[i][l].size();j++){
				if (cnt[v[i][l][j]]==0){
					anl[i]=l;
					ans[i]=v[i][l][j];
				}
			}
			for (int j=0;j<(int)v[i][l].size();j++){
				inc(cnt[v[i][l][j]]);
			}
		}
	}
	
	for (int i=1;i<=n;i++){
		if (anl[i]){
			if (anl[i]==1) printf("%d\n",ans[i]);
			if (anl[i]==2) printf("%02d\n",ans[i]);
			if (anl[i]==3) printf("%03d\n",ans[i]);
			if (anl[i]==4) printf("%04d\n",ans[i]);
			if (anl[i]==5) printf("%05d\n",ans[i]);
			if (anl[i]==6) printf("%06d\n",ans[i]);
			if (anl[i]==7) printf("%07d\n",ans[i]);
			if (anl[i]==8) printf("%08d\n",ans[i]);
		}else{
			printf("%d\n",v[i][9][0]);
		}
	}
}