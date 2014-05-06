#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "scanner.h"
#include "shakes.h"
/*******************************************************************************
 * cWords - a simple program that reads in a                                   *
 *           text file and searches the file for the                           *
 *           number of times a word appears within that file                   *
 *         - written by Cameron M. Brock   Febuary 2014                        *
 *         - uses scanner.c and scanner.h written by John C. Lusth             *
 *           all rights reserved for their respective owners.                  *
 *         - in general, the functions return what is implied by their names   *
 *         - all functions besides main occur in shakes.c                      *
 *         - all function prototypes occur in shakes.h                         *
 *                                                                             *
 *   Copyright (C) 2014  Cameron M Brock
 *  
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 * 
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *******************************************************************************/

int
main(int argc,char **argv)
    {
    char **tokens;
    int c = 0;
    // count number of raw tokens
    c = countTokens("shakespeare.txt");
    //allocate array tokens dynamically with a length of c
    tokens = (char **) malloc(sizeof(char *) * c);
    //error checking
    if (tokens == 0)
        {
        fprintf(stderr,"memory allocation failed\n");
        exit(1);
        }
    //store the input from the txt file in tokens
    storeArray("shakespeare.txt",tokens);
    //clean up the tokens removing all special characters and numbers
    cleanTokens(tokens,c);
    //force all tokens to lowercase
    makeLowercase(tokens,c);
    //display number of occurances of a word input as an argument
    numberOfInstances(argv,tokens,argc,c);
    //free up space allocated with malloc
    free(tokens);
    return 0;
    }
