#include "include/file_handler.h"
#include "include/player.h"

using namespace std;

#define SCORE_PATH "/home/tommaso/info/tpsit/gioco_impiccato/scoreboard.txt"
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
	auto p = gioco::player(nickname, 10);
	string word = gioco::get_random_word(INPUT_PATH, INPUT_LEN);

	cout << word << endl;

	int tot_score = 0;
	while (p.life > 0)
	{
		int score = p.play(word);
		tot_score += score;
	}
	cout << "[X] HAI PERSO! | punteggio = " << tot_score << endl;


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