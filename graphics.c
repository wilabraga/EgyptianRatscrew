#include "images/sprites.h"
#include "myLib.h"

volatile OamEntry shadow[128];

void setUpSprites(void) {
    DMA[3].src = sprites_palette;
    DMA[3].dst = SPRITEPAL;
    DMA[3].cnt = SPRITES_PALETTE_LENGTH | DMA_ON;
    DMA[3].src = sprites;
    DMA[3].dst = &CHARBLOCKBASE[5];
    DMA[3].cnt = SPRITES_LENGTH | DMA_ON;
    for(int i = 0; i < MAXSPRITES; i++) {
        shadow[i].attr0 = ATTR0_HIDE;
    }
}

void setSprites(void) {
    DMA[3].src = &shadow;
    DMA[3].dst = OAMMEM;
    DMA[3].cnt = MAXSPRITES * 4 | DMA_ON;
}

void hideSprites(void) {
    for(int i = 0; i < MAXSPRITES; i++) {
       shadow[i].attr0 = ATTR0_HIDE;
    }
}

volatile OamEntry* getSprite(int x) {
	return shadow + x;
}
