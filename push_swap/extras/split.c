/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:02:42 by xlourenc          #+#    #+#             */
/*   Updated: 2024/12/06 18:54:35 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "/Users/xaviermonteiro/Desktop/42/PROJECTS/push_swap/push_swap.h"


static int count_words(char *s, char c) 
{
    int count = 0;
    bool inside_word = false;

    while (*s) 
    {
        if (*s != c && !inside_word) 
        {
            inside_word = true;
            count++; // Found a new word
        } 
        else if (*s == c) 
        {
            inside_word = false; // Leaving a word, enter delimiter area
        }
        s++;
    }
    return count;
}

static char *get_next_word(char *s, char c, int *cursor) 
{
    int len = 0, i = 0;
    char *next_word;

    // Skip delimiters
    while (s[*cursor] == c && s[*cursor])
        (*cursor)++;
    
    // Find the length of the next word
    while (s[*cursor + len] != c && s[*cursor + len])
        len++;

    // Allocate memory for the next word
    next_word = malloc((len + 1) * sizeof(char)); 
    if (!next_word)
        return NULL;

    // Copy the word into next_word
    while (i < len)
        next_word[i++] = s[(*cursor)++];

    next_word[i] = '\0'; // Null-terminate the string
    return next_word;
}

char **split(char *s, char c) 
{
    int words_count = count_words(s, c);
    char **result_array;
    int i = 0, cursor = 0;

    if (words_count == 0)
        return NULL;

    // Allocate memory for result array (one more for NULL terminator)
    result_array = malloc((words_count + 1) * sizeof(char *));
    if (!result_array)
        return NULL;

    // Extract words and populate the array
    while (i < words_count) 
    {
        result_array[i] = get_next_word(s, c, &cursor);
        if (!result_array[i]) 
        {
            // Handle memory deallocation in case of failure
            while (--i >= 0)
                free(result_array[i]);
            free(result_array);
            return NULL;
        }
        i++;
    }
    result_array[i] = NULL; // Null-terminate the result array

    return result_array;
}

/* int main() 
{
    char *test_string = "hello,world,this,is,a,test";
    char delimiter = ',';
    
    char **result = split(test_string, delimiter);

    if (!result) 
    {
        printf("Error: Unable to split the string.\n");
        return 1;
    }

    printf("Split string results:\n");
    for (int i = 0; result[i]; i++)
    {
        printf("[%d]: %s\n", i, result[i]);
    }

    for (int i = 0; result[i]; i++)
        free(result[i]);
    free(result);

    return 0;
}



 static int count_words(char *str, char del)
{
    int i;
    int inside_word;
    int word_count;

    word_count = 0;
    inside_word = 0;
    i = 0;
    while(str[i])
    {
    while(str[i] == del && inside_word == 1)
    {
        i++;
        inside_word = 0;
    }
    while(str[i] != del && inside_word != 1)
    {
        i++;
        inside_word = 1;
        word_count++;
    }
    i++;
    }
    return(word_count);
}

static char *get_next_word(char *str, char del)
{   
    int i;
    int len;
    char *word_result;
    static int cursor;

    if(!cursor)
        cursor = 0;
    len = 0;
    i = 0;
    while(str[cursor] == del)
        cursor++;
    while(str[cursor+len] != del)
           len++;

        word_result = malloc(sizeof(char) * len + 1);
    while(i < len)
        {
            word_result[i] = str[cursor];
            i++;
            cursor++;
        }
    word_result[i] = '\0';
    return(word_result);
}


char **split(char *str, char del)
{
    char **result;
    int i;
    int word_count;

    i = 0;
    word_count = count_words(str,del);

    if(word_count == 0)
        return(NULL);
    
    result = malloc(sizeof(char *) * word_count + 1);
        if(!result)
            return(NULL);
    while(i < word_count )
        {
            result[i] = get_next_word(str, del);
            if(!result[i])
            {
                while(i >= 0)
                    free(result[i--]);
                free(result);
            }
            i++;
        }
        return(result);
} */
/*  int main(void) TESTES FOR SPLIT ALL
{   char *str = "    hello my friend   petrenko o ";
    int i = 0;
    char **result;

    result = split(str, ' ');
    while(result[i])
    {
        printf("nbr :%d   word :%s\n",i,result[i]);
        i++;
    }
    while(i >= 0)
            free(result[i--]);
    free(result);

    return(0);


}  */
/* int main(void)  TEST FOR GET_NEXT_WORD
{
    char *str = "hello my friend     d";
    char *word;

    word = get_next_word(str,' ', 8);
    printf("string :%s\n word :%s\n,",str, word);

    free(word);
} */



/*
    TEST FOR COUNT_WORDS
 int main(void)
{
    int words = 0;
    char *str = "      hello my friend     ";

    words = count_words(str, ' ');
    printf("string: %s\nword counter: %d\n", str,words);

} 
*/;
