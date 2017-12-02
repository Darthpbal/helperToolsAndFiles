prices = {
    "banana" : 4,
    "apple" : 2,
    "orange" : 1.5,
    "pear" : 3
}
stock = {
    "banana" : 6,
    "apple" : 0,
    "orange" : 32,
    "pear" : 15
}

# for key in prices:
#     print key
#     print "price: " + str(prices[key])
#     print "stock: " + str(stock[key])
#



# total = 0
#
# for item in prices:
#     print prices[item] * stock[item]
#     total += prices[item] * stock[item]
#
# print total

# shopping management up to this point





groceries = []

def compute_bill(food):
    total = 0
    for item in food:
        if stock[item] > 0:
            total += prices[item]
            stock[item] -= 1
    return total


looper = True

while looper:
    action = raw_input("display stock or shop?\ndisplay\nshop\n")
    action = action.lower()
    if(action == "display"):
        for item in stock:
            print "%s: %d left, $%2.2f/ea\n" % (item, stock[item], prices[item])
    elif(action == "shop"):
        done = False
        while done == False:
            item = raw_input("Add to groceries\n")
            if item.lower() == "done":
                done == True
            elif item.lower in stock.keys():
                print "in stock!"
            else:
                print "not in stock..."
    elif(action == "exit"):
        print "False"
    else:
        print "action error"



print compute_bill(groceries)
