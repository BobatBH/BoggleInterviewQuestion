
#import <Foundation/Foundation.h>

#define MIN_WORD_LENGTH     3
#define MAX_WORD_LENGTH     16

@interface WordDictionary : NSObject
@property (nonatomic, readonly, nonnull) NSArray* wordList;
@end
