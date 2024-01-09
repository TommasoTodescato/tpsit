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
	string word = get_random_word("/home/tommaso/info/tpsit/gioco_impiccato/parole.txt", FILE_LEN);
	cout << word << endl;

	ofstream myfile ("/home/tommaso/info/tpsit/gioco_impiccato/a.txt", ios::app);
	if (!myfile.is_open())
	{
		cout << "Percorso non valido" << endl;
		return 1;
	}

	myfile << "caca\n";
	myfile << "popo\n";
	myfile.close();

	return 0;
}