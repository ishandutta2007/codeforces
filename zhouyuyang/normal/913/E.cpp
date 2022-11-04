#include<bits/stdc++.h>
using namespace std;
char ans[300][2][50];
#define pa pair<int,int>
pa q[100000];
int h,t;
bool better(char *s,char *t){
	int ls=strlen(s+1);
	int lt=strlen(t+1);
	if (!lt) return 0;
	if (!ls) return 1;
	if (ls!=lt) return lt<ls;
	for (int i=1;i<=ls;i++)
		if (s[i]!=t[i]) return t[i]<s[i];
	return 1;
}
bool Better(char *s,char *t,char jdb){
	char tmp1[100];
	char tmp2[100];
	int len1=0;
	int len2=0;
	int len3=strlen(s+1);
	int len4=strlen(t+1);
	for (int i=1;i<=len3;i++)
		tmp1[++len1]=s[i];
	tmp1[++len1]=jdb;
	for (int i=1;i<=len4;i++)
		tmp1[++len1]=t[i];
	for (int i=1;i<=len4;i++)
		tmp2[++len2]=t[i];
	tmp2[++len2]=jdb;
	for (int i=1;i<=len3;i++)
		tmp2[++len2]=s[i];
	for (int i=1;i<=len3+len4+1;i++)
		if (tmp1[i]!=tmp2[i])
			return tmp1[i]>tmp2[i];
	return better(tmp1,tmp2);
}
void update(int x,int y,char *a){
	if (better(ans[x][y],a)){
		memcpy(ans[x][y],a,sizeof(ans[x][y]));
		q[++t]=pa(x,y);
	}
}
int main(){
	ans[15][0][1]='x';
	ans[51][0][1]='y';
	ans[85][0][1]='z';
	q[1]=pa(15,0);
	q[2]=pa(51,0);
	q[3]=pa(85,0);
	h=0,t=3;
	while (h!=t){
		int x=q[++h].first,y=q[h].second;
		//printf("%d %d\n",x,y);
		char a[50],b[50];
		int top,len=strlen(ans[x][y]+1);
		memset(a,0,sizeof(a)); top=0;
		a[++top]='!';
		if (len!=1) a[++top]='(';
		for (int i=1;i<=len;i++)
			a[++top]=ans[x][y][i];
		if (len!=1) a[++top]=')';
		update(255-x,0,a);
		for (int i=1;i<h;i++){
			memset(a,0,sizeof(a)); top=0;
			char *ss=ans[x][y];
			char *tt=ans[q[i].first][q[i].second];
			if (Better(ss,tt,'|')) swap(ss,tt);
			int len1=strlen(ss+1);
			int len2=strlen(tt+1);
			for (int j=1;j<=len1;j++)
				a[++top]=ss[j];
			a[++top]='|';
			for (int j=1;j<=len2;j++)
				a[++top]=tt[j];
			update(x|q[i].first,1,a);
			memset(a,0,sizeof(a)); top=0;
			memset(b,0,sizeof(b)); int topb=0;
			ss=ans[x][y];
			tt=ans[q[i].first][q[i].second];
			len1=strlen(ss+1);
			len2=strlen(tt+1);
			if (y) a[++top]='(';
			for (int j=1;j<=len1;j++)
				a[++top]=ss[j];
			if (y) a[++top]=')';
			if (q[i].second) b[++topb]='(';
			for (int j=1;j<=len2;j++)
				b[++topb]=tt[j];
			if (q[i].second) b[++topb]=')';
			ss=a;
			tt=b;
			if (Better(ss,tt,'&')) swap(ss,tt),swap(top,topb);
			ss[++top]='&';
			for (int j=1;j<=topb;j++)
				ss[++top]=tt[j];
			//printf("%s\n",ss+1);
			update(x&q[i].first,0,ss);
		}
	}
	for (int i=0;i<=255;i++)
		if (better(ans[i][0],ans[i][1]))
			memcpy(ans[i][0],ans[i][1],sizeof(ans[i][0]));
	int n;
	scanf("%d",&n);
	while (n--){
		char s[10];
		scanf("%s",s+1);
		int tmp=0;
		for (int i=1;i<=8;i++)
			tmp=tmp*2+s[i]-'0';
		printf("%s\n",ans[tmp][0]+1);
	}
}
/*
0:x&!x
1:x&y&z
2:x&y&!z
3:x&y
4:x&!y&z
5:
x:00001111
y:00110011
z:01010101
*/