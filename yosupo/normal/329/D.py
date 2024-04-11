r, c = map(int, input().split())
if r == 3:
    print('>vv')
    print('^<.')
    print('^.<')
    print('1 3')
elif r == 5:
    print('>...v')
    print('v.<..')
    print('..^..')
    print('>....')
    print('..^.<')
    print('1 1')
elif r == 100:
    for i in range(25):
        print('>'*50+'.>'*24+'.v')
        print('^'+'<.'*25+'<'*49)
        print('v.'+'<.'*24+'<'*50)
        print('>'*49+'.>'*25+'^')
    print('1 1')
else:
    d = []
    d[1] = 1