#include<iostream>
#include<string>
using namespace std;

int main(){
	scanf("{");

	int cnt[30]={0};
	while(1){
		char c;
		scanf("%c",&c);
		if(c=='}')break;
		cnt[c-'a']++;
		scanf("%c",&c);
		if(c=='}')break;
		scanf(" ");
	}

	int ret=0;
	for(int i=0;i<26;i++){
		if(cnt[i])ret++;
	}

	printf("%d\n",ret);
}