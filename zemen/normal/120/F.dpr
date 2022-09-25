{$APPTYPE CONSOLE}
Uses
    SysUtils;

var
max,x,y,ans,t,n,i,j,k:integer;
a:array[1..100,1..100] of integer;
ch:array[1..100] of boolean;
d:array[1..100] of integer;

procedure bfs(s:integer);
var
i:integer;
begin
for i:=1 to n do
    begin
    if (a[s,i]=1) and (ch[i]=false) then
       begin
       d[i]:=d[s]+1;
       ch[i]:=true;
       bfs(i);
       end;
    end;
end;


begin
reset(input,'input.txt');
rewrite(output,'output.txt');
readln(t);
for k:=1 to t do
    begin
    read(n);
    for i:=1 to 100 do     //!
        for j:=1 to 100 do    //!
            a[i,j]:=0;
    for j:=1 to n-1 do
        begin
        read(x,y);
        a[x,y]:=1;
        a[y,x]:=1;
        end;
    max:=-1;
    for i:=1 to n do
        begin
        for j:=1 to 100 do //!
        ch[j]:=false;
        for j:=1 to 100 do   //!
        d[j]:=0;
        ch[i]:=true;
        bfs(i);
        for j:=1 to n do
            if d[j]>max then max:=d[j];
        end;
    ans:=ans+max;
    end;
write(ans);
end.