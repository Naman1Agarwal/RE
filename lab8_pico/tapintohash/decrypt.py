import sys
import hashlib

def xor_bytes(a, b):
    return bytes(x ^ y for x, y in zip(a, b))


def decrypt(ciphertext, key):
    block_size = 16
    key_hash = hashlib.sha256(key).digest()
    print(len(key_hash), key_hash)
    decrypted = b''

    for i in range(0, len(ciphertext), block_size):
        block = ciphertext[i:i + block_size]
        decrypted_block = xor_bytes(block, key_hash)
        decrypted += decrypted_block
        
    original_plaintext = decrypted.decode('utf-8')

    return original_plaintext


key = b'B\xfdL\x92\xf1C\x8fP\xb4\xd4dt\x8b\x18\xcfR\xfd`\xd1-\xa5\xde\xcd\x89\xee\xdb\xfb\r\x83&\x07\x82'
ciphertext = b'|`M\xb2&\xa7\xea\xd5m\xb5\x83g\x11\x90\x08\xdbx7L\xb2v\xa0\xb8\xd4;\xbe\xdd`E\xc4\x01\xdb/:\x18\xe5s\xa6\xee\x8e;\xbd\xd8i\x19\x94X\xda|2\x19\xe2v\xf4\xed\x81m\xbb\xdd1\x13\x98\x08\xd3d3K\xe4t\xf1\xec\x83;\xbe\x83c\x18\x93]\xda|2\x1e\xe7&\xa9\xbd\xd0a\xee\x8a4\x13\xc3Z\xd3x7J\xb5u\xa1\xe9\x81o\xbf\x8ec\x12\x90\x0c\xd3y3N\xe3 \xa6\xbe\x85>\xe9\x82c\x14\x92\x0c\x81\x7f.K\xb6t\xa3\xee\x80o\xb4\x8dcE\x94\x08\x82(3K\xe2r\xa5\xe9\xd0o\xef\x8f1\x10\xc5\x0c\xd2\x7f`\x0b\xefs\xff\xcc\xe2\x1e\xf7\xd9<O\xc2R\xbczP)\xeeF\xf9\xdd\xd4\x0c\xbd\xca3x\xfea\xb6#NK\xf4$\xa9\xec\xfe\x07\xfd\xf8*M\xebc\x99\x0bH$\xbe$\xa2\xec\xd0`\xbf\xda-\x10\x91\\\xd3-eJ\xb6#\xa3\xea\xd2m\xbc\xddfC\xc5\t\x82+fO\xe2(\xa9\xee\x85k\xe8\x822\r\x91\t\x86y1I\xe7!\xf5\xb6\x8e>\xbd\xdae\x14\x98\t\xd6(1M\xbfv\xa9\xe9\x85=\xe8\xdadB\x92\x00\xdb*fB\xb2!\xa5\xeb\x83<\xea\x8d5A\x96\x0c\xd2\x7f2M\xb2(\xa6\xea\xd5l\xea\xdab\x16\x8c\t\xd3z`C\xe3(\xa0\xb7\x81j\xee\xd9hE\x95\x0b\x82*aO\xb2"\xa7\xeb\x86:\xbe\xd9gC\x97\x01\xd4yf\x19\xe0\'\xa3\xb9\x80>\xbb\xdahE\x93\x0f\x82,`\x1d\xb5#\xa7\xb6\x82k\xbc\x8ci\x14\x97;\xe1'
token = 'EncodedGenesisBlock'

decrypted_text = decrypt(ciphertext, key)
print(decrypted_text)

