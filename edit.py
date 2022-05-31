#opening and editing fles in python(.txt.py)
role_file=open("roles.txt","r")
print(role_file.readline())
#close file
role_file.close()

#append
role_file=open("roles.txt","a")
role_file.write("i love python")
role_file.close()

print("\n")