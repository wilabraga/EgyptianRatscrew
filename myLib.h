#include "gba.h"

#define CURSOR 0
#define PLAYERCARDBACK 1
#define OPPONENTCARDBACK 2
#define HIDDENCARDBACK 3
#define PLAYERSLAP 4
#define OPPENENTSLAP 5
#define CARDSHADOW(SUIT, VALUE) (5 + (SUIT) * 13 + (VALUE))

#define CARDXCENTER (HEIGHT/2 - 10)
#define CARDYCENTER (WIDTH/2 - 5)

extern volatile OamEntry shadow[128];

void setUpSprites(void);
void setSprites(void);
void hideSprites(void);
volatile OamEntry* getSprite(int x);

typedef struct Cursor Cursor;
typedef struct Opponent Opponent;
typedef struct CardBack CardBack;
typedef struct Card Card;
typedef struct Deck Deck;
