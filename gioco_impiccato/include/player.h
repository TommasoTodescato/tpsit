#ifndef GIOCO_IMPICCATO_PLAYER_H
#define GIOCO_IMPICCATO_PLAYER_H

#include <iostream>

namespace gioco
{
	class player
	{
	private:
		std::string name;

	public:
		explicit player(std::string name)
		{
			this->name = name;
		}

		bool play(std::string word, int tries);


	};
}

#endif