#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "trie.h"

struct NODE* mkNode(char letter, int isWord) {
        struct NODE *n = (struct NODE*) malloc(sizeof(struct NODE));
        if (n == NULL) {
                // Error. Out of memory?
                errno = ENOMEM;
                perror("Out of memory");
                exit(errno);
        }
        n->letter = letter;
        n->isWord = isWord;
        n->nextSibling = NULL;
        n->child = NULL;
        return n;
}

/**
 * 0: Success
 * 1: Word not found among siblings
 */
int seekSibling(struct NODE** leftChild, char letter) {
        while (*leftChild != NULL) {
                if (letter == (*leftChild)->letter) {
                        return 0;
                }
                (*leftChild) = (*leftChild)->nextSibling;
        }
        return 1;
}

/**
 * 0: Success
 * 1: Word not found among immediate children
 */
int seekChild(struct NODE** parent, char letter) {
        *parent = (*parent)->child;
        return seekSibling(parent, letter);
}

/**
 * 0: Success
 * 1: Word not found
 */
int checkWord(struct NODE** trie, char* word) {
        // For letter in word
        while (1) {
                if (seekSibling(trie, *word))
                        // Letter not found
                        return 1;

                word++;
                if (*word == '\0')
                        break;

                *trie = (*trie)->child;
        }
        // All letters found. Is it a word?
        return 1 == (*trie)->isWord ? 0 : 1;
}
