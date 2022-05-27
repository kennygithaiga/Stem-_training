# dictionaries in python
my_dict= {
    "Book":"Dynamics",
    "publisher":"longhorn",
    "year":2001,
    "authors":["John" ,"Mike" ,"ike"]
}

#accessing item
x=my_dict ["year"]
print(x)

#accessing using get()
y=my_dict["year"]
print(y)

#all keys
x=my_dict.keys()
print(x)

#all values
x=my_dict.values()
print()

#printing all items in a dictionary
x=my_dict.items()
print()

#checking if key exists
if "publisher"in my_dict:
    print("publisher is one of the keys")
print(len(my_dict))

#dictionaries can hold different data types
