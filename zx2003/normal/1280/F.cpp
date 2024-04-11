#include<bits/stdc++.h>
using namespace std;
const int N=35,L=10005;
int T,k,i,j,n,m;
int a[2][N],b[N*2],bb[N*2];
char cc[5],ans[L],*ass,out[26][L],*pp[26];
inline void getseq(){
	int xb=0;
	for(j=0;j<n;++j)if(a[0][j])b[xb++]=a[0][j];
	for(j=n-1;j>=0;--j)if(a[1][j])b[xb++]=a[1][j];
}
inline void push(char c1,char c2){*pp[c1-'A']++=c2;}
inline void opt(char c){*ass++=c;}
inline void get_rot2(int x,char c){
	int i;x-=k;if(x<0)x+=m;for(i=0;i<x;++i)push(c,'R');
	for(i=0;i<k;++i)push(c,'l');push(c,'u');
	for(i=0;i<k;++i)push(c,'r');push(c,'d');
	for(i=x;i<m;++i)push(c,'R');
}
inline void rot2(int x){
	int i;x-=k;if(x<0)x+=m;for(i=0;i<x;++i)opt('R');
	for(i=0;i<k;++i)opt('l');opt('u');
	for(i=0;i<k;++i)opt('r');opt('d');
	for(i=x;i<m;++i)opt('R');
}
inline void rot3(int x){
	swap(b[x],b[x+1]);swap(b[x+1],b[x+2]);
	if(k==1)return rot2(x);
	int i;
	if(x>=8)opt(x/8-1+'A');if(x%8)opt(x%8-1+'I');
	opt('U');
	x=m-x;if(x>=8)opt(x/8-1+'A');if(x%8)opt(x%8-1+'I');
}
int calcI(int*b){int ass=0;for(i=0;i<m;++i)for(j=i+1;j<m;++j)ass+=b[i]>b[j];return ass;}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&k);n=k*2+1;m=n*2-1;ass=ans;
		for(i=0;i<2;++i)for(j=0;j<n;++j)scanf("%s",cc),*cc=='E'?a[i][j]=0:sscanf(cc,"%d",a[i]+j);
		for(j=0;j+1<n;++j)for(i=0;i<2;++i)if(a[i][j]==0)opt('r'),swap(a[i][j],a[i][j+1]);
		if(a[0][n-1]==0)opt('d'),swap(a[0][n-1],a[1][n-1]);;
		int i1,i2;getseq();i1=calcI(b);
		for(i=0;i<m;++i)bb[i]=i+1;reverse(bb+n,bb+m);i2=calcI(bb);
		if((i2-i1)&1){puts("SURGERY FAILED");continue;}
		for(i=0;i<26;++i)pp[i]=out[i];
		for(i=n-1;i;--i)push('R','l');push('R','u');for(i=0;i<n-1;++i)push('R','r');push('R','d');
		for(i=1;i<=8;++i)push('A','R');for(i=2;i<=8;++i)push('A'+i-1,'A'+i-2),push('A'+i-1,'A');
		push('I','R');for(i=1;i<8;++i)push('I'+i,'I'+i-1),push('I'+i,'R');
		get_rot2(0,'S');get_rot2(1,'T');
		push('U','T');push('U','T');for(i=1;i<=2*k;i+=2)push('U','T'),push('U','S');
		for(i=0;i+2<m;++i){
			for(j=i;b[j]!=bb[i];++j);
			for(;j>i+1;rot3(j-2),--j);if(j>i)rot3(j-1);
		}
		puts("SURGERY COMPLETE");
		*ass=0;
		puts(ans);
		for(i=0;i<26;++i)if(pp[i]!=out[i])*pp[i]=0,printf("%c %s\n",i+'A',out[i]);
		puts("DONE");
	}
	return 0;
}