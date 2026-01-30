def addtwo(num):
    return num + 2

for i in range(0, 15, 2):
    result = addtwo(i)
    print(f"addtwo({i}) = {result}")

print("")

numarray = [1, 5, 98, 43, 53]
print(f"First element of the array = {numarray[0]}")
print("All of the subsequent array elements:")

arrayindex = 1
while arrayindex < len(numarray):
    print(numarray[arrayindex])
    arrayindex += 1

print("")

def sumvars(num1, num2):
    return num1 + num2

print(f"1 + 2 = {sumvars(1, 2)}")
print(f"56 + 4 = {sumvars(56, 4)}")

