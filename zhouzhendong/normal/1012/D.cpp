#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1000005;
int c[N],v[N],Next[N],cnt_node=0;
int L=0,R=1,len[2],head[2],n=0,ans[N][2];
char s1[N],s2[N];
int new_node(int color,int tot,int nxt){
	cnt_node++,c[cnt_node]=color,v[cnt_node]=tot,Next[cnt_node]=nxt;
	return cnt_node;
}
void build(int f,char s[]){
	int n=strlen(s+1),p=new_node(s[1]-'a',1,0);
	head[f]=p,len[f]=1;
	for (int i=2;i<=n;i++)
		if (s[i]==s[i-1])
			v[p]++;
		else
			p=Next[p]=new_node(s[i]-'a',1,0),len[f]++;
}
int func0(int x,int a,int b){
	return abs((a-2*x-1)-(b+2*x));
}
int func1(int x,int a,int b){
	return abs((a-2*x)-(b+2*x-2));
}
int func2(int x,int a,int b){
	return abs((a-2*x-1)-(b+2*x-1));
}
int Get_len(int f){
	int cnt=0;
	for (int p=head[f];p;p=Next[p])
		cnt++;
	return cnt;
}
void New_ans(int Lv,int Rv){
	n++;
	ans[n][L]=Lv,ans[n][R]=Rv;
}
int main(){
	scanf("%s%s",s1+1,s2+1);
	build(0,s1),build(1,s2);
	while (max(len[L],len[R])>1){
		if (len[L]<len[R])
			swap(L,R);
		if (c[head[L]]==c[head[R]]&&len[R]>1&&len[L]>2){
			int a=len[L],b=len[R],x1=(a-b+2)/4,x2=x1+1;
			int x=max(1,min(func1(x1,a,b)<=func1(x2,a,b)?x1:x2,a/2));
			int tot=v[head[L]],p=head[L];
			for (int i=1;i<=x*2-1;i++)
				p=Next[p],tot+=v[p];
			New_ans(tot,v[head[R]]);
			int hL=head[L],hR=head[R];
			v[head[L]=Next[p]]+=v[hR];
			head[R]=hL;
			Next[p]=Next[Next[hR]];
			v[p]+=v[Next[hR]];
			len[L]-=x*2,len[R]+=x*2-2;
			continue;
		}
		else if (c[head[L]]==c[head[R]]){
			int a=len[L],b=len[R],x1=(a-b-1)/4,x2=x1+1;
			int x=min(func0(x1,a,b)<=func0(x2,a,b)?x1:x2,(a-1)/2);
			int tot=v[head[L]],p=head[L];
			for (int i=1;i<=x*2;i++)
				p=Next[p],tot+=v[p];
			New_ans(tot,0);
			swap(head[R],head[L]);
			swap(Next[p],head[L]);
			v[p]+=v[Next[p]];
			Next[p]=Next[Next[p]];
			len[L]=(len[L]<3)?(Get_len(L)):(len[L]-(x*2+1));
			len[R]=(len[R]<3)?(Get_len(R)):(len[R]+(x*2));
		}
		else {
			int a=len[L],b=len[R],x1=(a-b-1)/4,x2=x1+1;
			int x=min(func2(x1,a,b)<=func2(x2,a,b)?x1:x2,(a-1)/2);
			int tot=v[head[L]],p=head[L];
			for (int i=1;i<=x*2;i++)
				p=Next[p],tot+=v[p];
			New_ans(tot,v[head[R]]);
			v[head[R]]+=v[Next[p]];
			v[p]+=v[Next[head[R]]];
			swap(Next[head[R]],Next[p]);
			Next[head[R]]=Next[Next[head[R]]];
			Next[p]=Next[Next[p]];
			swap(head[L],head[R]);
			len[L]=(len[L]<3)?(Get_len(L)):(len[L]-(x*2+1));
			len[R]=(len[R]<3)?(Get_len(R)):(len[R]+(x*2-1));
		}
	}
	printf("%d\n",n);
	for (int i=1;i<=n;i++)
		printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}