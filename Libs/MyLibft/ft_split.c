/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:51:54 by juan-anm          #+#    #+#             */
/*   Updated: 2023/08/06 09:44:06 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strdupli(const char *s1, char cut);
static int		ft_cntwrds(char const *s, char c);
static char		**ft_splipri(char **split, char const *s, char c);
static void		*ft_freesp(char **m);

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = ft_calloc((ft_cntwrds(s, c) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	if (ft_cntwrds(s, c) != 0)
	{
		if (ft_splipri(split, s, c) == NULL)
			return (NULL);
	}
	else
		split[0] = NULL;
	return (split);
}

static char	**ft_splipri(char **split, char const *s, char c)
{
	size_t	i;
	int		j;
	int		words;

	words = 1;
	i = 0;
	j = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == (unsigned char)c)
			words = 1;
		else if (words == 1 && s[i] != (unsigned char)c)
		{
			split[j] = ft_strdupli(&s[i], c);
			if (split[j] == NULL)
				return (ft_freesp(split));
			words = 0;
			j++;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

static int	ft_cntwrds(char const *s, char c)
{
	int	i;
	int	contl;
	int	contw;

	i = 0;
	contw = 0;
	contl = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
			contl++;
		if (s[i] == c && contl > 0)
		{
			contw++;
			contl = 0;
		}
		i++;
	}
	if (contl > 0)
		contw++;
	return (contw);
}

static	char	*ft_strdupli(const char *s1, char cut)
{
	int			i;
	int			j;
	const char	*str;
	char		*dupstr;

	str = s1;
	i = 0;
	j = 0;
	while (str[i] != cut && str[i] != 0)
		i++;
	dupstr = malloc(i * sizeof(char) + 1);
	if (!dupstr)
	{
		return (NULL);
	}
	while (j < i)
	{
		dupstr[j] = str[j];
		j++;
	}
	dupstr[j] = 0;
	return (dupstr);
}

static void	*ft_freesp(char **m)
{
	int	i;

	i = 0;
	while (m[i] != NULL)
	{
		free(m[i]);
		i++;
	}
	free(m);
	return (NULL);
}
