import z3

def recover_string_with_z3():
    s = z3.Solver()

    token = "1qazxsw23edcvfr45tgbnhy67ujm,ki8"
    cipher =  b"\x4d\x6c\x22\x26\x21\x74\x24\x25\x78\x61\x3a\x66\x2a\x34\x6e\x67\x76\x64\x29\x3f"
    cipher += b"\x68\x7f\x71\x58\x60\x3a\x29\x3b\x4f\x64\x7e\x3e"
    cipher += b"\x71\x70\x75\x69\x22\x22\x36\x36\x73\x38\x58\x41\x2d\x25\x60\x20"
    plainText = "Now everywhere is war! War. Rumors of war"

    x_chars = [z3.BitVec(f'x_{i}', 8) for i in range(32)]
    key = []
    for i in range(32):
        key.append(x_chars[(i+16)%32] ^ ord(token[(i+8)%32]))

    for i, c in enumerate(plainText):
        s.add(key[i%32] ^ cipher[i] == ord(c))


    if s.check() == z3.sat:
        model = s.model()
        sol = ""
        for b in x_chars:
            temp = model[b].as_long()
            sol += chr(temp)
        print(sol)
    else:
        return None

if __name__ == "__main__":
    recover_string_with_z3()
