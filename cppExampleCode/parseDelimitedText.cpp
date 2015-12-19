#include <iostream>
#include <string>
using namespace std;

int main(){
	string data, pos1, pos2, pos3;
	int position = 1;
	cout << "data string delimited by commas: " << endl;
	cin >> data;
	for(int i = 0; i <= data.size(); i++ ){
		if(data[i] == ','){
			i++;
			position++;
		}
		switch (position) {
			case 1:
			    pos1 += data[i];
			    break;
			case 2:
			    pos2 += data[i];
			    break;
			case 3:
			    pos3 += data[i];
			    break;
		}
	}
	cout << "\npos1 = "
		<< pos1
		<< "\npos2 = "
		<< pos2
		<< "\npos3 = "
		<< pos3
		<< endl;
    return 0;
}
