import tkinter as tk


window = tk.Tk()
window.title('my window')
window.geometry('200x200')



l = tk.Label(window, bg='green', width=20, text='empty')
l.pack()


def print_selection(v):
    l.config(text='you have selected  ' + v)



s = tk.Scale(window, label='try me', from_=5, to=11, orient=tk.HORIZONTAL,
             length=2000, showvalue=1, tickinterval=3,resolution=0.001,
             command=print_selection)

s.pack()
    



window.mainloop()
