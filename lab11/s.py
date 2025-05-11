
from pwn import *
import hashlib


salt = 'GpLaMjEWpVOjnnmkRGiledp6Mvcezxls'
text = 'AAAABBBBCCCCDDDD'
res = ''

i = 0
j = 0
while i < len(text):
    res += text[i:i+4]
    res += salt[j:j+8]
    i += 4
    j += 8

print(res)

hashText1 = hashlib.md5(res[0:12].encode()).digest()
hashText2 = hashlib.md5(res[12:24].encode()).digest()
hashText3 = hashlib.md5(res[24:36].encode()).digest()
hashText4 = hashlib.md5(res[36:].encode()).digest()
print(hashText4)

code = b""
code += hashText1[8:12]
code += hashText2[2:6]
code += hashText3[7:11]
code += hashText4[1:5]

print(hashText4)
print(code[-4:])

