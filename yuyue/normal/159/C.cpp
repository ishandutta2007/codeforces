#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=200200;
int k,n;
char s[M],t[M];
int num[2020][100];
int main(){
	k=read();
	scanf("%s",s+1); n=strlen(s+1);
	F(i,1,n){
		F(j,1,k)
			num[j][s[i]-'a']++;
	}
	F(i,1,k){
		F(j,1,n){
			t[(i-1)*n+j]=s[j];
		}
	}
	int m=read();
	while (m--){
		char y;
		int x=read(); cin>>y;
		int o=y-'a';
		F(i,1,k){
			if (x<=num[i][o]){
				num[i][o]--;
				F(j,1,n){
					int id=(i-1)*n+j;
					if (t[id]==y){
						x--;
						if (!x){
							t[id]=0;
							break;
						}
					}
				}
				break;
			}
			else{
				x-=num[i][o];
			}
		}
	}
	F(i,1,n*k){
		if (t[i]) cout<<t[i];
	}
 	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/