# 멀티 프로세싱(POOL)

from multiprocessing import Pool 

def f(x):
  return x*x

print(__name__)
  
if __name__ == '__main__': 
  p = Pool(4)
  result = p.map(f, range(10)) 
  p.close()
  print(result)