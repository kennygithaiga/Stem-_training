type=input("which data type do you choose")
if type =="float":
    x=float(input("assign a number for x"))
    y=float(input("assign a number for y"))

if type =="int":
    x=int(input("assign a number for x"))
    y=int(input("assign a number for y"))

operation= input("enter operation")
if operation== 'addition':
    print(x+y)
if operation== 'subtraction':
    print(x-y)
if operation== 'multiplication':
    print(x*y)
if operation== 'division':
    print(x/y)

solution=(x+y) or (x-y) or (x*y) or (x/y)
complex_solution=complex(solution)

print("the solution of this expression in its complex form is",complex_solution)

