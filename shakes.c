#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "scanner.h"
#include "shakes.h"
int
countTokens(char *fileName)
    {
    FILE *fp;
    int count = 0;
    char *token;
    //open file to read
    fp = fopen(fileName,"r");
    //error checking
    if (fp == 0)
        {
        fprintf(stderr,"file %s could not be opened for reading\n",fileName);
        exit(1);
        }
    //loop until end of file
    token = readToken(fp);
    while (!feof(fp))
        {
        //count each token
        ++count;
        free(token); //free up space allocated for token
        token = readToken(fp);
        }
    fclose(fp); //close file
    return count;
    }


void
storeArray(char *fileName,char **t)
    {
    //open file
    FILE *fp = fopen(fileName,"r");
    char *token;
    int count = 0;
    //error checking
    if (fp == 0)
        {
        fprintf(stderr,"file %s could not be opened for reading\n",fileName);
        exit(1);
        }
    token = readToken(fp);
    //while it is not the end of file store the tokens into t
    while (!feof(fp))
        {
        t[count] = token;
        ++count;
        token = readToken(fp);
        }

    //close file
    fclose(fp);
    return ;
    }

void
cleanToken(char *t)
    {
    int j = 0;
    for (int i = 0; i < strlen(t); ++i)
        {
        if (isalpha(t[i]))  //test t[i] to see if it is a letter
            {
            t[j++] = t[i];  //clean t[i] of all non-letter characters
            }
        }
    t[j] = '\0';
    return;
    }

void
cleanTokens(char **token,int length)
    {
    int count = 0;
    while(count < length)
        {
        cleanToken(token[count]); //employ cleanToken to clean all tokens stored in token
        ++count;
        }
    return;
    }

char
toLower(char ch)   //return lowercase version of ch
     {
     if (ch <= 'Z')  //this is true if ch is uppercase
        return ch + 'a' - 'A';
    else            //otherwise ch is lowercase, so return it
        return ch;
        }

char *
makeLower(char *string,int c)
    {
    for(int i = 0; string[i] != '\0'; i++)
        {
        string[i] = tolower(string[i]); //implements toLower on each ch in a string
        }
    return string;
    }

char **
makeLowercase(char **token,int length)
        {
        for(int i = 0; i < length; i++)
            {
            token[i] = makeLower(token[i],length); //implements makeLower on each string in token
            }
        return token;
        }

int
argumentsCount(char *arg,char **corpus,int length)
    {
    int counts = 0;
    for (int i = 0; i < length ; i++)
        {
        if (strcmp(corpus[i], arg) == 0) //true if a token is == to an arg
            {
            counts++; //counts number of times arg occurs in corpus
            }

        }
    return counts;
    }

void
numberOfInstances(char **args,char **corpus,int argcount,int length)
    {
    for(int i = 1; i < argcount; i++) 
        {
        int count = 0;
        count = argumentsCount(args[i],corpus,length); //implements argumentsCount on each argument after the program name
        printf("%s appears %d times\n",args[i],count); // prints the results of argumentCount
        }
    return;
    }
