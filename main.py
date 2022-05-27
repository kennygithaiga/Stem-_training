#opp
#defining a class and its attributes

class dog:
    def __init__(self,no_of_eyes,colour):
        self.no_of_eyes=no_of_eyes
        self.colour=colour
    
    def barking(self):
        print("woof woof!")

    def eating(self):
        print('hurriedly')

    def walking(self):
        print('slowly')


german_shepherd = dog(no_of_eyes=2,colour='brown')
dodger = dog(no_of_eyes=1,colour='white')
dobberman=dog(2,'brown')

print(german_shepherd.colour)
print(dodger.no_of_eyes)
print(dobberman.colour,dobberman.no_of_eyes)

dobberman.colour = 'darkbrown'
print(dobberman.colour)
print(dodger)

german_shepherd.no_of_eyes = 2
print(german_shepherd.no_of_eyes)
dobberman.barking()
dodger.eating()
german_shepherd.walking()
