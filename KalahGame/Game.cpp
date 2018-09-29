# include "Game.h"
#include <ctime>
#include <cstdlib>

using namespace std;

Game::Game(){
	srand((unsigned int)time(NULL));// Generate the number of seeds in each house
	int seedArray[12]={0};
	for (int i=0;i<30;i++)
	{
		seedArray[rand() % 6]++;
		seedArray[rand() % 6 + 6]++;
	}

	node * newN;
	House * newH;
	Store * newS;
	for (int j=0;j<2;j++)
	{		
		for (int i=0;i<6;i++)
		{			
			newH = new House(seedArray[i+j*6]);
			newN = new node(newH);
			cL.push_back(newN);	
		}
		newS = new Store();
		newN = new node(newS);
		cL.push_back(newN);
	}
	cL.end()->next(cL.begin()); // finally, form the loop
}

/*
void Game::play()
{
	while (h) // while there are still some seeds in both sides, go on
*/
