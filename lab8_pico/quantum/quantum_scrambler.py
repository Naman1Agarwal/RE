import sys

def exit():
  sys.exit(0)

def scramble(L):
  A = L
  i = 2
  while (i < len(A)):
    A[i-2] += A.pop(i-1)
    #print("A-2", A[i-2])
    A[i-1].append(A[:i-2])
    #print("A-1", A[i-1])
    i += 1
    #print("In:", A)
    
  return L

def get_flag():
  flag = open('flag.txt', 'r').read()
  flag = flag.strip()
  hex_flag = []
  for c in flag:
    hex_flag.append([str(hex(ord(c)))])
  print(hex_flag)

  return hex_flag

def main():
  flag = get_flag()
  cypher = scramble(flag)
  for i, item in enumerate(cypher):
  	print(i, item)

if __name__ == '__main__':
  main()
