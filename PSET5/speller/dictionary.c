// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 990000;

// Hash table
node *table[N];

int dictionarySize = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashValue = hash(word);
    node *n = table[hashValue];

    while(n != NULL)
    {
        if (strcasecmp(word, n -> word ) == 0)
        {
                return true;
        }

        n = n -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    long sum = 0;
    for (int i = 0; i < strlen(word) ;i++)
    {
        sum += tolower(word[i]);
    }

    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dictionaryPoiner = fopen(dictionary , "r");

    if (dictionary == NULL)
    {
        printf("Unable to open %s\n" , dictionary);
        return false;
    }

    char next_word[LENGTH + 1];

    while (fscanf(dictionaryPoiner, "%s" , next_word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n -> word , next_word);
       int hashValue = hash(next_word);

       n-> next = table[hashValue];
       table[hashValue] = n;
       dictionarySize++;
    }

    fclose(dictionaryPoiner);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dictionarySize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N ;i++)
    {
        node *n = table[i];

        while(n != NULL)
        {
            node *temp = n;
            n = n-> next;
            free(temp);
        }

        if (n == NULL && i == N - 1)
        {
                return true;
        }

    }

    return false;
}
