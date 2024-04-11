#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x*f;
}
int n;
string ask(int x,int y){
	printf("%d %d\n",x,y);
	fflush(stdout);
	string s;
	cin >> s;
	return s;
}
string ls;
int main(){
	n=read();
	ls=ask(1,0);
	int L=1,R=1e9;
	while (--n){
		int mid=(L+R)>>1;
		string now=ask(1,mid);
		if (now==ls)
			L=mid;
		else
			R=mid;
	}
	printf("0 %d 2 %d",L,R);
	return 0;
}