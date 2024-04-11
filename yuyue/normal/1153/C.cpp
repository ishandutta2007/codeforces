#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=3e5+110;
int n;
char ch[M],p[M];
int s1[M],s2[M],s3[M];
int q1(int l,int r){
	return s1[r]-s1[l-1];
}
int q2(int l,int r){
	return s2[r]-s2[l-1];
}
int q3(int l,int r){
	return s3[r]-s3[l-1];
}
int main(){
	n=read(); scanf("%s",ch+1);
	if (ch[1]==')'){
		printf(":(\n");
		return 0;
	}
	for (int i=2;i<=n;i++){
		s1[i]=s1[i-1];
		if (ch[i]=='(') s1[i]++;
		s2[i]=s2[i-1];
		if (ch[i]==')') s2[i]++;
		s3[i]=s3[i-1];
		if (ch[i]=='?') s3[i]++;
	}
	int yy=0;
	for (int i=1;i<n;i++){
		if (s1[i]+s3[i]-s2[i]+1==q2(i+1,n)+q3(i+1,n)-q1(i+1,n)) {
			yy=i;
			break;
		}
	}
	if (!yy){
		printf(":(\n");
		return 0;
	}
	int num=1;
//	cout<<yy<<"\n";
	p[1]='(';
	for (int i=2;i<=n;i++){
		if (ch[i]=='(') p[i]='(',num++;
		if (ch[i]==')') p[i]=')',num--;
		if (ch[i]=='?'){
			if (i<=yy) p[i]='(',num++;
			else p[i]=')',num--;
		}
//		cout<<p[i]<<" "<<num<<" "<<i<<"\n";
		if (num<=0&&i<n || num!=0 && i==n) {
			printf(":(\n");
			return 0;
		}
		
	}
	cout<<(p+1)<<"\n";
    return 0;
}