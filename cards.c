#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 #define SUITS 4
 #define FACES 13
 #define CARDS 52

 // prototypes
 void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
 void deal(unsigned int wDeck[][FACES], const char *wFace[],
 const char *wSuit[]); // dealing doesn't modify the arrays

int main(void)
{
 // initialize deck array
	unsigned int deck[SUITS][FACES] = {0};

	srand(time(NULL)); // seed random-number generator
	shuffle(deck); // shuffle the deck

	//initialize suit array
	const char *suit[SUITS] = {"Hearts","Diamonds","Clubs","Spades"};

	//initialise face array
	const char *face[FACES] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};

	deal(deck, face, suit); // deal the deck
}
//shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
	//for each of the cards choose slot of deck randomly
	for (size_t card = 1; card <= CARDS; card++)
	{
		size_t row;
		size_t column;

		//choose new random location until unoccupied slot found
		do
		{
			row = rand() % SUITS;
			column = rand() % FACES;
		}while(wDeck[row][column] != 0);

		//PLACE CARD NUMBER IN CHOSEN SLOT OF DECK
		wDeck[row][column] = card;
	}
}
//deal cards in deck
void deal (unsigned int wDeck[][FACES],const char *wFace[],const char *wSuit[])
{
	//deal each of the cards
	for (size_t card = 1; card <= CARDS; ++card)
	{
		//loop through rows of wDeck
		for (size_t row = 0; row < SUITS; ++row)
		{
			//loop through columns of wDeck for current row
			for(size_t column = 0; column < FACES; ++column)
			{
				//if slot contains current card , display card
				if (wDeck[row][column] == card)
				{
					printf("%5s of %-8s%c",wFace[column],wSuit[row],card % 2 == 0 ? '\n' : '\t'); //2 column format
				}

			}
		}
	}
}

