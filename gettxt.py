from tkinter import *

from flask import stream_with_context

root =Tk()
# creating a text field
e1=Entry(root,width=50,bg="orange",fg="green")
e1.pack()
e1.insert(0,"enter first no")

#second input
e2=Entry(root,width=50,bg="white",fg="red")
e2.pack()
e2.insert(0,"enter second no")


# create a task function
def myclick():
    str_= e.get()
    if"*"in srt_:

    f_no=float(e1.get())
    s_no=float(e2.get())
    sub=f_no-s_no
    add=f_no+s_no
    div=f_no /s_no
    mult=f_no*s_no

    Ans="Add :" + str(add) +"\nsub :"+str(sub) +"\nDiv :" +str(div) +"\nMult:" +str(mult)
    my_label=Label(root,text=Ans)
    my_label.pack ()
#create a frame
my_button = Button(root,text="calculate",command=myclick,fg="blue")

# pack it - -show  in the window
my_button.pack()
root.mainloop()
