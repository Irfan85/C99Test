#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card{
    char *suit;
    char *face;
};

void printDeck(struct card deck[]){
    for(int i = 0; i < 52; i++){
        printf("%s of %s\n", deck[i].face, deck[i].suit);
    }
}

void shuffle(struct card deck[]){
    //Seeding rand() with current system time
    srand(time(NULL));

    for(int i = 0; i < 52; i++){
        //Generate random numbers form 0 to 51
        int random = rand() % 52;

        struct card temp_card = deck[i];
        deck[i] = deck[random];
        deck[random] = temp_card;
    }
}

int DeckOfCards_main(){
    struct card deck[52];

    char *suits[4] = {"Hearts", "Diamonds", "Spades", "Clubs"};
    char *faces[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            deck[(i * 13) + j].suit = suits[i];
            deck[(i * 13) + j].face = faces[j];
        }
    }

    printDeck(deck);

    puts("\nShuffling...\n"); //Extra space

    shuffle(deck);
    printDeck(deck);

    return 0;
}