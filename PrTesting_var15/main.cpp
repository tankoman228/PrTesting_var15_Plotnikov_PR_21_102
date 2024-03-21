#include "Array.h"
#include <iostream>

using namespace std;
Array<char> c_array;

void execute_command(string cmd) {

	if (cmd == "help") {
		cout << "help : list of commands" << endl;
		cout << "array : print array" << endl;
		cout << "new_array <array> : set new list of chars (don\'t use spaces)" << endl;
		cout << "set <index> <value> : set array element" << endl;
		cout << "get <index> : get array element" << endl;
		cout << "swap <start_index1> <start_index2> <zones_length>" << endl;
	}
	else if (cmd == "array") {

		for (int i = 0; i < c_array.size(); i++) {
			cout << c_array[i] << ' ';
		}
		cout << endl;
	}
	else if (cmd == "new_array") {

		string new_charlist;
		cin >> new_charlist;

		char* chars = new char[new_charlist.size()];
		for (int i = 0; i < new_charlist.size(); i++) {
			chars[i] = new_charlist[i];
		}
		c_array = Array<char>(chars, new_charlist.size());
	}
	else if (cmd == "set") {

		try {
			int i; cin >> i;
			char x; cin >> x; 
			c_array.set(i, x);
			cout << "success!\n";
		}
		catch (int) {
			cout << "bad index!" << endl;
		}
	}
	else if (cmd == "get") {
		try {
			int i; cin >> i;
			cout << c_array[i];
		}
		catch (int) {
			cout << "bad index!" << endl;
		}
	}
	else if (cmd == "swap") {
		//<start_index1> <start_index2> <zones_length>
		int i1; cin >> i1;
		int i2; cin >> i2;
		int l; cin >> l;

		try {
			for (int i = i1, j = i2, k = 0; k < l; i++, j++, k++) {
				char a = c_array[i];
				c_array.set(i, c_array[j]);
				c_array.set(j, a);
			}
		}
		catch (int) {
			cout << "Out of range!" << endl;
		}
	}
	else {
		cout << "Unknown command! Print help to get full list of available commands\n";
	}
}

int main() {
	
	cout << "Array manager started\n\n";

	char* char_array = new char[5] {'a', 'b', 'c', 'd', 'e'};
	c_array = Array<char>(char_array, 5);

	string cmd = "help";
	do {
		cin >> cmd;
		execute_command(cmd);
		cout << endl;
	} while (cmd != "exit");
}

