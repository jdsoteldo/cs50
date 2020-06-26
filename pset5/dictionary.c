// Implements a dictionary's functionality
#include <strings.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;


// Number of buckets in hash table
const unsigned int N = 65536;

int word_count;

char dictionary_word[LENGTH + 1];

// Hash table
node *table[N];


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    unsigned int word_pos = hash(word);

    node *cursor = table[word_pos];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    int index = 0 ;
    for (int i = 0 ; word[i] != '\0' ; i++)
    {
        index += tolower(word[i]) ;
    }
    return index % N ;
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // open the file
    FILE *file = fopen(dictionary, "r");
    // check if file is null
    if (!file)
    {
        fprintf(stderr, "File does not exist.\n");
        return false;
    }

    char word[LENGTH + 1];

    word_count = 0;

    while (fscanf(file, "%s", dictionary_word) != EOF)
    {
        // allocate memory for the new node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }

        strcpy(new_node->word, dictionary_word);
        int hashed = hash(dictionary_word);

        if (table[hashed] == NULL)
        {
            table[hashed] = new_node;
            new_node->next = NULL;
        }
        else
        {
            new_node->next = table[hashed];
            table[hashed] = new_node->next;
            free(new_node);
        }
        word_count++;
    }
    fclose(file);
    return true;
}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    //just return the word count, easy piesey.
    return word_count;
}


// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
