my_list=[1,3,4,6,7,8,9,]
for elem in my_list:
    print(elem)

other_list=[]
for elem in my_list:
    if elem % 2==0:
        other_list.append(elem)
print(other_list)

my_list=[1,3,4,6,7,8,9]
other_list=[elem for elem in my_list]
print(other_list)

my_list=[1,3,4,6,7,8,9]
other_list=[elem for elem in my_list if elem % 2==0]
print(other_list)

def add (a,b):
    return a+b
result=add(4,6)
print(result)

result_2=add(8,6)
print(result_2)