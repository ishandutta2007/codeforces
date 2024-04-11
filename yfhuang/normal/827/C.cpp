#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int n,k;


int q;

const int maxn = 100000 + 5;

int d[4][11][10][maxn];

char s[maxn];

void add(int a1,int a2,int a3,int x,int val){
	for(int i = x;i < maxn;i += i & -i){
		d[a1][a2][a3][i] += val;
	}
}

int sum(int a1,int a2,int a3,int x){
	int ret = 0;
	for(int i = x;i > 0;i -= i & -i){
		ret += d[a1][a2][a3][i];
	}
	return ret;
}

int id(char c){
	int x = -1;
	if(c == 'A') x = 0;
	else if(c == 'C') x = 1;
	else if(c == 'G') x = 2;
	else if(c == 'T') x = 3;
	return x;
}

int main(){
	scanf("%s",s + 1);
	int len = strlen(s + 1);
	for(int i = 1;i <= len;i++){
		for(int j = 1;j <= 10;j++){
			add(id(s[i]),j,i % j,i,1);
		}
	}
	cin >> q;
	for(int i = 1;i <= q;i++){
		int type;
		char e[11];
		scanf("%d",&type);
		if(type == 1){
			int x;char ss[3];
			scanf("%d",&x);
			scanf("%s",ss);
			int idd = id(s[x]);
			int idd1 = id(ss[0]);
			for(int j = 1;j <= 10;j++){
				add(idd,j,x % j,x,-1);
				add(idd1,j,x % j,x,1);
			}
			s[x] = ss[0];
		}else{
			int l,r;
			scanf("%d%d",&l,&r);
			scanf("%s",e);
			int lens = strlen(e);
			int ans = 0;
			
			for(int j = 0;j < lens;j++){
				ans += sum(id(e[j]),lens,(j  + l) % lens,r) - sum(id(e[j]),lens,(j  + l) % lens,l - 1);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}