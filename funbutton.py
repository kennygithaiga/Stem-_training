from tkinter import *
root = Tk ()
def myclick():
    my_label = Label (root,text="Hey,you clicked")
    my_label.pack()
myB=Button (root,text="click me!",command=myclick)
myB.pack()
root . mainloop ()