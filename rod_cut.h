#ifndef ROD_CUT_H
#define ROD_CUT_H

typedef struct {
    int length;
    int value;
} Piece;

int rod_cut(int rod_length, Piece pieces[], int n);

#endif

