#try,expect in python to catch errors
try:
    div=10/0
    value=int(input("enter a number: "))
    print(value)
except ValueError:
    print("invalid number entered")
except ZeroDivisionError:
    print("Divided by zero")
