# include "Game.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Windows.h"
using namespace std;

Game::Game(){
	srand((unsigned int)time(NULL));// Generate the number of seeds in each house
	int seedArray[12]={0};
	for (int i=0;i<2;i++)
	{
		seedArray[rand() % 6]++;
		seedArray[rand() % 6 + 6]++;
	}

	House * newH;
	Store * newS;
	for (int j=0;j<2;j++) // set up the vector of containers
	{		
		for (int i=0;i<6;i++)
		{			
			newH = new House(seedArray[i+j*6]);
			containerV.push_back(newH);	
		}
		newS = new Store();
		containerV.push_back(newS);
	}
}

Game::~Game(){
	vector<Container *>::iterator i;
	for (i=containerV.begin();i!=containerV.end();i++)
	{
		delete *i;
	}
}

gameStatus Game::play(){
	bool flagA	=	1; // if flagA is true, A's turn to play
	int houseID;
	int aSeeds=0, bSeeds=0; // total number of seeds in a & b's house
	do	{
		system("cls");
		display();
		// input
		if (flagA)
				cout<<"Player A's turn!"<<endl;
			else
				cout<<"Player B's turn!"<<endl;
		cout<<"Choose a house number ("<<(1-flagA)*6+1<<"-"<<(1-flagA)*6+6<<") that you want to sow the seeds (0 to quit):"<<endl;
		cin>>houseID;
		if (houseID==0)
			return quit; // quit the game
		while (houseID>(1-flagA)*6+6 || houseID<(1-flagA)*6+1) // not input the right number
		{
			cin.clear();
			cin.ignore(10, '\n');
			cout<<"Incorrect input! Please input again:"<<endl;
			cin>>houseID;
		}
		while (containerV[houseID-flagA]->sowSeeds()==0) // when 0 seed, ask another house
		{
			//cout<<"No seed in the chosen house! Please choose another house:"<<endl;
			cin>>houseID;
		}
		
		// Sow
		int curH	=	houseID-flagA;
		int tmpInt	=	containerV[curH]->sowSeeds();
		
		while(tmpInt>0)
		{
			curH = (curH+1) % 14;
			containerV[houseID-flagA]->addSeed(-1);
			containerV[curH]->addSeed(1);
			tmpInt--;
			Sleep(1000);
			system("cls");
			display();
		}
		
		// Wrap up for this round
		if (containerV[curH]->numseeds()==1 && curH>=(1-flagA)*7 && curH<=(1-flagA)*7+5 && containerV[12-curH]->numseeds()!=0) // caputured?
		{
			cout<<"Congratulations! You've captured your opponent's seeds."<<endl;
			containerV[(1-flagA)*7+6]->addSeed(containerV[12-curH]->numseeds()+containerV[curH]->numseeds());// seeds go to store
			containerV[12-curH]->addSeed(-containerV[12-curH]->numseeds());
			containerV[curH]->addSeed(-containerV[curH]->numseeds());
		}
		
		aSeeds=0;
		bSeeds=0;
		for (int i=0;i<6;i++)
		{
			aSeeds += containerV[i]->numseeds();
			bSeeds += containerV[i+7]->numseeds();
		}

		if (curH!=(1-flagA)*7+6) // if last seed is not in store, other's turn!
			flagA = !flagA;
		else
			cout<<"You've won a free turn!"<<endl;
		Sleep(1000);		
	} while (aSeeds>0 && bSeeds>0);	
	
	system("cls");
	display();
	if (containerV[6]->numseeds()>containerV[13]->numseeds()) // A wins
		return aWin;
	else if (containerV[6]->numseeds()<containerV[13]->numseeds()) // B wins
		return bWin;
	else
		return tie;
}

void Game::display(){
	cout<<"\t";
	for (int i=0;i<6;i++)
	{
		cout<<"House";
		cout.width(2);
		cout<<12-i<<"\t";
	}
	cout<<endl;
	cout<<"\t";
	for (int i=0;i<6;i++)
	{
		cout<<"-------"<<"\t";
	}
	cout<<endl;
	cout<<"\t";
	for (int i=0;i<6;i++)
	{
		cout.width(5);
		cout<<containerV[12-i]->numseeds()<<"\t";
	}
	cout<<endl;
	
	cout.fill(' ');
	cout.width(60);
	cout << left <<"Store B";
	cout << right<<"Store A"<<'\n';
	
	cout.fill(' ');
	cout.width(60);
	cout << left <<"-------";
	cout << right<<"-------"<<'\n';

	cout<<"   ";
	cout.fill(' ');
	cout.width(60);
	cout << left<<containerV[13]->numseeds();
	cout << right<<containerV[6]->numseeds()<<'\n';

	cout<<"\t";
	for (int i=0;i<6;i++)
	{
		cout<<"House";
		cout.width(2);
		cout<<i+1<<"\t";
	}
	cout<<endl;
	cout<<"\t";
	for (int i=0;i<6;i++)
	{
		cout<<"-------"<<"\t";
	}
	cout<<endl;
	cout<<"\t";
	for (int i=0;i<6;i++)
	{
		cout.width(5);
		cout<<containerV[i]->numseeds()<<"\t";
	}
	cout<<endl<<endl;
}