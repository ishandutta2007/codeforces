#define _GLIBCXX_IOSTREAM
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int K=16;
int n,ptr,m;
ull pw[100];
char s[110][110];
struct Data{
	set<ull>st[20];
	ull pre[20],suf[20],len;
	char A[50],B[50];
	Data(){
		for(int i=0;i<20;++i)st[i].clear();
		memset(pre,0,sizeof(pre));
		memset(suf,0,sizeof(suf));
	}
	void init(int y,int len){
		this->len=len;
		for(int i=1;i<=len;i++){
			ull h=0,x=1;
			for(int j=i;j<=len&&j-i+1<=K;j++,x*=19260817)
				h=h+s[y][j]*x,st[j-i+1].insert(h);
		}
		ull x=1;
		for(int i=1;i<=K&&i<=len;i++,x*=19260817)
			pre[i]=pre[i-1]+s[y][i]*x;
		for(int i=1;i<=K&&i<=len;++i)
			suf[i]=suf[i-1]*19260817+s[y][len-i+1];
		for(int i=1;i<=K&&i<=len;++i)A[i]=s[y][i];
		for(int i=1;i<=K&&i<=len;++i)B[i]=s[y][len-i+1];
	}
}d[300];
char ls[400];
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",s[i]+1);
		d[++ptr].init(i,strlen(s[i]+1));
	}
	scanf("%d",&m);
	pw[0]=1;
	for(int i=1;i<=60;++i)pw[i]=pw[i-1]*19260817;
	for(int i=1,l,r;i<=m;++i){
		scanf("%d%d",&l,&r),ptr++;int lsp=0;
		for(int j=1;j<=K;++j)for(auto s:d[l].st[j])d[ptr].st[j].insert(s);
		for(int j=1;j<=K;++j)for(auto s:d[r].st[j])d[ptr].st[j].insert(s);
//		for(int j=1;j<=K;++j)printf("[%d]",d[l].B[j]);
//		printf("[%s,%s]",d[l].B+1,d[r].A+1);
//		printf("[%d,%d,%d]",d[ptr].st[2].size(),d[l].st[2].size(),d[r].st[2].size());
		for(int j=1;j<=K&&j<=d[l].len;++j)
			for(int k=1;k+j<=K&&k<=d[r].len;++k)
				d[ptr].st[j+k].insert(d[l].suf[j]+d[r].pre[k]*pw[j]);
//		printf("{%d}",d[ptr].st[2].size());
		d[ptr].len=d[l].len+d[r].len;
		for(int i=1;i<=d[l].len&&i<=K;++i)ls[++lsp]=d[l].A[i];
		for(int i=1;i<=d[r].len&&i<=K;++i)ls[++lsp]=d[r].A[i];
		for(int i=1;i<=K&&i<=lsp;++i)d[ptr].A[i]=ls[i];
		lsp=0;
		for(int i=1;i<=d[r].len&&i<=K;++i)ls[++lsp]=d[r].B[i];
		for(int i=1;i<=d[l].len&&i<=K;++i)ls[++lsp]=d[l].B[i];
		for(int i=1;i<=K&&i<=lsp;++i)d[ptr].B[i]=ls[i];
		ull x=1;
//		printf("[%s,%s]\n",d[ptr].A+1,d[ptr].B+1);
		for(int i=1;i<=K&&i<=d[ptr].len;++i,x*=19260817)d[ptr].pre[i]=d[ptr].pre[i-1]+d[ptr].A[i]*x;
		for(int i=1;i<=K&&i<=d[ptr].len;++i)d[ptr].suf[i]=d[ptr].suf[i-1]*19260817+d[ptr].B[i];
		for(int i=1;i<=K;++i)if(d[ptr].st[i].size()<(1<<i)){printf("%d\n",i-1);break;}
	}
}