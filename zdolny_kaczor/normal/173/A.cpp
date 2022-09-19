# include <cstdio>
# include <cstring>
bool lost(char a, char b)
{
    return (a=='R' && b=='P') || (a=='P' && b=='S') || (a=='S' && b=='R');
}
char seq1[1001], seq2[1001];
int main()
{
    int n;
    scanf("%d%s%s", &n, seq1, seq2);
    int l1=strlen(seq1), l2=strlen(seq2);
    int fi=0, se=0;
    for (int i=0; i<l1*l2; ++i)
    {
        fi+=lost(seq1[i%l1], seq2[i%l2])
        *
        ( n/(l1*l2) + (i<n%(l1*l2)?1:0))
        ;
        se+=lost(seq2[i%l2], seq1[i%l1])
        *
        ( n/(l1*l2) + (i<n%(l1*l2)?1:0))
        ;
    }
    printf("%d %d\n", fi, se);
}