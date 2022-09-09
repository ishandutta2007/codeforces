#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
char s[10005][10];
inline int f(char c){
	if(c=='.')return 0+1;
	if(c>='0'&&c<='9')return 1+c-'0'+1;
	if(c>='a'&&c<='z')return 1+10+c-'a'+1;
	return -1;
}
set<long long> w;
map<long long,int> h,g;
char t[10];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]);
		int l=strlen(s[i]);
		w.clear();
		for(int j=0;j<l;j++){
			long long hsh=0;
			for(int k=j;k<l;k++){
				hsh=hsh*40+f(s[i][k]);
				w.insert(hsh);
			}
		}
		for(set<long long>::iterator it=w.begin();it!=w.end();it++){
			h[*it]++;
			g[*it]=i;
		}
	}
	s[0][0]='-';
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%s",t);
		int l=strlen(t);
		long long hsh=0;
		for(int j=0;j<l;j++)hsh=hsh*40+f(t[j]);
		printf("%d %s\n",h[hsh],s[g[hsh]]);
	}
	return 0;
}