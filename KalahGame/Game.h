// The class Game controls the flow of the game
# ifndef GAME_H
# define GAME_H
# include "ContainerList.h"
# include "Container.h"
# include "House.h"
# include "Store.h"

class Game{
	containerList cL;
public:
	Game();// Default constructor
	~Game(){};// Default destructor

	void play(); // main member function to play the game
};

# endif