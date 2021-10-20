"""Write a Python program that computes the net amount of a bank account based a
transaction log from console input. The transaction log format is shown as following: D
100 W 200 (Withdrawal is not allowed if balance is going negative. Write functions for
withdraw and deposit) D means deposit while W means withdrawal."""

global accbal
accbal = 0

def bank(transtype, ammount):
    global accbal    
    if transtype == "D":
        accbal = accbal + ammount
        print("Your Updated Total Balance is: ", accbal)
    elif transtype == "W":
        if accbal - ammount >= 0:
            accbal = accbal - ammount
            print("Your Updated Total Balance is: ", accbal)
        elif accbal == 0:
            print("Can't Withdraw Your Total Balance is: ", accbal)
        else:
            negammount = accbal - ammount
            removeammount = ammount - (- negammount)
            accbal = accbal - removeammount
            print("You were able to withdraw only", removeammount,)
            print("Your Updated Total Balance is: ", accbal)

while True:
    try:
        print("Enter the transaction and amount in this format (D/W Amount): ")
        entered = str(input())
        transtype = entered[0]
        ammount = int(entered[2:])
        bank(transtype, ammount)
    except:
        print("Wrong Input Enter Again")
        continue
