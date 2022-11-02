#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=600005;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int n,m;
struct Point{
	int x,y;
}p1[N],p2[N],O;
LL sqr(int x){
	return 1LL*x*x;
}
LL dis(Point a,Point b){
	return sqr(a.x-b.x)+sqr(a.y-b.y);
}
LL cross(Point a,Point b,Point c){
	return 1LL*(b.x-a.x)*(c.y-a.y)-1LL*(c.x-a.x)*(b.y-a.y);
}
bool cmp_O(Point a,Point b){
	if (a.y==b.y)
		return a.x<b.x;
	return a.y<b.y;
}
bool cmp_Angle(Point a,Point b){
	LL c=cross(O,a,b);
	if (c==0)
		return dis(O,a)<dis(O,b);
	return c>0;
}
int st[N],top;
int Make_Convex(Point P[],int n){
	for (int i=2;i<=n;i++)
		if (!cmp_O(P[1],P[i]))
			swap(P[1],P[i]);
	O=P[1];
	sort(P+2,P+n+1,cmp_Angle);
	top=0;
	st[++top]=1,st[++top]=2;
	for (int i=3;i<=n;i++){
		while (top>=2&&cross(P[st[top-1]],P[st[top]],P[i])<=0)
			top--;
		st[++top]=i;
	}
	for (int i=1;i<=top;i++)
		P[i]=P[st[i]];
	return top;
}
LL s1[N],s2[N];
int Fail[N];
void KMP(LL s[],int n){
    Fail[0]=Fail[1]=0;
    for (int i=2;i<=n;i++){
        int k=Fail[i-1];
        while (k>0&&s[i]!=s[k+1])
            k=Fail[k];
        Fail[i]=k+(s[k+1]==s[i]?1:0);
    }
}
bool check(){
	int k=0;
	for (int i=1;i<=n*6;i++){
		while (k>0&&s2[k+1]!=s1[i])
			k=Fail[k];
		if (s2[k+1]==s1[i])
			k++;
		if (k>=m*3){
			if (i%3==0)
				return 1;
			else
				k=Fail[k];
		}	
	}
	return 0;
}
int main(){
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		p1[i].x=read(),p1[i].y=read();
	for (int i=1;i<=m;i++)
		p2[i].x=read(),p2[i].y=read();
	n=Make_Convex(p1,n);
	m=Make_Convex(p2,m);
	for (int i=1;i<=n;i++){
		s1[i*3-2]=dis(p1[i],p1[i%n+1]);
		s1[i*3-1]=cross(p1[i],p1[i%n+1],p1[(i+1)%n+1]);
		s1[i*3]=dis(p1[i],p1[(i+1)%n+1]);
	}
	for (int i=1;i<=m;i++){
		s2[i*3-2]=dis(p2[i],p2[i%m+1]);
		s2[i*3-1]=cross(p2[i],p2[i%m+1],p2[(i+1)%m+1]);
		s2[i*3]=dis(p2[i],p2[(i+1)%m+1]);
	}
	for (int i=1;i<=n*3;i++)
		s1[i+n*3]=s1[i];
	KMP(s2,m*3);
	puts(n==m&&check()?"YES":"NO");
	return 0;
}