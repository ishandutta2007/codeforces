{$APPTYPE CONSOLE}
Uses
    SysUtils;

var
n,k,i,ans,j:integer;
a,ch:array[1..1000] of integer;
begin
reset(input,'input.txt');
rewrite(output,'output.txt');
readln(n,k);
for i:=1 to n do
    read(a[i]);
for i:=1 to n do
    ch[i]:=0;
ans:=0;
for i:=1 to n do
    begin
    for j:=1 to 3 do
        begin
        if a[i]>=k then a[i]:=a[i]-k;
        end;
    ans:=ans+a[i];
    end;
writeln(ans);

end.