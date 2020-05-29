import threading
import time

def thread_job():
    print('T1 start\n')
    for i in range(10):
        time.sleep(0.1) #线程每次暂停0.1秒
    print('T1 finish\n') 

def T2_job():
    print('T2 start\n')
    print('T2 finish\n')
    

def main():
    thread1 = threading.Thread(target=thread_job, name='T1') #将线程命名为T1
    thread2 = threading.Thread(target= T2_job, name='T2')
    
   # thread1.start()#启动线程1
    thread2.start()  #启动线程2

    
    thread2.join() #thread2线程运行完成之后才能运行其他的线程
   
    print('all done\n') #主线程执行完毕
    thread1.start() #执行线程thread1
     
if __name__=='__main__':
    main()
