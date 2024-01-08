#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ofstream myfile ("/home/tommaso/info/tpsit/gioco_impiccato/parole.txt", std::ios::app);
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
