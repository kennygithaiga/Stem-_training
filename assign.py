def print_nums(n):
    for num in range (n) :
        if num % 3 == 0 and num % 5 !=0:
            print("foo")
        if num % 5 == 0 and num % 3 !=0:
            print("bar")
        if num % 3==0 and num % 5==0:
            print("foobar")
        if num % 3 !=0 and num % 5!=0:
            print(num)    

print_nums(26)


# for each number in the range 0 to b(not inclusive),if the number is greater than a,print'greater than a',else print 'less than a'

def greater_than(a,b):
    for num in range(b) :
        if num >a:
            print("greater than",a)
        elif num ==a:
            print("equal to",a)
        else:
            print("less than",a)    

greater_than(6,10)

