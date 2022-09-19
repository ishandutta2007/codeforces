# include <cstdio>
# include <vector>
# include <cstring>
const int MN=4*100*1000+47;
const int A=26;
char all[MN];
int pre[MN][A];//first occurence strictly before [i]
int kmp[MN];
const int NONE=-1;
int main()
{
	int psize, tsize;
	scanf("%d%d", &tsize, &psize);
	scanf("%s%s", all+psize+1, all);
	all[psize]='$';
	for (int l=0; l<A; ++l)
		pre[0][l]=NONE;
	for (int i=1; i<=psize+tsize+1; ++i)
		for (int l=0; l<A; ++l)
			if (all[i-1]==l+'a')
				pre[i][l]=i-1;
			else
				pre[i][l]=pre[i-1][l];
	kmp[0]=0;
	for (int i=1; i<psize+tsize+1; ++i)
	{
// 		printf("%d\n", i);
		if (all[i]=='$')
		{
			kmp[i]=0;
			continue;
		}
		int can=kmp[i-1];
		while (true)
		{
// 			printf("iter c=%d\n", can);
			int last=pre[i][all[i]-'a'];
			int last2=pre[can][all[can]-'a'];
			int dist=i-last;
			int dist2=can-last2;
// 			printf("last=%d\n", last);
			if (((dist>can && dist2>can) || dist==dist2) && all[can]!='$')
			{
				kmp[i]=can+1;
				break;
			}
			can=kmp[can-1];
		}
	}
// 	printf("%s\n", all);
// 	for (int i=0; i<psize+tsize+1; ++i)
// 		printf("%d.%d\n", i, kmp[i]);
	std::vector <int> res;
	for (int i=2*psize+1; i<=tsize+psize+1; ++i)
		if (kmp[i-1]==psize)
		{
// 			printf("try %d\n", i);
			int p[A];
			for (int l=0; l<A; ++l)
				p[l]=NONE;
			for (int l=0; l<A; ++l)
				if (pre[i][l]!=NONE)
				{
					int dist=i-pre[i][l];
// 					printf("letter=%c dist=%d\n", l+'a', dist);
					if (dist<=psize)
						p[l]=all[psize-dist]-'a';
				}
			bool OK=true;
			for (int l=0; l<A; ++l)
				if (p[l]!=NONE && p[p[l]]!=NONE && p[p[l]]!=l)
					OK=false;
			if (OK)
				res.push_back(i-psize*2);
		}
	printf("%lu\n", res.size());
	for (int i=0; i<res.size(); ++i)
		printf("%d ", res[i]);
	printf("\n");
}