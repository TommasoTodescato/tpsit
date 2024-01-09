#include "include/file_handler.h"
using namespace std;

namespace gioco
{
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

	void print_scoreboard()
	{
		cout << "ok";
	}
}