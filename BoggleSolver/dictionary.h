
#ifndef dictionary_h
#define dictionary_h

#include <stdbool.h>

#define MIN_WORD_LENGTH     3
#define MAX_WORD_LENGTH     16

extern char** dictionary;
extern long   numDictionaryEntries;

extern bool createDictionary(void);
extern void destroyDictionary(void);

#endif
