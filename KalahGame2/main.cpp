# include "Container.h"
# include "House.h"
# include "Store.h"
# include "Game.h"
# include <iostream>

using namespace std;

void main(){
	char ans;// whether to continue playing the game
	do{ 
		Game newG;
		gameStatus result = newG.play();
		switch (result){
			case aWin:
				cout<<"WOW! Player A has won the game!"<<endl;
				break;
			case bWin:
				cout<<"WOW! Player B has won the game!"<<endl;
				break;
			case tie:
				cout<<"It's a tie!"<<endl;
				break;
			default: // quit
				cout<<"You have chosen to quit!"<<endl;
				break;
			}
		if (result!=quit)
		{
			cout<<"Want to play again? (pree 0 to quit and press other key to continue):";
			cin>>ans;
		} else
			ans='0';		
	} while (ans!='0');
}