from fractions import Fraction
x,y,n = map(int,raw_input().split(' '))
ans = Fraction(x,y).limit_denominator(n)
print str(ans.numerator) + '/' + str(ans.denominator)