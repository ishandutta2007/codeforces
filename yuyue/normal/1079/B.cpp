#include<bits/stdc++.h>
#define LL long long

using namespace std;

inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
int size;
char ch[500];
void print(int x,int y){
	cout<<x<<" "<<y<<"\n";
	int p=1,c=(x-size%x)%x;
	for (int i=1;i<=x;i++){
		int l=y-1;
		while (l--) cout<<ch[p++];
		if (i<=c) cout<<"*\n";
		else cout<<ch[p++]<<"\n";
	}
}
int main(){
	gets(ch+1);
	size=strlen(ch+1);
	for (int i=1;i<=5;i++){
		int column=size/i;
		if (size%i) column++;
		if (column>20) continue;
		print(i,column); break;
	}
	return 0;
}