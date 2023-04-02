/*
 * Exported with nin10kit v1.7
 * Invocation command was nin10kit --mode=sprites --bpp=4 --for_bitmap --transparent=FF0000 sprites cursor.png cardback.png playerslap.png opponentslap.png card1.png card2.png card3.png card4.png card5.png card6.png card7.png card8.png card9.png card10.png card11.png card12.png card13.png card14.png card15.png card16.png card17.png card18.png card19.png card20.png card21.png card22.png card23.png card24.png card25.png card26.png card27.png card28.png card29.png card30.png card31.png card32.png card33.png card34.png card35.png card36.png card37.png card38.png card39.png card40.png card41.png card42.png card43.png card44.png card45.png card46.png card47.png card48.png card49.png card50.png card51.png card52.png 
 * Time-stamp: Sunday 04/07/2019, 20:41:54
 * 
 * Image Information
 * -----------------
 * cursor.png 16@16
 * cardback.png 16@32
 * playerslap.png 16@16
 * opponentslap.png 16@16
 * card1.png 16@32
 * card2.png 16@32
 * card3.png 16@32
 * card4.png 16@32
 * card5.png 16@32
 * card6.png 16@32
 * card7.png 16@32
 * card8.png 16@32
 * card9.png 16@32
 * card10.png 16@32
 * card11.png 16@32
 * card12.png 16@32
 * card13.png 16@32
 * card14.png 16@32
 * card15.png 16@32
 * card16.png 16@32
 * card17.png 16@32
 * card18.png 16@32
 * card19.png 16@32
 * card20.png 16@32
 * card21.png 16@32
 * card22.png 16@32
 * card23.png 16@32
 * card24.png 16@32
 * card25.png 16@32
 * card26.png 16@32
 * card27.png 16@32
 * card28.png 16@32
 * card29.png 16@32
 * card30.png 16@32
 * card31.png 16@32
 * card32.png 16@32
 * card33.png 16@32
 * card34.png 16@32
 * card35.png 16@32
 * card36.png 16@32
 * card37.png 16@32
 * card38.png 16@32
 * card39.png 16@32
 * card40.png 16@32
 * card41.png 16@32
 * card42.png 16@32
 * card43.png 16@32
 * card44.png 16@32
 * card45.png 16@32
 * card46.png 16@32
 * card47.png 16@32
 * card48.png 16@32
 * card49.png 16@32
 * card50.png 16@32
 * card51.png 16@32
 * card52.png 16@32
 * Transparent color: (255, 0, 0)
 * 
 * All bug reports / feature requests are to be filed here https://github.com/TricksterGuy/nin10kit/issues
 */

#ifndef SPRITES_H
#define SPRITES_H

#define SPRITES_PALETTE_TYPE (0 << 13)
#define SPRITES_DIMENSION_TYPE (1 << 6)

extern const unsigned short sprites_palette[256];
#define SPRITES_PALETTE_SIZE 512
#define SPRITES_PALETTE_LENGTH 256

extern const unsigned short sprites[6976];
#define SPRITES_SIZE 13952
#define SPRITES_LENGTH 6976

#define CARDBACK_PALETTE_ID (0 << 12)
#define CARDBACK_SPRITE_SHAPE (2 << 14)
#define CARDBACK_SPRITE_SIZE (2 << 14)
#define CARDBACK_ID 512

#define CARD19_PALETTE_ID (0 << 12)
#define CARD19_SPRITE_SHAPE (2 << 14)
#define CARD19_SPRITE_SIZE (2 << 14)
#define CARD19_ID 520

#define CARD25_PALETTE_ID (0 << 12)
#define CARD25_SPRITE_SHAPE (2 << 14)
#define CARD25_SPRITE_SIZE (2 << 14)
#define CARD25_ID 528

#define CARD20_PALETTE_ID (0 << 12)
#define CARD20_SPRITE_SHAPE (2 << 14)
#define CARD20_SPRITE_SIZE (2 << 14)
#define CARD20_ID 536

#define CARD21_PALETTE_ID (0 << 12)
#define CARD21_SPRITE_SHAPE (2 << 14)
#define CARD21_SPRITE_SIZE (2 << 14)
#define CARD21_ID 544

#define CARD22_PALETTE_ID (0 << 12)
#define CARD22_SPRITE_SHAPE (2 << 14)
#define CARD22_SPRITE_SIZE (2 << 14)
#define CARD22_ID 552

#define CARD23_PALETTE_ID (0 << 12)
#define CARD23_SPRITE_SHAPE (2 << 14)
#define CARD23_SPRITE_SIZE (2 << 14)
#define CARD23_ID 560

#define CARD24_PALETTE_ID (0 << 12)
#define CARD24_SPRITE_SHAPE (2 << 14)
#define CARD24_SPRITE_SIZE (2 << 14)
#define CARD24_ID 568

#define CARD26_PALETTE_ID (0 << 12)
#define CARD26_SPRITE_SHAPE (2 << 14)
#define CARD26_SPRITE_SIZE (2 << 14)
#define CARD26_ID 576

#define CARD27_PALETTE_ID (0 << 12)
#define CARD27_SPRITE_SHAPE (2 << 14)
#define CARD27_SPRITE_SIZE (2 << 14)
#define CARD27_ID 584

#define CARD28_PALETTE_ID (0 << 12)
#define CARD28_SPRITE_SHAPE (2 << 14)
#define CARD28_SPRITE_SIZE (2 << 14)
#define CARD28_ID 592

#define CARD29_PALETTE_ID (0 << 12)
#define CARD29_SPRITE_SHAPE (2 << 14)
#define CARD29_SPRITE_SIZE (2 << 14)
#define CARD29_ID 600

#define CARD30_PALETTE_ID (0 << 12)
#define CARD30_SPRITE_SHAPE (2 << 14)
#define CARD30_SPRITE_SIZE (2 << 14)
#define CARD30_ID 608

#define CARD31_PALETTE_ID (0 << 12)
#define CARD31_SPRITE_SHAPE (2 << 14)
#define CARD31_SPRITE_SIZE (2 << 14)
#define CARD31_ID 616

#define CARD32_PALETTE_ID (0 << 12)
#define CARD32_SPRITE_SHAPE (2 << 14)
#define CARD32_SPRITE_SIZE (2 << 14)
#define CARD32_ID 624

#define CARD33_PALETTE_ID (0 << 12)
#define CARD33_SPRITE_SHAPE (2 << 14)
#define CARD33_SPRITE_SIZE (2 << 14)
#define CARD33_ID 632

#define CARD34_PALETTE_ID (0 << 12)
#define CARD34_SPRITE_SHAPE (2 << 14)
#define CARD34_SPRITE_SIZE (2 << 14)
#define CARD34_ID 640

#define CARD35_PALETTE_ID (0 << 12)
#define CARD35_SPRITE_SHAPE (2 << 14)
#define CARD35_SPRITE_SIZE (2 << 14)
#define CARD35_ID 648

#define CARD36_PALETTE_ID (0 << 12)
#define CARD36_SPRITE_SHAPE (2 << 14)
#define CARD36_SPRITE_SIZE (2 << 14)
#define CARD36_ID 656

#define CARD37_PALETTE_ID (0 << 12)
#define CARD37_SPRITE_SHAPE (2 << 14)
#define CARD37_SPRITE_SIZE (2 << 14)
#define CARD37_ID 664

#define CARD38_PALETTE_ID (0 << 12)
#define CARD38_SPRITE_SHAPE (2 << 14)
#define CARD38_SPRITE_SIZE (2 << 14)
#define CARD38_ID 672

#define CARD39_PALETTE_ID (0 << 12)
#define CARD39_SPRITE_SHAPE (2 << 14)
#define CARD39_SPRITE_SIZE (2 << 14)
#define CARD39_ID 680

#define CARD17_PALETTE_ID (0 << 12)
#define CARD17_SPRITE_SHAPE (2 << 14)
#define CARD17_SPRITE_SIZE (2 << 14)
#define CARD17_ID 688

#define CARD16_PALETTE_ID (0 << 12)
#define CARD16_SPRITE_SHAPE (2 << 14)
#define CARD16_SPRITE_SIZE (2 << 14)
#define CARD16_ID 696

#define CARD15_PALETTE_ID (0 << 12)
#define CARD15_SPRITE_SHAPE (2 << 14)
#define CARD15_SPRITE_SIZE (2 << 14)
#define CARD15_ID 704

#define CARD14_PALETTE_ID (0 << 12)
#define CARD14_SPRITE_SHAPE (2 << 14)
#define CARD14_SPRITE_SIZE (2 << 14)
#define CARD14_ID 712

#define CARD18_PALETTE_ID (0 << 12)
#define CARD18_SPRITE_SHAPE (2 << 14)
#define CARD18_SPRITE_SIZE (2 << 14)
#define CARD18_ID 720

#define PLAYERSLAP_PALETTE_ID (0 << 12)
#define PLAYERSLAP_SPRITE_SHAPE (0 << 14)
#define PLAYERSLAP_SPRITE_SIZE (1 << 14)
#define PLAYERSLAP_ID 728

#define CARD52_PALETTE_ID (0 << 12)
#define CARD52_SPRITE_SHAPE (2 << 14)
#define CARD52_SPRITE_SIZE (2 << 14)
#define CARD52_ID 732

#define CARD40_PALETTE_ID (0 << 12)
#define CARD40_SPRITE_SHAPE (2 << 14)
#define CARD40_SPRITE_SIZE (2 << 14)
#define CARD40_ID 740

#define CARD41_PALETTE_ID (0 << 12)
#define CARD41_SPRITE_SHAPE (2 << 14)
#define CARD41_SPRITE_SIZE (2 << 14)
#define CARD41_ID 748

#define CARD42_PALETTE_ID (0 << 12)
#define CARD42_SPRITE_SHAPE (2 << 14)
#define CARD42_SPRITE_SIZE (2 << 14)
#define CARD42_ID 756

#define CARD43_PALETTE_ID (0 << 12)
#define CARD43_SPRITE_SHAPE (2 << 14)
#define CARD43_SPRITE_SIZE (2 << 14)
#define CARD43_ID 764

#define CARD44_PALETTE_ID (0 << 12)
#define CARD44_SPRITE_SHAPE (2 << 14)
#define CARD44_SPRITE_SIZE (2 << 14)
#define CARD44_ID 772

#define CARD45_PALETTE_ID (0 << 12)
#define CARD45_SPRITE_SHAPE (2 << 14)
#define CARD45_SPRITE_SIZE (2 << 14)
#define CARD45_ID 780

#define CARD46_PALETTE_ID (0 << 12)
#define CARD46_SPRITE_SHAPE (2 << 14)
#define CARD46_SPRITE_SIZE (2 << 14)
#define CARD46_ID 788

#define CARD47_PALETTE_ID (0 << 12)
#define CARD47_SPRITE_SHAPE (2 << 14)
#define CARD47_SPRITE_SIZE (2 << 14)
#define CARD47_ID 796

#define CARD48_PALETTE_ID (0 << 12)
#define CARD48_SPRITE_SHAPE (2 << 14)
#define CARD48_SPRITE_SIZE (2 << 14)
#define CARD48_ID 804

#define CARD49_PALETTE_ID (0 << 12)
#define CARD49_SPRITE_SHAPE (2 << 14)
#define CARD49_SPRITE_SIZE (2 << 14)
#define CARD49_ID 812

#define CARD50_PALETTE_ID (0 << 12)
#define CARD50_SPRITE_SHAPE (2 << 14)
#define CARD50_SPRITE_SIZE (2 << 14)
#define CARD50_ID 820

#define CARD51_PALETTE_ID (0 << 12)
#define CARD51_SPRITE_SHAPE (2 << 14)
#define CARD51_SPRITE_SIZE (2 << 14)
#define CARD51_ID 828

#define OPPONENTSLAP_PALETTE_ID (0 << 12)
#define OPPONENTSLAP_SPRITE_SHAPE (0 << 14)
#define OPPONENTSLAP_SPRITE_SIZE (1 << 14)
#define OPPONENTSLAP_ID 836

#define CARD1_PALETTE_ID (0 << 12)
#define CARD1_SPRITE_SHAPE (2 << 14)
#define CARD1_SPRITE_SIZE (2 << 14)
#define CARD1_ID 840

#define CARD2_PALETTE_ID (0 << 12)
#define CARD2_SPRITE_SHAPE (2 << 14)
#define CARD2_SPRITE_SIZE (2 << 14)
#define CARD2_ID 848

#define CARD3_PALETTE_ID (0 << 12)
#define CARD3_SPRITE_SHAPE (2 << 14)
#define CARD3_SPRITE_SIZE (2 << 14)
#define CARD3_ID 856

#define CARD4_PALETTE_ID (0 << 12)
#define CARD4_SPRITE_SHAPE (2 << 14)
#define CARD4_SPRITE_SIZE (2 << 14)
#define CARD4_ID 864

#define CARD5_PALETTE_ID (0 << 12)
#define CARD5_SPRITE_SHAPE (2 << 14)
#define CARD5_SPRITE_SIZE (2 << 14)
#define CARD5_ID 872

#define CARD6_PALETTE_ID (0 << 12)
#define CARD6_SPRITE_SHAPE (2 << 14)
#define CARD6_SPRITE_SIZE (2 << 14)
#define CARD6_ID 880

#define CARD7_PALETTE_ID (0 << 12)
#define CARD7_SPRITE_SHAPE (2 << 14)
#define CARD7_SPRITE_SIZE (2 << 14)
#define CARD7_ID 888

#define CARD8_PALETTE_ID (0 << 12)
#define CARD8_SPRITE_SHAPE (2 << 14)
#define CARD8_SPRITE_SIZE (2 << 14)
#define CARD8_ID 896

#define CARD9_PALETTE_ID (0 << 12)
#define CARD9_SPRITE_SHAPE (2 << 14)
#define CARD9_SPRITE_SIZE (2 << 14)
#define CARD9_ID 904

#define CARD10_PALETTE_ID (0 << 12)
#define CARD10_SPRITE_SHAPE (2 << 14)
#define CARD10_SPRITE_SIZE (2 << 14)
#define CARD10_ID 912

#define CARD11_PALETTE_ID (0 << 12)
#define CARD11_SPRITE_SHAPE (2 << 14)
#define CARD11_SPRITE_SIZE (2 << 14)
#define CARD11_ID 920

#define CARD12_PALETTE_ID (0 << 12)
#define CARD12_SPRITE_SHAPE (2 << 14)
#define CARD12_SPRITE_SIZE (2 << 14)
#define CARD12_ID 928

#define CURSOR_PALETTE_ID (0 << 12)
#define CURSOR_SPRITE_SHAPE (0 << 14)
#define CURSOR_SPRITE_SIZE (1 << 14)
#define CURSOR_ID 936

#define CARD13_PALETTE_ID (0 << 12)
#define CARD13_SPRITE_SHAPE (2 << 14)
#define CARD13_SPRITE_SIZE (2 << 14)
#define CARD13_ID 940

#endif

