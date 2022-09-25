def solve(i):
  x = int(input())
  a = abs(x)**0.5
  b = x**3 * 5
  res = a + b
  if i > 1:
    solve(i - 1)
  if res < 400:
    print("f({}) = {:.2f}".format(x, res))
  else:
    print("f({}) = MAGNA NIMIS!".format(x))

solve(11)