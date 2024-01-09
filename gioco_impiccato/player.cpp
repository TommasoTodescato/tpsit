#include "include/player.h"

using namespace std;

namespace gioco
{
	bool player::play(string word, int tries)
	{
		cout << word << endl;

		string unknown(word.size(), '_');
		for (int i = 0; i < tries; i++) {
			string input;
			cout << "[?] Indovina la lettera: " << endl;
			cin >> input;
			while (input.length() != 1 || !isalpha(input[0]))
			{
				cout << "[!] Stringa non alfabetica o troppo lunga. Riprova: " << endl;
				cin >> input;
			}

			if (word.find(input[0]) != string::npos)
			{
				if (unknown.find(input[0]) != string::npos)
				{
					cout << "[X] Già trovata | " << unknown << endl;
					continue;
				}
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
				return true;
			}
		}
		return word == unknown;
	}
}