run:compile
	clear
	./program

compile:clean
	g++ shoppingListGenerator.cpp -o program

backup:
	cat index > indxBackup
	
clean:
	rm -f program shoppingList.html
	clear

exp:
	mv -f shoppingList.html ~/Dropbox/
