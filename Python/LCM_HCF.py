def lcm(a,b):
    maxnum=max(a,b)
    while True:
        if maxnum%a==0 and maxnum%b==0:
            return maxnum
        maxnum +=1
num1=int(input("Enter first number: "))
num2=int(input("Enter second number: "))
print("The LCM (Iteration Method) of the given numbers is: ",lcm(num1,num2))

def lcm_recursive(a,b,maxnum):
    if maxnum%a==0 and maxnum%b==0:
        return maxnum
    else:
        return lcm_recursive(a,b,maxnum+max(a,b))

num1=int(input("Enter first number: "))
num2=int(input("Enter second number: "))
maxnum=max(num1,num2)
print("The LCM (Recursive method) of the given numbers is: ",lcm_recursive(num1,num2,maxnum))




def hcf(a,b):
    minnum=min(a,b)
    while True:
        if a%minnum==0 and b%minnum==0:
            return minnum
        minnum=minnum-1

num1=int(input("Enter first number: "))
num2=int(input("Enter second number: "))
print("The HCF( iteration method) of the given numbers is: ",hcf(num1,num2))

def hcf_recursive(a,b,minnum):
    if a%minnum==0 and b%minnum==0:
        return minnum
    else:
        return hcf_recursive(a,b,minnum-1)
num1=int(input("Enter first number: "))
num2=int(input("Enter second number: "))
minnum=min(num1,num2)
print("The HCF (recursive method) of the given numbers is: ",hcf_recursive(num1,num2,minnum))