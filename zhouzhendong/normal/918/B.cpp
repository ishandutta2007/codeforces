#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
const int N=1005;
int n,q,len[N];
char name[N][20],ip[N][20];
bool dy(char ip1[],char ip2[],int len){
	for (int i=0;i<len;i++)
		if (ip1[i]!=ip2[i])
			return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
		scanf("%s%s",name[i],ip[i]),len[i]=strlen(ip[i]);
	while (q--){
		char na[20],IP[20];
		scanf("%s%s",na,IP);
		int L=strlen(IP)-1;
		IP[L]='\0';
		for (int i=1;i<=n;i++)
			if (len[i]==L&&dy(IP,ip[i],L)){
				printf("%s %s; #%s\n",na,IP,name[i]);
				break;
			}
	}
	return 0;
}