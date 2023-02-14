#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFSIZE 1024

/**
 * tokenize - tokenize a string
 *
 * Return: array of tokens.
 */
char **tokenize()
{
	char str[BUFFSIZE];
	char *token;
	char *s = " ";
	char **ret = NULL;
	int i = 0, j;

	if(fgets(str, BUFFSIZE, stdin) == NULL)
	{
		dprintf(STDERR_FILENO, "Error: fgets() failure\n");
		exit(EXIT_FAILURE);
	}
	if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
	token = strtok(str, s);
#if 0
	ret = malloc(sizeof(char *));
	if (!ret)
	{
		dprintf(2, "Error: malloc() failure\n");
		exit(EXIT_FAILURE);
	}
#endif
	while (token)
	{
		ret = realloc(ret, sizeof(char *) * (i + 1));
        if (ret == NULL)
        {
            dprintf(2, "Error: realloc() failure\n");
            exit(EXIT_FAILURE);
        }
		ret[i] = malloc(strlen(token) + 1);
		if (!(ret[i]))
		{
			dprintf(2, "Error: malloc() failure\n");
			exit(EXIT_FAILURE);
		}
		for (j = 0; token[j]; j++)
			(ret[i])[j] = token[j];
		token = strtok(NULL, s);
		i++;
		/*increase the size of the array*/
		ret = realloc(ret, (i + 1) * sizeof(char *));
		if (!ret)
		{
			dprintf(2, "Error: realloc() failure\n");
			exit(EXIT_FAILURE);
		}
	}

	ret[i] = NULL;
	return (ret);
}

/**
 * main - entry point
 *
 * Return: EXIT_SUCCESS.
*/
int main(void)
{
	char **arr = tokenize();
	int i;

	for (i = 0; arr[i]; i++)
	{
		if (arr[i + 1] == NULL)
		{
			printf("%s", arr[i]);
		}
		else
			puts(arr[i]);
	}
	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);

	exit(EXIT_SUCCESS);
}
