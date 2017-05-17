#ifndef TRIE_H
#define TRIE_H
struct NODE {
        char letter;
        int isWord;
        struct NODE *child, *nextSibling;
};

struct NODE* mkNode(char letter, int isWord);
int seekSibling(struct NODE** parent, char letter);
int seekChild(struct NODE** parent, char letter);
int checkWord(struct NODE** trie, char* word);
#endif
