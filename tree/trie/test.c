#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "trie.h"

int main() {
        struct NODE *root = mkNode('a', 1);
        struct NODE *ar = mkNode('r', 0);
        struct NODE *are = mkNode('e', 1);
        struct NODE *ars = mkNode('s', 0);
        struct NODE *arse = mkNode('e', 1);
        struct NODE *iterator = NULL;

        root->child = ar;
        ar->child = are;
        are->nextSibling = ars;
        ars->child = arse;

        // Test basic struct
        assert(root->child->letter == ar->letter);
        assert(root->letter == 'a');
        assert(root->child->letter == 'r');
        assert(ar->child->letter == 'e');
        assert(ar->child->nextSibling->letter == 's');

        // Test seekSibling
        iterator = are;
        assert(0 == seekSibling(&iterator, 'e'));
        assert(iterator->letter == 'e');
        assert(0 == seekSibling(&iterator, 's'));
        assert(iterator->letter == 's');
        assert(1 == seekSibling(&iterator, 'X'));

        // Test seekChild 
        // First child
        iterator = ar;
        assert(0 == seekChild(&iterator, 'e'));
        assert(iterator->letter == 'e');
        // Secondary child
        iterator = ar;
        assert(0 == seekChild(&iterator, 's'));
        assert(iterator->letter == 's');
        // No such child
        iterator = ar;
        assert(1 == seekChild(&iterator, 'X'));

        // Test checkWord
        char* ars_s = "ars";
        iterator = root;
        assert(1 == checkWord(&iterator, ars_s));
        char* arse_s = "arse";
        iterator = root;
        assert(0 == checkWord(&iterator, arse_s));
        char* arsd_s = "arsd";
        iterator = root;
        assert(1 == checkWord(&iterator, arsd_s));

        free(root);
        free(ar);
        free(are);
        free(ars);
        free(arse);
        return 0;
}


