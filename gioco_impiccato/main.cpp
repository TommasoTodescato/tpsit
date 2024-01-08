#include <iostream>
#include <fstream>
#include <string>
#include <random>

#define FILE_LEN 60453

int main()
{
	int line_number = 7;
	std::random_device r;
	std::mt19937 gen(r()); // Mersenne Twister
	std::uniform_int_distribution<> distribution(1, FILE_LEN);

	for (int i = 0; i < 5; ++i)
	{
		int randomNum = distribution(gen);
		std::cout << "Random number: " << randomNum << std::endl;
	}
	
	std::string s;
	std::ifstream file_words ("/home/tommaso/info/tpsit/gioco_impiccato/parole.txt", std::ios::app);
	for (int i = 1; i <= line_number; i++)
		std::getline(file_words, s);

	std::ofstream myfile ("/home/tommaso/info/tpsit/gioco_impiccato/a.txt", std::ios::app);
	if (!myfile.is_open())
	{
		std::cout << "Percorso non valido" << std::endl;
		return 1;
	}

	myfile << "caca\n";
	myfile << "popo\n";
	myfile.close();

	return 0;
}
