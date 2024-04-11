#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
int ans[10][10] = {{0,0,0,0,0,0,0,0,0,0},
{-1,0,0,0,0,0,0,0,0,0},
{-1,0,0,0,0,0,0,0,0,0},
{-1,0,0,1,1,2,2,3,3,4},
{-1,0,0,1,2,2,3,4,4,5},
{-1,0,0,2,2,4,4,5,6,7},
{-1,0,0,2,3,4,5,6,7,8},
{-1,0,0,3,4,5,6,8,9,10},
{-1,0,0,3,4,6,7,9,10,12},
{-1,0,0,4,5,7,8,10,12,13}}, N, M;
string Sol[10][10][10]= {
    {{},{},{},{},{},{},{},{},{},{}},
    {{""},{"."},{".."},{"..."},{"...."},{"....."},{"......"},{"......."},{"........"},{"........."}},
    {{"",""},{".","."},{"..",".."},{"...","..."},{"....","...."},{".....","....."},{"......","......"},
    {".......","......."},{"........","........"},{".........","........."}},{{"","",""},
    {".",".","."},{"..","..",".."},{"A..","AAA","A.."},{"A...","AAA.","A..."},{"A.BBB","AAAB.","A..B."},
    {"A.BBB.","AAAB..","A..B.."},{"A.BBBC.","AAAB.C.","A..BCCC"},{"A.BBBC..","AAAB.C..","A..BCCC."},
    {"A.BBBCDDD","AAAB.C.D.","A..BCCCD."}},
    {{"","","",""},{".",".",".","."},{"..","..","..",".."},{"A..","AAA","A..","..."},{"A...","AAAB","ABBB","...B"},
    {"A.BBB","AAAB.","A..B.","....."},{"A.BBB.","AAABC.","A..BC.","...CCC"},
    {"A..BBB.","AAACBD.","ACCCBD.","...CDDD"},{"A.BBBC..","AAABDCCC","A..BDC..","...DDD.."},
    {"A.BBBC...","AAABDCCCE","A..BDCEEE","...DDD..E"}},{{"","","","",""},
    {".",".",".",".","."},{"..","..","..","..",".."},{"A..","AAA","AB.",".B.","BBB"},
    {"A...","AAAB","ABBB","...B","...."},
    {"A.BBB","AAAB.","AC.BD",".CDDD","CCC.D"},
    {"A.BBB.","AAABC.","AD.BC.",".D.CCC","DDD..."},
    {"A.BBB.C","AAABCCC","AD.BE.C",".D..E..","DDDEEE."},
    {"A.BBBC..","AAABDCCC","AE.BDCF.",".E.DDDF.","EEE..FFF"},
    {"A.BBB.CCC","AAABDDDC.","AE.BFDGC.",".E..FDGGG","EEEFFFG.."}},
    {{"","","","","",""},{".",".",".",".",".","."},{"..","..","..","..","..",".."},
    {"A..","AAA","AB.",".B.","BBB","..."},
    {"A...","AAAB","ABBB","C..B","CCC.","C..."},
    {"A.BBB","AAAB.","AC.BD",".CDDD","CCC.D","....."},
    {"A.BBB.","AAAB..","A.CB..",".DCCCE",".DCEEE","DDD..E"},
    {"A.BBBC.","AAAB.C.","AD.BCCC",".DEEEF.","DDDE.F.","...EFFF"},
    {"A.BBBC..","AAAB.CCC","AD.BEC..",".D.FEEEG","DDDFEGGG","..FFF..G"},
    {"A.BBBCDDD","AAAB.C.D.","AE.BCCCDF",".EGGGHFFF","EEEG.H..F","...GHHH.."}},
    {{"","","","","","",""},{".",".",".",".",".",".","."},
    {"..","..","..","..","..","..",".."},
    {"A..","AAA","A.B","BBB","C.B","CCC","C.."},
    {"A...","AAAB","ABBB","C..B","CCCD","CDDD","...D"},
    {"A.BBB","AAAB.","AC.BD",".CDDD","CCCED","...E.","..EEE"},
    {"A.BBB.","AAABC.","A.DBC.","..DCCC","EDDDF.","EEE.F.","E..FFF"},
    {"A.BBB.C","AAABCCC","AD.BE.C",".DDDEEE","FD.GE.H","FFFGHHH","F.GGG.H"},
    {"A.BBB..C","AAABDCCC","AE.BDDDC",".EEEDFFF","GEHHHIF.","GGGH.IF.","G..HIII."},
    {"A.BBBCDDD","AAAB.C.D.","AE.BCCCDF",".EEEG.FFF","HE.IGGGJF","HHHIG..J.","H.III.JJJ"}},
    {{"","","","","","","",""},
    {".",".",".",".",".",".",".","."},
    {"..","..","..","..","..","..","..",".."},
    {"A..","AAA","AB.",".B.","BBB","C..","CCC","C.."},
    {"A...","AAAB","ABBB","C..B","CCCD","CDDD","...D","...."},
    {"A.BBB","AAAB.","AC.BD",".CDDD","CCCED","FFFE.",".FEEE",".F..."},
    {"A.BBB.","AAABC.","AD.BC.",".D.CCC","DDDE..","FEEEG.","FFFEG.","F..GGG"},
    {"A..BCCC","AAAB.C.","ADBBBCE",".DDDEEE","FD.GGGE","FFFHGI.","FHHHGI.","...HIII"},
    {"A.BBBC..","AAAB.C..","AD.BCCCE",".DFFFEEE","DDDFGGGE","HHHFIGJ.",".HIIIGJ.",".H..IJJJ"},
    {"A.BBBC...","AAABDCCCE","A.FBDCEEE","FFFDDDG.E","H.FIIIGGG","HHHJIKG.L","HJJJIKLLL","...JKKK.L"}},
    {{"","","","","","","","",""},
    {".",".",".",".",".",".",".",".","."},
    {"..","..","..","..","..","..","..","..",".."},
    {"A..","AAA","A.B","BBB","C.B","CCC","CD.",".D.","DDD"},
    {"A...","AAAB","ABBB","C..B","CCCD","CDDD","E..D","EEE.","E..."},
    {"A.BBB","AAAB.","AC.BD",".CDDD","CCCED","FEEE.","FFFEG","F.GGG","....G"},
    {"A.BBB.","AAABC.","AD.BC.",".D.CCC","DDDE..","FFFEEE",".FGE.H",".FGHHH",".GGG.H"},
    {"A.BBBC.","AAAB.C.","A.DBCCC","DDDE...","F.DEEEG","FFFEGGG","FHIIIJG",".H.I.J.","HHHIJJJ"},
    {"A.BBBCCC","AAAB.DC.","AE.B.DC.",".EEEDDDF","GEHHHFFF","GGGHIIIF","GJ.HKIL.",".JKKKIL.","JJJ.KLLL"},
    {"A.BBBCDDD","AAAB.C.D.","AE.BCCCDF",".EGGGHFFF","EEEGIHHHF","JJJGIHKKK",".JLIIIMK.",".JL...MK.",".LLL.MMM."}}};
int main(){
    scanf("%d %d", &N, &M);
    printf("%d\n", ans[N][M]);
    for(int i = 0; i < N; i++)
        cout << Sol[N][M][i] << endl;
    return 0;
}