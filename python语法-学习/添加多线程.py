import threading

def thread_job(): #定义模块
    print('this is and added Thread, number is %s'%threading.current_thread())

def main():
    added_thread = threading.Thread(target=thread_job) #添加线程，目标是thread_job模块
    print(threading.active_count())  #计算多少激活的线程
    print(threading.enumerate())  #查看运行线程的名称
    print(threading.current_thread())  #查看当前运行的线程

    added_thread.start() #启动线程thread_job

if __name__=='__main__':
    main()
 

