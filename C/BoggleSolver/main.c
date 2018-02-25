/*
    Problem:
    Given a grid of NxM letters and a dictionary, display a list of all the
    words that can be constructed from the letters of sequentially adjacent
    locations, where "adjacent locations" are those horizontally and vertically
    neighboring (not diagonally). Words must be at least three letters long and
    cannot use the same location more than once per word.

    Notes:
    - The word list does not need to be stored or sorted. You can display them
    as soon as each word is found.

    - A populated 4x4 grid is provided, but the solution you create should
    accommodate a grid with an arbitrary width and height (both >=3);
    i.e. your code should not assume the grid is 4x4. If you need to make any
    assumptions, you can assume the grid is at least 3x3.

    - The dictionary is provided for you. However, the use of it is up to you.
    It is a pointer to a table of entries. Each entry is lower-case and null-
    terminated (char*).

    You are provided with the following variables/information:

        MIN_WORD_LENGTH
        MAX_WORD_LENGTH

        char** dictionary

        long   numDictionaryEntries

    - For brevity, the use of globals is acceptable.

    Data:
    The 4x4 grid to use is:
        t i l s
        h n a v
        g i m e
        n e p o
*/

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include "dictionary.h"

//==== insert your code between here... ====


void solution(void) {
}


//==== ...and here =========================

int main(int argc, const char * argv[]) {
    if (createDictionary() == false) {
        return 0;
    }
    solution();
    destroyDictionary();
    return 0;
}
