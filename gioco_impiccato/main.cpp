#include "include/file_handler.h"
#include "include/game.h"


using namespace std;

#define FILE_LEN 60453





int main()
{
	string word = get_random_word("/home/tommaso/info/tpsit/gioco_impiccato/parole.txt", FILE_LEN);
	bool victory = play(word, 10);
	if (!victory)
		cout << "[X] HAI PERSO! | " << word << endl;

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