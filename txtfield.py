from cProfile import label
from tkinter import Tk


from tkinter import *

root =Tk()
#create a task function
def myclick():
    my_label=label(root,text = "Hey!,you clicked me!")
    my_label.pack()

#create a frame
my_button = Button(root,text="click me",command=myclick)
# pack it - -show  in the window
my_button.pack()
root.mainloop()
