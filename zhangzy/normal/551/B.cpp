#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mx;
struct Str{
    char s[233333];
    int l,cnt[26];
}a,b,c;

void in(Str &x){
	scanf("%s",x.s+1);
	x.l=strlen(x.s+1);
	memset(x.cnt,0,sizeof x.cnt);
	for (int i=1;i<=x.l;i++){
		x.cnt[x.s[i]-'a']++;
	}
}

ll t[26];
int doit(int x,int ttt){
	if (ttt){
		for (int i=1;i<=x;i++) printf("%s",b.s+1);
	}
	for (int i=0;i<26;i++){
		t[i]=(ll)a.cnt[i]-(ll)b.cnt[i]*x;
		if (t[i]<0) return 0;
	}
	int an=1e6;
	for (int i=0;i<26;i++){
		if (c.cnt[i]>0){
			an=min((ll)an,t[i]/c.cnt[i]);
		}
	}
	if (ttt){
		for (int i=1;i<=an;i++) printf("%s",c.s+1);
		for (int i=0;i<26;i++){
			t[i]-=an*c.cnt[i];
			for (int j=1;j<=t[i];j++){
				printf("%c",'a'+i);
			}
		}
	}
	return x+an;
}

int main(){
    in(a);in(b);in(c);
    mx=0;
    for (int i=0;i<=a.l;i++){
    	mx=max(mx,doit(i,0));
	}
	for (int i=0;i<=a.l;i++){
		if (mx==doit(i,0)){
			doit(i,1);
			return 0;
		}
	}
}