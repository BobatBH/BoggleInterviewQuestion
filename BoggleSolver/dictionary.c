
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

const char* const dictionaryFileName = "dictionary.txt";

static char* data = NULL;
static long  dataSize = 0;

char** dictionary = NULL;
long   numDictionaryEntries = 0;

//==================
// support

static void displayTableError(void) {
    printf("Could not create dictionary table\n");
}
static void displayDictionaryError(void) {
    printf("Could not create a dictionary from '%s'\n", dictionaryFileName);
}

//==================
// destruction

static void destroyBuffer(void) {
    if (data != NULL) {
        free(data);
        data = NULL;
    }
    dataSize = 0;
}

static void destroyTable(void) {
    if (dictionary != NULL) {
        free(dictionary);
        dictionary = NULL;
    }
    numDictionaryEntries = 0;
}

void destroyDictionary(void) {
    destroyTable();
    destroyBuffer();
}

//==================
// creation

static char* extractNumEntries(const char* const buffer,
                               const long        size,
                               long* const       destVariable) {
    if (   (buffer == NULL)
        || (size <= 0)
        || (destVariable == NULL)) {
        // nothing to do
        return NULL;
    }

    char numberBuffer[1024];
    long numberIndex = 0;

    long counter = 0;
    const char* ptr = buffer;
    do {
        char c = *ptr++;
        if (c == 0x0A) {
            break;
        }
        numberBuffer[numberIndex++] = c;
    } while (counter < size);
    numberBuffer[numberIndex] = 0;

    *destVariable = atol(numberBuffer);
    return (char*)ptr;
}

static bool createEntryTable(char* const  buffer,
                             const size_t size) {
    if (   (buffer == NULL)
        || (size <= 0)) {
        // nothing to do
        return false;
    }

    char* bufferPtr = extractNumEntries(buffer, size, &numDictionaryEntries);

    dictionary = (char**)malloc(numDictionaryEntries * sizeof(char*));
    if (dictionary == NULL) {
        return false;
    }

    char** tablePtr = dictionary;
    *tablePtr++ = bufferPtr;

    // null terminate the entries while we're here
    const size_t adjustedSize = size - (bufferPtr - buffer);
    for (size_t i = 0; i < adjustedSize; i++) {
        char c = *bufferPtr;
        if (c == 0x0A) {
            *bufferPtr = 0;
            bufferPtr++;
            *tablePtr++ = bufferPtr;
        } else {
            bufferPtr++;
        }
    }

    return true;
}

static bool readDictionary(const char* const fileName) {
    if (   (fileName == NULL)
        || (strlen(fileName) == 0)) {
        return false;
    }

    FILE* file = fopen(fileName, "rb");
    if (file == NULL) {
        return false;
    }

    fseek(file, 0, SEEK_END);
    dataSize = ftell(file);
    if (dataSize == -1) {
        (void)fclose(file);
        return false;
    }

    data = (char*)malloc(dataSize * sizeof(char));
    if (data == NULL) {
        (void)fclose(file);
        return false;
    }

    rewind(file);
    const size_t result = fread(data, 1, dataSize, file);
    if (result != dataSize) {
        destroyDictionary();
        (void)fclose(file);
    }
    (void)fclose(file);
    return true;
}

bool createDictionary(void) {
    if (readDictionary(dictionaryFileName) == false) {
        displayDictionaryError();
        return false;
    }

    if (createEntryTable(data, dataSize) == false) {
        destroyDictionary();
        displayTableError();
        return false;
    }

    printf("dictionary created with %ld entries\n", numDictionaryEntries);
    return true;
}
