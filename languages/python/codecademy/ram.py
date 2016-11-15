groceries = [
    "banana",
    "orange",
    "apple"
]



def compute_bill(food):
    total = 0
    for item in food:
        if(stock[item] > 0):
            total += prices[item] 
    return total
