{$APPTYPE CONSOLE}
Uses
    SysUtils;

var
s:string;
n:integer;
begin
reset(input,'input.txt');
rewrite(output,'output.txt');
readln(s);
read(n);
if ((s='front') and (n=1)) or ((s='back') and (n=2)) then writeln('L')
                                                     else writeln('R');
end.