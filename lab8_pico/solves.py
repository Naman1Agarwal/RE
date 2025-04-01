def addr(a):
     a = a - 0x000000000000133d + 0x00000000000012a7
     return a

print(hex(addr(0x57f8d165433d)))
