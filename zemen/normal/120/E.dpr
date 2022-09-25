{$APPTYPE CONSOLE}
Uses
    SysUtils;

var
t,n,i:integer;
begin
reset(input,'input.txt');
rewrite(output,'output.txt');
read(t);
for i:=1 to t do
    begin
    read(n);
    if n mod 2 = 0 then writeln(1)
                   else writeln(0);
    end;
end.