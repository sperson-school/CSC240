def factorial(num):
    answer = 1
    while(num > 0):
        answer = answer * num
        num -= 1
    return answer

integer = int(input("Enter an integer that isn't negative: "))
print(f"{integer}! equals {factorial(integer)}")
