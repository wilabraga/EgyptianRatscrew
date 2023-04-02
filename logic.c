#include "logic.h"
#include "images/sprites.h"
#include <stdlib.h>

static int shouldSlap(AppState *currentAppState);
static int opponentSlapped(AppState *currentAppState);
static void freeDeck(Deck *deck);
static Card* popTopDeck(Deck *deck);
static void pushTopDeck(Deck *deck, Card *card);
static void pushBotDeck(Deck *deck, Card *card);
static void combineDecks(Deck *mainDeck, Deck* toCombine);

void initializeAppState(AppState* appState) {
    // TA-TODO: Initialize everything that's part of this AppState struct here.
    // Suppose the struct contains random values, make sure everything gets
    // the value it should have when the app begins.

    // Make All Decks
    Deck *playerDeck = malloc(sizeof(Deck));
    Deck *opponentDeck = malloc(sizeof(Deck));
    Deck *pileDeck = malloc(sizeof(Deck));
    appState -> mallocError = 0;
    if (playerDeck == NULL || opponentDeck == NULL || pileDeck == NULL) {
        appState -> mallocError = 1;
        return;
    }

    Card *allCards[52];
    int cardIDs[52] = {CARD1_ID, CARD2_ID, CARD3_ID, CARD4_ID, CARD5_ID, CARD6_ID, CARD7_ID, CARD8_ID, CARD9_ID, CARD10_ID, CARD11_ID, CARD12_ID, CARD13_ID, CARD14_ID, CARD15_ID, CARD16_ID, CARD17_ID, CARD18_ID, CARD19_ID, CARD20_ID, CARD21_ID, CARD22_ID, CARD23_ID, CARD24_ID, CARD25_ID, CARD26_ID, CARD27_ID, CARD28_ID, CARD29_ID, CARD30_ID, CARD31_ID, CARD32_ID, CARD33_ID, CARD34_ID, CARD35_ID, CARD36_ID, CARD37_ID, CARD38_ID, CARD39_ID, CARD40_ID, CARD41_ID, CARD42_ID, CARD43_ID, CARD44_ID, CARD45_ID, CARD46_ID, CARD47_ID, CARD48_ID, CARD49_ID, CARD50_ID, CARD51_ID, CARD52_ID};
    // Make All Cards
    for (int suit = 0; suit < 4; suit++) {
        for (int val = 1; val <= 13; val++) {
            Card *card = malloc(sizeof(Card));
            if (card == NULL) {
                appState -> mallocError = 1;
                return;
            }
            card -> suit = suit;
            card -> value = val;
            card -> id = cardIDs[CARDOFFSET(suit, val)];
            int fca = 0;
            if (val == 1) {
                fca = 4;
            } else if (val > 10) {
                fca = (val - 10);
            }
            card -> faceCardAttempts = fca;
            allCards[CARDOFFSET(suit, val)] = card;
        }
    }

    // Shuffle
    for (int i = 0; i < 52; i++) {
        int index = randint(0, 52);
        Card *temp = allCards[index];
        allCards[index] = allCards[i];
        allCards[i] = temp;
    }

    // Player / Opponent Decks
    Card *prevPlayer = NULL;
    Card *prevOpp = NULL;
    for (int i = 0; i < 52; i++) {
        Card *next = allCards[i];
        if (i % 2 == 0) {
            // player card
            if (i < 2) {
                playerDeck -> head = next;
            } else {
                prevPlayer -> next = next;
            }
            prevPlayer = next;
        } else {
            //opponent card
            if (i < 2) {
                opponentDeck -> head = next;
            } else {
                prevOpp -> next = next;
            }
            prevOpp = next;
        }
    }
    appState -> playerDeck = playerDeck;
    appState -> opponentDeck = opponentDeck;
    appState -> pileDeck = pileDeck;

    appState -> opponentDeck -> size = 26;
    appState -> playerDeck -> size = 26;

    CardBack *opponentBack = malloc(sizeof(CardBack));
    if (opponentBack == NULL) {
        appState -> mallocError = 1;
        return;
    }
    opponentBack -> x = 20;
    opponentBack -> y = WIDTH/2 - 5;
    opponentBack -> shadow = OPPONENTCARDBACK;
    appState -> opponentDeck -> cardBack = opponentBack;

    CardBack *playerBack = malloc(sizeof(CardBack));
    if (playerBack == NULL) {
        appState -> mallocError = 1;
        return;
    }
    playerBack -> x = 117;
    playerBack -> y = WIDTH/2 - 5;
    playerBack -> shadow = PLAYERCARDBACK;
    appState -> playerDeck -> cardBack = playerBack;

    appState -> state = 0;
    appState -> pileDeck -> size = 0;
    appState -> frames = 0;
    appState -> oppSlap = -1;
    appState -> shouldSlap = 0;
    appState -> moving = NULL;
    appState -> fcAttempts = -1;
    appState -> whoSlapped = 0;
    appState -> xVariation = 0;
    appState -> yVariation = 0;
    appState -> whoPlayed = 0;
    appState -> oppPlace = -1;

    CardBack *hiddenCard = malloc(sizeof(CardBack));
    if (hiddenCard == NULL) {
        appState -> mallocError = 1;
        return;
    }
    hiddenCard -> x = 117;
    hiddenCard -> y = WIDTH/2 - 5;
    hiddenCard -> shadow = HIDDENCARDBACK;
    appState -> hiddenCard = hiddenCard;
}

// TA-TODO: Add any process functions for sub-elements of your app here.
// For example, for a snake game, you could have a processSnake function
// or a createRandomFood function or a processFoods function.
//
// e.g.:
// static Snake processSnake(Snake* currentSnake);
// static void generateRandomFoods(AppState* currentAppState, AppState* nextAppState);

// This function processes your current app state and returns the new (i.e. next)
// state of your application.

AppState processAppState(AppState *currentAppState, u32 keysPressedBefore, u32 keysPressedNow) {
    /* TA-TODO: Do all of your app processing here. This function gets called
     * every frame.
     *
     * To check for key presses, use the KEY_JUST_PRESSED macro for cases where
     * you want to detect each key press once, or the KEY_DOWN macro for checking
     * if a button is still down.
     *
     * To count time, suppose that the GameBoy runs at a fixed FPS (60fps) and
     * that VBlank is processed once per frame. Use the vBlankCounter variable
     * and the modulus % operator to do things once every (n) frames. Note that
     * you want to process button every frame regardless (otherwise you will
     * miss inputs.)
     *
     * Do not do any drawing here.
     *
     * TA-TODO: VERY IMPORTANT! READ THIS PART.
     * You need to perform all calculations on the currentAppState passed to you,
     * and perform all state updates on the nextAppState state which we define below
     * and return at the end of the function. YOU SHOULD NOT MODIFY THE CURRENTSTATE.
     * Modifying the currentAppState will mean the undraw function will not be able
     * to undraw it later.
     */
    AppState nextAppState = *currentAppState;
    nextAppState.frames++;
    int state = currentAppState -> state;
    switch(state) {
        case 0: // Player Turn
        {   
            if (nextAppState.oppSlap >= 0 && nextAppState.oppSlap <= currentAppState -> frames) {
                // Opponent Slapped
                nextAppState.oppSlap = -1;
                nextAppState.frames = 0;
                nextAppState.state = 3;
                nextAppState.whoSlapped = 2;
            } else if (KEY_JUST_PRESSED(BUTTON_A, keysPressedNow, keysPressedBefore)) {
                // Player Slapped
                nextAppState.frames = 0;
                nextAppState.state = 3;
                nextAppState.whoSlapped = 1;
            } else if ((!currentAppState -> shouldSlap || currentAppState -> frames > 80) && nextAppState.fcAttempts == 0) {
                // No More FC Attempts (Opp Victory)
                nextAppState.oppSlap = -1;
                nextAppState.whoSlapped = 2;
                nextAppState.frames = 0;
                nextAppState.state = 4;
                nextAppState.fcAttempts = -1;
            } else if (currentAppState -> playerDeck -> size > 0 && KEY_JUST_PRESSED(BUTTON_B, keysPressedNow, keysPressedBefore)) {
                // Place Down
                nextAppState.frames = 0;
                nextAppState.state = 2;
                Card *drawn = popTopDeck(nextAppState.playerDeck);
                nextAppState.moving = drawn;
                nextAppState.whoPlayed = 1;
            } else if (currentAppState -> frames > 30 && currentAppState -> playerDeck -> size == 0) {
                nextAppState.state = 7;
            }
            break;
        }
        case 1: // Opponent Turn
        {
            if (currentAppState -> frames == 0) {
                nextAppState.oppPlace = randint(70, 100);
            }
            if (nextAppState.oppSlap >= 0 && nextAppState.oppSlap <= currentAppState -> frames) {
                // Opponent Slapped
                nextAppState.oppSlap = -1;
                nextAppState.frames = 0;
                nextAppState.state = 3;
                nextAppState.whoSlapped = 2;
            } else if (KEY_JUST_PRESSED(BUTTON_A, keysPressedNow, keysPressedBefore)) {
                // Player Slapped
                nextAppState.frames = 0;
                nextAppState.state = 3;
                nextAppState.whoSlapped = 1;
            } else if ((!currentAppState -> shouldSlap || currentAppState -> frames > 80) && nextAppState.fcAttempts == 0) {
                // No More FC Attempts (Player Victory)
                nextAppState.fcAttempts = -1;
                nextAppState.oppSlap = -1;
                nextAppState.whoSlapped = 1;
                nextAppState.frames = 0;
                nextAppState.state = 4;
            } else if (currentAppState -> opponentDeck -> size > 0 && nextAppState.oppPlace <= currentAppState -> frames) {
                // Place Down
                nextAppState.frames = 0;
                nextAppState.state = 2;
                Card *drawn = popTopDeck(nextAppState.opponentDeck);
                nextAppState.moving = drawn;
                nextAppState.whoPlayed = 2;
            } else if (currentAppState -> frames > 30 && currentAppState -> opponentDeck -> size == 0) {
                nextAppState.state = 6;
            }
            break;
        }
        case 2: // Card Being Placed Down
        {
            if (currentAppState -> frames == 0) {
                // int xV = 0;
                // int yV = 0;
                // if (currentAppState -> pileDeck -> size > 0) {
                //     do {
                //         xV = randint(-2, 2) * 5;
                //         yV = randint(-2, 2) * 5;
                //     } while (xV != currentAppState -> xVariation && yV != currentAppState -> yVariation);
                //     nextAppState.xVariation = xV;
                //     nextAppState.yVariation = yV;
                // }
                if (currentAppState -> whoPlayed == 1) {
                    nextAppState.hiddenCard -> x = currentAppState -> playerDeck -> cardBack -> x;
                    nextAppState.hiddenCard -> y = currentAppState -> playerDeck -> cardBack -> y;
                } else {
                    nextAppState.hiddenCard -> x = currentAppState -> opponentDeck -> cardBack -> x;
                    nextAppState.hiddenCard -> y = currentAppState -> opponentDeck -> cardBack -> y;
                }
            } else {
                int x = CARDXCENTER; //+ (currentAppState -> xVariation);
                int y = CARDYCENTER; //+ (currentAppState -> yVariation);
                if (currentAppState -> hiddenCard -> x != x || currentAppState -> hiddenCard -> y != y) {
                    if (currentAppState -> hiddenCard -> x < x) {
                        nextAppState.hiddenCard -> x++;
                    } else if (currentAppState -> hiddenCard -> x > x) {
                        nextAppState.hiddenCard -> x--;
                    }
                    if (currentAppState -> hiddenCard -> y < y) {
                        nextAppState.hiddenCard -> y++;
                    } else if (currentAppState -> hiddenCard -> y > y) {
                        nextAppState.hiddenCard -> y--;
                    }
                } else {
                    pushTopDeck(nextAppState.pileDeck, currentAppState -> moving);
                    nextAppState.moving -> x = currentAppState -> hiddenCard -> x;
                    nextAppState.moving -> y = currentAppState -> hiddenCard -> y;
                    nextAppState.shouldSlap = shouldSlap(&nextAppState);
                    nextAppState.oppSlap = opponentSlapped(&nextAppState);
                    nextAppState.frames = 0;
                    int flipped = 0;
                    if (nextAppState.pileDeck -> head -> faceCardAttempts > 0) {
                        nextAppState.fcAttempts = nextAppState.moving -> faceCardAttempts;
                        flipped = 1;
                    } else if (currentAppState -> fcAttempts > 0) {
                        nextAppState.fcAttempts--;
                    }
                    if (currentAppState -> whoPlayed == 1) {
                        //player
                        if (nextAppState.fcAttempts >= 0 && !flipped) {
                            //still playing on fc
                            nextAppState.state = 0;
                        } else {
                            nextAppState.state = 1;
                        } 
                    } else {
                        //opponent
                        if (nextAppState.fcAttempts >= 0 && !flipped) {
                            //still playing on fc
                            nextAppState.state = 1;
                        } else {
                            nextAppState.state = 0;
                        } 
                    }
                }
            }
            break;
        }
        case 3: // Slap Being Made
        {
            if (currentAppState -> frames > 40) {
                nextAppState.frames = 0;
                if (currentAppState -> shouldSlap) {
                    nextAppState.state = 4;
                } else {
                    nextAppState.state = 5;
                }
                nextAppState.shouldSlap = 0;
            }
            break;
        }
        case 4: // Card Pile Won (Take Pile)
        {
            nextAppState.fcAttempts = -1;
            if (currentAppState -> frames == 0) {
                nextAppState.hiddenCard -> x = CARDXCENTER;
                nextAppState.hiddenCard -> y = CARDYCENTER;
            } else {
                int x = currentAppState -> playerDeck -> cardBack -> x;
                int y = currentAppState -> playerDeck -> cardBack -> y;
                if (currentAppState -> whoSlapped == 2) {
                    x = currentAppState -> opponentDeck -> cardBack -> x;
                    y = currentAppState -> opponentDeck -> cardBack -> y;
                }
                if (currentAppState -> hiddenCard -> x != x || currentAppState -> hiddenCard -> y != y) {
                    if (currentAppState -> hiddenCard -> x < x) {
                        nextAppState.hiddenCard -> x++;
                    } else if (currentAppState -> hiddenCard -> x > x) {
                        nextAppState.hiddenCard -> x--;
                    }
                    if (currentAppState -> hiddenCard -> y < y) {
                        nextAppState.hiddenCard -> y++;
                    } else if (currentAppState -> hiddenCard -> y > y) {
                        nextAppState.hiddenCard -> y--;
                    }
                } else {
                    if (currentAppState -> whoSlapped == 1) {
                        combineDecks(nextAppState.playerDeck, nextAppState.pileDeck);
                    } else {
                        combineDecks(nextAppState.opponentDeck, nextAppState.pileDeck);
                    }
                    if (currentAppState -> whoSlapped == 1){
                        nextAppState.frames = 0;
                        nextAppState.state = 0;
                    } else {
                        nextAppState.frames = 0;
                        nextAppState.state = 1;
                    }
                }
            }
            break;
        }
        case 5: // Card Pile Lost (Burn a Card)
        {
            if (currentAppState -> frames == 0) {
                if (currentAppState -> whoSlapped == 2) {
                    nextAppState.hiddenCard -> x = currentAppState -> opponentDeck -> cardBack -> x;
                    nextAppState.hiddenCard -> y = currentAppState -> opponentDeck -> cardBack -> y;
                } else {
                    nextAppState.hiddenCard -> x = currentAppState -> playerDeck -> cardBack -> x;
                    nextAppState.hiddenCard -> y = currentAppState -> playerDeck -> cardBack -> y;
                }
            } else if (currentAppState -> whoSlapped == 1 && currentAppState -> playerDeck -> size == 0) {
                nextAppState.state = 7;
            } else if (currentAppState -> whoSlapped == 2 && currentAppState -> opponentDeck -> size == 0) {
                nextAppState.state = 6;
            } else {
                int x = CARDXCENTER;
                int y = CARDYCENTER;
                if (currentAppState -> hiddenCard -> x != x || currentAppState -> hiddenCard -> y != y) {
                    if (currentAppState -> hiddenCard -> x < x) {
                        nextAppState.hiddenCard -> x++;
                    } else if (currentAppState -> hiddenCard -> x > x) {
                        nextAppState.hiddenCard -> x--;
                    }
                    if (currentAppState -> hiddenCard -> y < y) {
                        nextAppState.hiddenCard -> y++;
                    } else if (currentAppState -> hiddenCard -> y > y) {
                        nextAppState.hiddenCard -> y--;
                    }
                } else {
                    if (currentAppState -> whoSlapped == 1 && currentAppState -> playerDeck -> size > 0) {
                        pushBotDeck(nextAppState.pileDeck, popTopDeck(nextAppState.playerDeck));
                    } else if (currentAppState -> whoSlapped == 2 && currentAppState -> opponentDeck -> size > 0) {
                        pushBotDeck(nextAppState.pileDeck, popTopDeck(nextAppState.opponentDeck));
                    } 
                    if ((currentAppState -> whoPlayed == 1 && currentAppState -> fcAttempts < 0) || (currentAppState -> whoPlayed == 1 && currentAppState -> fcAttempts >= 0 && currentAppState -> pileDeck -> head -> faceCardAttempts == currentAppState -> fcAttempts) || (currentAppState -> whoPlayed == 2 && currentAppState -> fcAttempts >= 0 && currentAppState -> pileDeck -> head -> faceCardAttempts != currentAppState -> fcAttempts)){
                        nextAppState.frames = 0;
                        nextAppState.state = 1;
                    } else {
                        nextAppState.frames = 0;
                        nextAppState.state = 0;
                    }
                }
            }
            break;
        }
        case 6: // Player Wins Game
        {
            freeAppState(&nextAppState);
            break;
        }
        case 7: // Opponent Wins Game
        {
            freeAppState(&nextAppState);
            break;
        }
    }
    return nextAppState;
}

static int shouldSlap(AppState *currentAppState) {
    Deck *cardPile = currentAppState -> pileDeck;
    if (cardPile -> size > 0) {
        Card *card = cardPile -> head;
        // Tens (1 Card)
        if (card -> value == 10) {
            return 1;
        }
        if (cardPile -> size > 1) {
            Card *secondCard = card -> next;
            // Tens (2 Cards)
            if (card -> value + secondCard -> value == 10) {
                return 1;
            }
            // Marriages
            if (card -> value == 12 && secondCard -> value == 13) {
                return 1;
            }
            if (card -> value == 13 && secondCard -> value == 12) {
                return 1;
            }
            // Doubles
            if (card -> value == secondCard -> value) {
                return 1;
            }
            if (cardPile -> size > 2) {
                Card *thirdCard = secondCard -> next;
                // Sandwiches
                if (thirdCard -> value == card -> value) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

static int opponentSlapped(AppState *currentAppState) {
    int accuracy = 75;
    int missRate = 10;
    int frames = 50;
    int difficulty = currentAppState -> opponent -> difficulty;
    if (difficulty == 2) {
        frames = 40;
    } else if (difficulty == 3) {
        accuracy = 85;
        missRate = 5;
    } else {
        frames = 30;
        accuracy = 90;
        missRate = 0;
    }
    int hit = randint(0, 100);
    if (currentAppState -> shouldSlap && hit < accuracy) {
        return frames;
    } else if (!currentAppState -> shouldSlap && hit < missRate) {
        return frames;
    }
    return -1;
}

void freeAppState(AppState* appState) {
    free(appState -> opponent);
    free(appState -> hiddenCard);
    freeDeck(appState -> playerDeck);
    freeDeck(appState -> opponentDeck);
    freeDeck(appState -> pileDeck);
}

static void freeDeck(Deck *deck) {
    Card *curr = deck -> head;
    while (curr != NULL) {
        Card *temp = curr -> next;
        free(curr);
        curr = temp;
    }
    free(deck -> cardBack);
    free(deck);
}

static Card* popTopDeck(Deck *deck) {
    if (deck -> size == 0) {
        return NULL;
    }
    Card *ret = deck -> head;
    deck -> head = deck -> head -> next;
    deck -> size--;
    ret -> next = NULL;
    return ret;
}

static void pushTopDeck(Deck *deck, Card *card) {
    if (card != NULL) {
        card -> next = NULL;
        if (deck -> size == 0) {
            deck -> head = card;
        } else {
            card -> next = deck -> head;
            deck -> head = card;
        }
        deck -> size++;
    }
}

static void pushBotDeck(Deck *deck, Card *card) {
    if (card != NULL) {
        Card *curr = deck -> head;
        if (curr == NULL) {
            deck -> head = card;
        } else {
            while (curr -> next != NULL) {
                curr = curr -> next;
            }
            curr -> next = card;
        }
        deck -> size++;
    }
}

static void combineDecks(Deck *mainDeck, Deck* toCombine) {
    pushBotDeck(mainDeck, toCombine -> head);
    mainDeck -> size += (toCombine -> size - 1);
    toCombine -> size = 0;
    toCombine -> head = NULL;
}

int equals(Card *one, Card *two) {
    if (one -> value == two -> value && one -> suit == two -> suit) {
        return 1;
    }
    return 0;
}
