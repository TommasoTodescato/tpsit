#include "include/file_handler.h"
#include "include/player.h"

using namespace std;

#define SCORE_PATH "/home/tommaso/info/tpsit/gioco_impiccato/a.txt"
#define INPUT_PATH "/home/tommaso/info/tpsit/gioco_impiccato/parole.txt"
#define INPUT_LEN 60453

string input_nickname()
{
	string player_name;
	cout << "Inserisci il tuo nickname: ";
	cin >> player_name;
	while (player_name.length() > 16)
	{
		cout << "Il nome deve essere sotto i 16 caratteri, riprova: ";
		cin >> player_name;
	}
	return player_name;
}

int main()
{
	string nickname = input_nickname();
	auto p = gioco::player(nickname);
	string word = gioco::get_random_word(INPUT_PATH, INPUT_LEN);

	bool victory = p.play(word, 10);
	if (!victory)
		cout << "[X] HAI PERSO! | " << word << endl;

	ofstream myfile (SCORE_PATH, ios::app);
	if (!myfile.is_open())
	{
		cout << "Percorso non valido" << endl;
		return 1;
	}

	myfile << "caca\n";
	myfile.close();

	return 0;
}