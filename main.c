#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

extern char *getKomplementti(char *);

extern int muunnaLuku(int, int);
extern int getLuku(char *);

int main(int argc, char *argv[]) {


    char *bits = argv[1];
    char *komplementti = getKomplementti(bits);
//    printf("%s\n", bits);
//    printf("%s", komplementti);

    int luku = getLuku(komplementti);
    printf("%d", luku);
    return 0;
}


char *getKomplementti(char *bits) {

    int i = 0;
    size_t len = strlen(bits);
    char string[200] = {};
    char *t = malloc(len + 1);
    for (i = 0; i < len; ++i) {
        char c = bits[i];

        if (c == '1') {
            string[i] = '0';
        } else {
            string[i] = '1';
        }
    }
    string[++i] = '\0';

    strcpy(t, string);
    return t;
}


int getEtumerkki(char *s) {
    int i = (int) s[0];
    return i;
}


int getLuku(char *s) {
    int etumerkki = getEtumerkki(s);
    int luku = 0;
    size_t i = 0;
    size_t slen = strlen(s);
    int currentLuku = 0;
    int kerroin = 0;


    for (i = slen; i > 1; --i) {
        kerroin = kerroin * 2;
        currentLuku = (int) s[i];
        if (currentLuku == 1) {
            luku += kerroin;
        }

    }
    luku = muunnaLuku(luku, etumerkki);
    return luku;
}

int muunnaLuku(int luku, int etumerkki) {
    if (etumerkki == 0) {
        if (luku >= 0) {
            return luku;
        } else {
            return luku - (luku * 2);
        }
    } else {
        if (luku == 1) {
            return luku;
        } else {
            return luku + (luku * 2);
        }
    }
}