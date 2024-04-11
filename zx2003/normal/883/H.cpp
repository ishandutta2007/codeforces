#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
using namespace std;
typedef pair<int,int> pa;
void getint(LL &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
int n,cnt[1111],S,top,qs,Qs;
char s[600010],stk[1111],ans[600010],q[600010],Q[600010];
int main(){
	cin>>n;
	scanf("%s",s+1);
	FOR(i,1,n) ++cnt[s[i]];
	for (char c='a';c<='z';++c) stk[++top]=c;
	for (char c='A';c<='Z';++c) stk[++top]=c;
	for (char c='0';c<='9';++c) stk[++top]=c;
	FOR(j,1,top)
		S+=cnt[stk[j]]/2;
	FOR(i,1,n)
		if (n%i==0){
			int t=n/i;
			int v=t/2*i;
			if (S<v) continue;
			FOR(j,1,top){
				FOR(k,1,cnt[stk[j]]/2)
					q[++qs]=stk[j];
				if (cnt[stk[j]]&1)
					Q[++Qs]=stk[j];
			}
			cout<<i<<endl;
			FOR(j,1,i){
				FOR(j,1,t/2)
					ans[j]=ans[t-j+1]=q[qs--];
				if (t&1){
					if (Qs) ans[t/2+1]=Q[Qs--];
					else{
						ans[t/2+1]=q[qs--];
						Q[++Qs]=ans[t/2+1];
					}
				}
				FOR(j,1,t) putchar(ans[j]);
				if (j<i) putchar(' ');
				else putchar('\n');
			}
			break;
		}
	return 0;
}