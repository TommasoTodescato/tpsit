#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

#define FILE_LEN 60453

string get_random_word(const string& file_path, const int& file_length)
{
	string s = "";
	ifstream words_file (file_path);
	if (!words_file.is_open())
	{
		cout << "Percorso non valido" << endl;
		return s;
	}

	random_device r;
	mt19937 gen(r()); // Mersenne Twister
	uniform_int_distribution<> distribution(1, file_length);
	int line_number = distribution(gen);

	for (int i = 1; i <= line_number; i++)
		getline(words_file, s);
	words_file.close();
	return s;
}

int main()
{
	int tries = 10;

	string word = get_random_word("/home/tommaso/info/tpsit/gioco_impiccato/parole.txt", FILE_LEN);
	cout << word << endl;

	string unknown(word.size(), '_');
	for (int i = 0; i < tries; i++)
	{
		cout << "[?] Indovina la lettera: " << endl;

		string input;
		cin >> input;
		while (input.length() != 1 || !isalpha(input[0]))
		{
			cout << "[!] Stringa non alfabetica o troppo lunga. Riprova: " << endl;
			cin >> input;
		}

		if (word.find(input[0]) != string::npos)
		{
			for (int c = 0; c < unknown.length(); c++)
				if (word[c] == input[0])
					unknown[c] = word[c];
			cout << "[V] Giusto | " << unknown << endl;
		}
		else
			cout << "[X] Sbagliato | " << unknown << endl;

		if (word == unknown)
		{
			cout << "[V] HAI VINTO! | " << unknown << endl;
			break;
		}
	}
	if (word != unknown)
	{
		cout << "[X] HAI PERSO! | " << word << endl;
	}

//	ofstream myfile ("/home/tommaso/info/tpsit/gioco_impiccato/a.txt", ios::app);
//	if (!myfile.is_open())
//	{
//		cout << "Percorso non valido" << endl;
//		return 1;
//	}
//
//	myfile << "caca\n";
//	myfile << "popo\n";
//	myfile.close();

	return 0;
}