
import random
import time
from pwn import *

def get_random(length, seed_val):
    alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    random.seed(seed_val)
    return ''.join(random.choice(alphabet) for _ in range(length))

approx_time_ms = int(time.time() * 1000)

possible_tokens = []
for seed in range(approx_time_ms - 25, approx_time_ms + 25):
    token = get_random(20, seed)
    possible_tokens.append(token)

print(len(possible_tokens))
proc = remote('verbal-sleep.picoctf.net', 58139)

for i in range(50):
	proc.sendline(possible_tokens[i])
	print(proc.recv())
