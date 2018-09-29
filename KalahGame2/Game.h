// The class Game controls the flow of the game
# ifndef GAME_H
# define GAME_H
# include <vector>
# include "Container.h"
# include "House.h"
# include "Store.h"

using namespace std;

enum gameStatus {aWin, bWin, tie, quit};

class Game{
	vector<Container *> containerV;
public:
	Game(); // Default constructor
	~Game(); // Default destructor

	void display();// display houses and stores
	gameStatus play(); // main member function to play the game
};

# endif
