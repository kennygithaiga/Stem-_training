class Person:
    def __init__ (self,name,age):
        self.name=name
        self.age=age

    def details (self) :
        print(f"my name is {self.name} and my age is {self.age}")


P1=Person("Felix",22)
P1.details()

class Employee(Person):
    def __init__(self,name,age,salary):
        super().__init__(name,age)
        self.salary= salary
P2 = Employee("Felix" ,22,500)
P2.details()
