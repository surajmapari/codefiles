"""In second year computer engineering class, group A student’s play cricket, group B
students play badminton and group C students play football. Write a Python program
using functions to compute following: -
a)List of students who play both cricket and badminton
b)List of students who play either cricket or badminton but not both
c)Number of students who play neither cricket nor badminton
d)Number of students who play cricket and football but not badminton."""


arr1 = ["Aditya", "Indraneil", "Parth", "Suraj"]
arr2 = ["Indraneil", "Suraj", "Sandeep", "Virat"]
arr3 = ["Suraj", "Virat", "Ronaldo", "Aditya"]
print("---------------------------------------------------------------------------------")
print("Group A students who play cricket: ", arr1)
print("Group B students who play batminton: ", arr2)
print("Group C students who play football: ", arr3)
print("---------------------------------------------------------------------------------")

intersecAB = [i for i in arr1 if i in arr2]
intersecBC = [i for i in arr2 if i in arr3]
intersecCA = [i for i in arr3 if i in arr1]
intersecABC = [i for i in arr1 if i in arr2 if i in arr3]
print("Intersection of AB: ", intersecAB)
print("Intersection of BC: ", intersecBC)
print("Intersection of CA: ", intersecCA)
print("Intersection of ABC: ", intersecABC)
print("---------------------------------------------------------------------------------")

rawunionAB = [i for i in arr1 + arr2]
unionAB = rawunionAB
for i in range(len(arr1)):
    if arr1[i] in (arr1 and arr2):
        unionAB.remove(arr1[i])

rawunionBC = [i for i in arr2 + arr3]
unionBC = rawunionBC
for i in range(len(arr2)):
    if arr2[i] in (arr2 and arr3):
        unionBC.remove(arr2[i])

rawunionCA = [i for i in arr3 + arr1]
unionCA = rawunionCA
for i in range(len(arr3)):
    if arr3[i] in (arr3 and arr1):
        unionCA.remove(arr3[i])

print("Union of AB: ", unionAB)
print("Union of BC: ", unionBC)
print("Union of CA: ", unionCA)
print("---------------------------------------------------------------------------------")

# a)List of students who play both cricket and badminton
print("Students who play both cricket and badminton: ", intersecAB)

# b)List of students who play either cricket or badminton but not both
notintersecAB = unionAB
for i in range(len(intersecAB)):
    if intersecAB[i] in unionAB:
        notintersecAB.remove(intersecAB[i])
print("Students who play either cricket or badminton but not both: ", notintersecAB)
print("---------------------------------------------------------------------------------")

# c)Number of students who play neither cricket nor badminton
nonCB = arr3
for i in range(len(intersecCA)):
    if intersecCA[i] in (arr3):
        nonCB.remove(intersecCA[i])
for i in range(len(intersecBC)):
    if intersecBC[i] in (arr3):
        nonCB.remove(intersecBC[i])
print("Students who play neither cricket nor badminton: ", nonCB)

# d)Number of students who play cricket and football but not badminton
playAC = unionCA
for i in range(len(intersecAB)):
    if intersecAB[i] in unionCA:
        playAC.remove(intersecAB[i])
for i in range(len(intersecBC)):
    if intersecBC[i] in unionCA:
        playAC.remove(intersecBC[i])

print("Students who play cricket and football but not badminton: ", playAC)
print("---------------------------------------------------------------------------------")

# Algorithm for to find the difference of two set:
diffAB = []
for i in range(len(arr1)):
    if arr1[i] not in arr2:
        diffAB.append(arr1[i])
print("Difference of Group A - Group B: ", diffAB)
diffBA = []
for i in range(len(arr2)):
    if arr2[i] not in arr1:
        diffBA.append(arr2[i])
print("Difference of Group B - Group A: ", diffBA)
print("---------------------------------------------------------------------------------")

# Algorithm to find out complement of two set:
compA = []
for i in range(0, len(notintersecAB)):
    if notintersecAB[i] not in arr1:
        compA.append(notintersecAB[i])
print("Complement of GroupA: ", compA)

compB = []
for i in range(0, len(notintersecAB)):
    if notintersecAB[i] not in arr2:
        compB.append(notintersecAB[i])
print("Complement of GroupB: ", compB)
print("---------------------------------------------------------------------------------")
