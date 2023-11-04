class Item:
    def __init__(self, name, value, weight):
        self.name = name
        self.value = value
        self.weight = weight


def fractionalKnapsack(capacity, arr):
    finalvalue = 0
    arr.sort(key=lambda x: (x.value/x.weight), reverse=True)

    for item in arr:
        if item.weight <= capacity:
            capacity = capacity - item.weight
            finalvalue = finalvalue + item.value
        else:
            finalvalue = finalvalue + item.value * (capacity / item.weight)
            break
    return finalvalue


capacity = 50
arr = [Item("item1", 60, 10), Item("item2", 100, 20), Item("item3", 120, 30)]

max_val = fractionalKnapsack(capacity, arr)
for i in arr:
    print("Item:", i.name, ", Value:", i.value, ", Weight:", i.weight)
print("Total value in the knapsack:", max_val)
