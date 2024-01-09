#ifndef GIOCO_IMPICCATO_FILE_HANDLER_H
#define GIOCO_IMPICCATO_FILE_HANDLER_H

#include <iostream>
#include <fstream>
#include <random>

namespace gioco
{
	std::string get_random_word(const std::string& file_path, const int& file_length);


}

#endif
