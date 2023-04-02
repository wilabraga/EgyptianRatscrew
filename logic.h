#ifndef LOGIC_H
#define LOGIC_H

#include "myLib.h"

typedef struct {
    Opponent *opponent;

    // if 1, main(void) returns 1
    int mallocError;

    // num frames in current state
    int frames;

    // num frames till opponent will slap / place
    int oppSlap;
    int oppPlace;

    // state = 0: Player May Place Card (Anyone May Slap)
    // state = 1: Opponent May Place Card (Anyone May Slap)
    // state = 2: Card Being Placed (No Slap)
    // state = 3: Slap Made (No Slap)
    // state = 4: Pile Won (No Slap)
    // state = 5: Pile Lost (No Slap)
    // state = 6: Game Over - Player Wins
    // state = 7: Game Over - Opponent Wins
    int state;

    // 0 = no one, 1 = player, 2 = opponent
    int whoSlapped;
    int whoPlayed;

    // 0 = no, 1 = yes
    int shouldSlap;

    int xVariation;
    int yVariation;

    int fcAttempts;

    Card *moving;

    /*
    * TA-TODO: Add any logical elements you need to keep track of in your app.
    *
    * For example, for a Snake game, those could be:
    *
    * Snake snake;
    * Food foods[10];
    * int points;
    *
    */
    Deck *playerDeck;
    Deck *opponentDeck;
    Deck *pileDeck;

    CardBack *hiddenCard;
} AppState;

/*
* TA-TODO: Add any additional structs that you need for your app.
*
* For example, for a Snake game, one could be:
*
* typedef struct {
*   int heading;
*   int length;
*   int x;
*   int y;
* } Snake;
*
*/
struct Cursor {
    int x;
    int y;
    int sprite_shape;
    int sprite_size;
    int palette_id;
    int id;
};

#define MAX_CURSOR_X 143
#define MIN_CURSOR_X 2
#define MAX_CURSOR_Y 228
#define MIN_CURSOR_Y 1

struct Opponent {
    char *name;
    int difficulty;
    int x;
    int y;
    const u16 *image;
};

struct CardBack {
    int x;
    int y;
    int shadow;
};

struct Card {
    Card *next;
    // CLUBS = 0, DIAMONDS = 1, HEARTS = 2, SPADES = 3
    int suit;
    // A = 1, 2 - 10, J = 11, Q = 12, K = 13
    int value;
    // 2 - 10 = 0, J = 1, Q = 2, K = 3, A = 4
    int faceCardAttempts;
    int x;
    int y;
    int id;
};

#define CARDOFFSET(SUIT, VALUE) (((SUIT) * 13) + ((VALUE) - 1))

struct Deck {
    Card *head;
    CardBack *cardBack;
    int size;
};

// This function can initialize an unused AppState struct.
void initializeAppState(AppState *appState);

// This function will be used to process app frames.
AppState processAppState(AppState *currentAppState, u32 keysPressedBefore, u32 keysPressedNow);

void freeAppState(AppState *appState);

int equals(Card* one, Card* two);

// If you have anything else you need accessible from outside the logic.c
// file, you can add them here. You likely won't.

#endif
