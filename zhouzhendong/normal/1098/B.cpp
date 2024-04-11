#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
const int N=300005;
const LL INF=1LL<<60;
int n,m;
char ch[4]={'A','C','G','T'};
int v[300],a[N],b[N],t[N],ans;
char s[N];
int &A(int i,int j){
	return a[(i-1)*m+j];
}
int &B(int i,int j){
	return b[(i-1)*m+j];
}
int &T(int i,int j){	
	return t[(i-1)*m+j];
}
int get(int c,int v1,int v2){
	int c1=0,c2=0;
	for (int i=1;i<=n;i++){
		if (i&1){
			c1+=A(i,c)!=v1;
			c2+=A(i,c)!=v2;
		}
		else {
			c1+=A(i,c)!=v2;
			c2+=A(i,c)!=v1;
		}
	}
	if (c1<=c2){
		for (int i=1;i<=n;i++)
			if (i&1)
				T(i,c)=v1;
			else
				T(i,c)=v2;
		return c1;
	}
	else {
		for (int i=1;i<=n;i++)
			if (i&1)
				T(i,c)=v2;
			else
				T(i,c)=v1;
		return c2;
	}
}
int get2(int c,int v1,int v2){
	int c1=0,c2=0;
	for (int i=1;i<=m;i++){
		if (i&1){
			c1+=A(c,i)!=v1;
			c2+=A(c,i)!=v2;
		}
		else {
			c1+=A(c,i)!=v2;
			c2+=A(c,i)!=v1;
		}
	}
	if (c1<=c2){
		for (int i=1;i<=m;i++)
			if (i&1)
				T(c,i)=v1;
			else
				T(c,i)=v2;
		return c1;
	}
	else {
		for (int i=1;i<=m;i++)
			if (i&1)
				T(c,i)=v2;
			else
				T(c,i)=v1;
		return c2;
	}
}
int main(){
	v['A']=0,v['C']=1,v['G']=2,v['T']=3;
	n=read(),m=read();
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=m;j++)
			A(i,j)=v[s[j]];
	}
	ans=n*m;
	for (int i=0;i<4;i++)
		for (int j=i+1;j<4;j++){
			int now=0;
			int ii=-1,jj;
			for (int k=0;k<4;k++)
				if (k!=i&&k!=j)
					if (!~ii)
						ii=k;
					else
						jj=k;
			for (int k=1;k<=m;k++)
				if (k&1)
					now+=get(k,i,j);
				else
					now+=get(k,ii,jj);
			if (now<ans){
				ans=now;
				for (int i=1;i<=n*m;i++)
					b[i]=t[i];
			}
		}
	for (int i=0;i<4;i++)
		for (int j=i+1;j<4;j++){
			int now=0;
			int ii=-1,jj;
			for (int k=0;k<4;k++)
				if (k!=i&&k!=j)
					if (!~ii)
						ii=k;
					else
						jj=k;
			for (int k=1;k<=n;k++)
				if (k&1)
					now+=get2(k,i,j);
				else
					now+=get2(k,ii,jj);
			if (now<ans){
				ans=now;
				for (int i=1;i<=n*m;i++)
					b[i]=t[i];
			}
		}
	for (int i=1;i<=n;i++,puts(""))
		for (int j=1;j<=m;j++)
			putchar(ch[B(i,j)]);
	return 0;
}