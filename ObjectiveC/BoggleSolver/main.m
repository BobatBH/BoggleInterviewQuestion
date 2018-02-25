/*
    Problem:
    Given a grid of NxM letters and a word dictionary, create a list of all the
    words that can be constructed from the letters of sequentially adjacent
    locations, where "adjacent locations" are those horizontally and vertically
    neighboring (not diagonally). Words must be at least three letters long and
    cannot use the same location more than once per word.

    Notes:
    - A Solution class has been created for you. Store the words in its
    foundWords property. The list will be displayed automatically.

    - A populated 4x4 grid is provided, but the solution you create should
    accommodate a grid with an arbitrary width and height (both >=3);
    i.e. your code should not assume the grid is 4x4. If you need to make any
    assumptions, you can assume the grid is at least 3x3.

    - The word dictionary is provided for you. However, the use of it is up to
    you. It is an NSArray of lower-case NSStrings.

    You are provided with the following variables/information:

        MIN_WORD_LENGTH
        MAX_WORD_LENGTH

        NSArray* wordDictionary.wordList

    Data:
    The 4x4 grid to use is:
        t i l s
        h n a v
        g i m e
        n e p o
*/

#import <Foundation/Foundation.h>
#import "WordDictionary.h"

WordDictionary* wordDictionary = nil;

//==== insert your code between here... ====


@interface Solution : NSObject
@property (nonatomic, strong) NSMutableArray* foundWords;
@end

@implementation Solution
@end


//==== ...and here =========================

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        wordDictionary = [[WordDictionary alloc] init];
        if (wordDictionary.wordList.count == 0) {
            return 0;
        }
        Solution* solution = [[Solution alloc] init];
        NSLog(@"%@", solution.foundWords);
    }
    return 0;
}
