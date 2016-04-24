all:run display

run:compileShopGen
	clear
	./program

display:compileShopDisp
	clear
	./displayOptions

compile:compileShopGen compileShopDisp

compileShopGen:clean backup
	g++ shoppingListGenerator.cpp -o program

compileShopDisp:clean backup
	g++ shoppingListGenerator.cpp -o displayOptions

backup:
	cat index > indxBackup

clean:
	rm -f program displayOptions shoppingList.html
	clear

exp:
	mv -f shoppingList.html ~/Dropbox/
