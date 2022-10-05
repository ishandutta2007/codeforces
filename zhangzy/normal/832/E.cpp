#include<bits/stdc++.h>
using namespace std;
int t[520][517],n,m,f[517];
char s[520233];

int all0(int x,int y){
	for (int i=x;i<=n;i++){
		if (t[i][y]>0){
			return i;
		}
	}
	return 0;
}

int xxxg(int *tem){
	for (int i=1;i<=m;i++){
		if (tem[i]>0){
			return 0;
		}
	}
	return 1;
}

int GT(){
	int p=1,fir,a,b;
	for (int i=1;i<n;i++){
		while ((fir=all0(i,p))==0&&p<=m) p++;
		if (p>m) break;
		if (fir!=i){
			swap(t[fir],t[i]);
		}
		b=t[i][p];
		for (int j=i+1;j<=n;j++){
			a=t[j][p];
			if (a==0){
				continue;
			}
			for (int k=p;k<=m;k++){
				t[j][k]=(t[j][k]*b-t[i][k]*a+233520)%5;
			}
		}
		p++;
	}
	p=0;
	for (int i=1;i<=n;i++){
		p+=xxxg(t[i]);
	}
	return p;
}

void cg(){
	for (int i=1;i<=m;i++){
		f[i]=(s[i]-'a')%5;
	}
}

bool doit(){
	int p=1,a,b;
	for (int i=1;i<=n;i++){
		while (t[i][p]==0&&p<=m){
			if (f[p]>0) return 0;
			p++;
		}
		if (p>m) return 1;
		b=t[i][p];
		a=f[p];
		if (a==0) continue;
		for (int k=p;k<=m;k++){
			f[k]=(f[k]*b-t[i][k]*a+233520)%5;
		}
		p++;
		if (p>m) return 1;
	}
	for (int i=p;i<=m;i++){
		if (f[i]>0){
			return 0;
		}
	}
	return 1;
}

int main(){
	scanf("%d%d\n",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		cg();
		memcpy(t[i],f,sizeof(f));
	}
	int times=GT();
	long long ans=1;
	for (int i=1;i<=times;i++){
		ans=(ans*5)%1000000007;
	}
	int T;
	scanf("%d\n",&T);
	while (T--){
		scanf("%s",s+1);
		cg();
		if (doit()){
			printf("%I64d\n",ans);
		}else{
			printf("0\n");
		}
	}
}