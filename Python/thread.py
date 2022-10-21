from threading import Thread
import time

def work(work_id, start, end, result): 
  total = 0
  for i in range(start, end):
    total += i 
  result.append(total)

if __name__ == "__main__":
  start = time.time()
  result = []
  th1 = Thread(target=work, args=(1, 0, 10000, result))
  th2 = Thread(target=work, args=(2, 10001, 20000, result))

  th1.start()
  th2.start()
  th1.join()  # join () 메소드는 파이썬에게 프로세스가 종료 될 때까지 대기하도록 지시합니다. 
  th2.join()

print(result)
print(time.time()-start)