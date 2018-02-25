
#import "WordDictionary.h"

NSString* const dictionaryFileName = @"dictionary.json";

@interface WordDictionary ()
@property (nonatomic, strong, nonnull) NSArray* words;
@end


@implementation WordDictionary

- (nullable instancetype)init {
    self = [super init];
    if (self == nil) return nil;
    self.words = [self createWordList];
    NSAssert(self.words != nil, @"the word array wasn't created");
    NSLog(@"word dictionary created with %lu entries", (unsigned long)self.words.count);
    return self;
}
- (nonnull NSArray*)createWordList {
    NSDictionary* jsonDictionary = [self loadJSON];
    if (jsonDictionary == nil) {
        return @[];
    }
    return jsonDictionary[@"words"];
}
- (nullable NSDictionary*)loadJSON {
    NSError* jsonError = nil;
    NSData* objectData = [NSData dataWithContentsOfFile:dictionaryFileName];
    return [NSJSONSerialization JSONObjectWithData:objectData
                                           options:NSJSONReadingMutableContainers
                                             error:&jsonError];
}

- (nonnull NSArray*)wordList {
    return self.words;
}

@end
