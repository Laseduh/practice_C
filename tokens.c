#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * tokenize- splits a string and returns an array of each
 * token/word of the string
 * @text - string to tokenize
 * @delim - delimeter(s) - can handle multiple delimeters
 * @count - buffer to hold number of tokens returned by
 * function
 *
 * Return: array of strings/tokens. Free allocared memory after use!
 */

char **tokenize(char *text, const char *delim, int *count)
{
	char **words;
	int j;
	int i;
	int count_delim = 1;

	i = 0;
	while (text[i])
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (text[i] == delim[0])
			count_delim++;
		}
		i++;
	}

	/*Allocate memory based on tokens in view*/

	words = malloc(sizeof(char *) * count_delim);

	/*Verify malloc was successful*/
	if (words == NULL)
	{
		printf("Malloc Failed!\n");
		exit(99);
	}

	/*Tokenize string and store in reserved array*/

	words[0] = strtok(text, delim);

	for (i = 1; i < count_delim; i++)
	{
		words[i] = strtok(NULL, delim);
	}
	
	/*Count tokens stored*/
	i = 0;
	count_delim = 0;
	while (words[i] != NULL);
	{
		count_delim++;
		i++;
	}

	/*Return every update*/
	*count = count_delim - 1;
	return (words);
}


int main(void)
{
	char text[] = "One two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen";
	char **words;
	const char *delim = " ";
	int i = 0;
	int count = 0;

	/*Call to tokens*/
	words = tokenize(text, delim, &count);

	/*Print all tokens/words acquired*/
	for (i = 0; i < count; i++)
	{
		printf("argument %i: %s\n", i, words[i]);
	}

	/*Free allocated memories*/
	free(words);
	return (0);
}
