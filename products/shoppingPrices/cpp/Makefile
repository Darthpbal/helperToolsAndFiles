all:run display

run:compileShopGen
	clear
	./shoppingListGenerator

display:compileShopDisp
	./displayOptions
	less options

compile:compileShopGen compileShopDisp

compileShopGen:clean backup
	g++ shoppingListGenerator.cpp Shlist.cpp -o shoppingListGenerator

compileShopDisp:clean backup
	g++ displayOptions.cpp -o displayOptions

backup:
	cat index > indxBackup

sort:
	sort index > tmpFile
	cat tmpFile > index
	rm tmpFile

clean:
	rm -f shoppingListGenerator displayOptions shoppingList.html options
	clear

exp:
	mv -f shoppingList.html ~/Dropbox/
