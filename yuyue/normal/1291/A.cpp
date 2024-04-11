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
const int M=5e5+10;
char ch[M];
int a[M];
int main(){
	int T=read();
	while (T--){
		int n;
		scanf("%d%s",&n,ch+1);
		F(i,1,n) a[i]=a[i-1]+ch[i]-'0';
		bool flag=0;
		DF(i,n,1){
			if ((ch[i]-'0')&1){
				if (a[i]%2==0){
					F(j,1,i) cout<<ch[j]; cout<<"\n";
					flag=1;
					break;
				}
				F(j,1,i-1){
					if ((ch[j]-'0')&1){
						if (j==1 && ch[2]=='0') continue;
//						if (i!=2){
							F(k,1,i){
								if (k!=j){
									cout<<ch[k];
								}
							}
							cout<<"\n";
							flag=1;
							break;
//						}
					}
				}
			}
			if (flag) break;
		}
		if (!flag){
			cout<<"-1\n";
		}
	}
	return 0;
}