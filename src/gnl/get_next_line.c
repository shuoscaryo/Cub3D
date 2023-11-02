#include "get_next_line.h"

void _bzero(void *s, int n)
{
	char *aux = s;
	while (n--)
		*aux++ = 0;
}

int str_len(char *s)
{
	int i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char *strjoin(char *s1, char *s2)
{
	char *new_str;
	int i = 0;
	int j = 0;

	new_str = malloc(str_len(s1) + str_len(s2) + 1);
	if (!new_str)
		return (NULL);
	while (s1 && s1[i])
		new_str[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		new_str[j++] = s2[i++];
	new_str[j] = 0;
	return (new_str);
}

void free_str(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}

int has_enter(char *str)
{
	int i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char *cut_line(char **str)
{
	int i = 0;
	char *new_str;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	new_str = malloc(i + 2);
	if (!new_str)
		return (NULL);
	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
	{
		new_str[i] = (*str)[i];
		i++;
	}
	new_str[i] = '\n';
	new_str[i + 1] = 0;
	char *aux = *str;
	*str = strjoin(*str + i + 1, NULL);
	free(aux);
	return (new_str);
}

char *get_next_line(int fd)
{
	static char end = 0;
	static char *str = NULL;
	char buffer[BUFFER_SIZE + 1];
	int	rd;

	//check if BUFFERSIZE is valid or EOF/error happened in previous call
	if (end || BUFFER_SIZE <= 0)
		return (NULL);
	
	//read from fd until \n or EOF
	_bzero(buffer, BUFFER_SIZE + 1);
	while ( (rd = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		char *aux = strjoin(str, buffer);
		if (!aux)
			return (free_str(&str), end = 1, NULL);
		if (str)
			free(str);
		str = aux;
		if (has_enter(str) >= 0)
			break;
		_bzero(buffer, BUFFER_SIZE + 1);
	}

	//check if error happened return and end gnl
	if (rd < 0)
		return (free_str(&str), end = 1, NULL);

	//check if is last line
	if (has_enter(str) == -1)
	{
		end = 1;

		//check if line read is empty and return NULL if true
		if (str_len(str) == 0)
			return (free_str(&str), NULL);

		//return line read and set str to NULL
		char *aux = str;
		str = NULL;
		return (aux);
	}
	//if not last line cut line and return it
	char *aux = cut_line(&str);
	if (!aux)
		return (free_str(&str), end = 1, NULL);
	return (aux);
}
