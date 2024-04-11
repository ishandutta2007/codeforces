#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=111;
int n,l;
char ch[M],A[M];
bool d[M],v[M];
bool g[M][M];
int tot,t[M];
bool dfs(int x,int ci){
//	cout<<char(x+'a')<<" "<<ci<<"\n";
	v[x]=1;
	A[ci]=x+'a';
	if (ci==tot) return 1;
	for (int i=0;i<26;i++) {
		if (!v[i] && abs(i-x)!=1 && t[i]) {
			if (dfs(i,ci+1)) return 1;
		}
	}
	v[x]=0;
	return 0;
}
void print(){
	for (int i=1;i<=tot;i++){
		for (int j=1;j<=t[A[i]-'a'];j++)
		cout<<A[i];
	}
	cout<<"\n";
}
int main(){
	n=read();
	while (n--){
		scanf("%s",ch+1);
		memset(t,0,sizeof t);
		memset(v,0,sizeof v);
		memset(A,0,sizeof A);
		memset(d,0,sizeof d);
		tot=0;
		l=strlen(ch+1);
		int bia=0;
		for (int i=1;i<=l;i++) t[ch[i]-'a']++;
		for (int i=0;i<26;i++) if (t[i]) tot++;
//		cout<<tot<<"\n";
//		df(1);
//		bool fff=0;
//		for (int i=1;i<=l;i++){
//			if (!d[i]){
//				fff=1;
//				break;
//			}
//		}
//		cout<<fff<<"\n";
//		if (fff) {
//			cout<<"No answer\n";
//			continue;
//		}
		
		bool fl=0;
		for (int i=0;i<26;i++){
			if (!t[i]) continue;
			if (dfs(i,1)){
				print();
				fl=1;
				break;
			}//	system("pause");
			
		}
		if (!fl) cout<<"No answer\n";
	
	}
    return 0;
}