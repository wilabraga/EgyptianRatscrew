#ifndef DRAW_H
#define DRAW_H

#include "logic.h"


// This function will be used to draw everything about the state of your app
// including the background and whatnot.
void fullDrawAppState(AppState *state);

void drawAppState(AppState *state);

// This function will be used to undraw (i.e. erase) things that might
// move in a frame. E.g. in a Snake game, erase the Snake, the food & the score.
void undrawAppState(AppState *state);

void drawCursor(Cursor *cursor);

void drawStartScreen(void);

void drawOpponents(Opponent opponents[], int arr_size);

void drawOpponent(Opponent *opponent);

void drawDeck(Deck *deck);

void drawCard(Card *card);

void drawCardBack(CardBack *cardBack);

void drawSlap(int turn);

void hideCardBack(CardBack *cardBack);

void hideSlap(int turn);

void hideCard(Card* card);

void drawTwoDigitNum(int x, int y, int num, u16 color);
// If you have anything else you need accessible from outside the graphics.c
// file, you can add them here. You likely won't.

#endif
