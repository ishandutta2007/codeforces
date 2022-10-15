#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=207;
int n,cnt[6];
char s[N],t[6]={'t','r','y','g','u','b'};
vector<char>vec;
inline void work(){
	n=read(),scanf("%s",s+1),vec.clear();
	for(int i=0;i<6;i++)cnt[i]=0;
	for(int i=1;i<=n;i++){
		switch(s[i]){
		case 't':{cnt[0]++;break;}
		case 'r':{cnt[1]++;break;}
		case 'y':{cnt[2]++;break;}
		case 'g':{cnt[3]++;break;}
		case 'u':{cnt[4]++;break;}
	case 'b':{cnt[5]++;break;}
		default:{vec.push_back(s[i]);break;}
		}
	}
	for(char x:vec)putchar(x);
	for(int i=5;~i;i--)
		while(cnt[i])putchar(t[i]),cnt[i]--;
	puts("");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}