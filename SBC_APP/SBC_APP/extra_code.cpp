// creates a text file containing a list of the player names and prices
void createList()
{
	cout << "Please enter a player name followed by cost.\n";
	cout << "Enter 'done' when you've finished filling the list.\n";

	ofstream playerList;
	string input;
	playerList.open(FileName);
	if (playerList.is_open()) {
		while (cin) {
			cin >> input;
			if (input == "done" || input == "Done" ||
				input == "done." || input == "Done.") {
				playerList.close();
				cout << "List created.\n";
				break;
			}

			if (!isFloat(input)) {
				cout << "Player Name: " << input << '\n';
				playerList << "Player" << endl;
				playerList << input << endl;
				continue;
			}

			if (isFloat(input)) {
				cout << "Player Cost: " << input << '\n';
				playerList << "Price" << endl;
				playerList << input << endl;
				continue;
			}
		}
	}
	else cout << "Unable to open file.\n";
	return;
}

// lookups current file containing a list of players and their prices
void lookupList()
{
	ifstream list;
	string line;
	list.open(FileName);
	if (list.is_open()) {
		while (getline(list, line)) {
			cout << line << endl;
		}
		list.close();
	}
	else error("Unable to open file");
	keep_window_open();
	return;
}
