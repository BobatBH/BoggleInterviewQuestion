/*
    Problem:
    Given a grid of NxM letters and a word dictionary, create a list of all the
    words that can be constructed from the letters of sequentially adjacent
    locations, where "adjacent locations" are those horizontally and vertically
    neighboring (not diagonally). Words must be at least three letters long and
    cannot use the same location more than once per word.

    Notes:
    - A solution() function has been created for you. Store the words in the
    foundWords array. The list will be displayed automatically.

    - A populated 4x4 grid is provided, but the solution you create should
    accommodate a grid with an arbitrary width and height (both >=3);
    i.e. your code should not assume the grid is 4x4. If you need to make any
    assumptions, you can assume the grid is at least 3x3.

    - The word dictionary is provided for you. However, the use of it is up to
    you. It is an array of lower-case Strings.

    You are provided with the following variables/information:

        minWordLength
        maxWordLength

        wordDictionary.wordList: [String]

    Data:
    The 4x4 grid to use is:
        t i l s
        h n a v
        g i m e
        n e p o
*/

import Foundation

var foundWords: [String] = []

//==== insert your code between here... ====


func solution() {
}


//==== ...and here =========================

do {
    let wordDictionary = try WordDictionary()
    if wordDictionary.wordList.count > 0 {
        solution()
        print(foundWords)
    }
} catch {
    print("Could not create the word dictionary")
}
