/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:38:12 by juan-anm          #+#    #+#             */
/*   Updated: 2023/09/28 12:59:43 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strj;
	int		i;
	int		j;

	j = 0;
	i = 0;
	strj = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!strj)
		return (NULL);
	while (s1[i])
	{
		strj[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		strj[j] = s2[i];
		j++;
		i++;
	}
	strj[j] = 0;
	return (strj);
}

char	*ft_strjoin_free(char *storage, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!storage)
		return (ft_strdup(buffer));
	str = malloc(sizeof(char) * ((ft_strlen(storage) + ft_strlen(buffer)) + 1));
	if (!str)
		return (ft_freesp(&storage));
	i = -1;
	j = 0;
	while (storage[++i] != '\0')
		str[i] = storage[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[i] = '\0';
	free(storage);
	return (str);
}

char	*ft_strjoin_doublefree(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!str1)
		return (ft_strdup(str2));
	str = malloc(sizeof(char) * ((ft_strlen(str1) + ft_strlen(str2)) + 1));
	if (!str)
		return (ft_freesp(&str1));
	i = -1;
	j = 0;
	while (str1[++i] != '\0')
		str[i] = str1[i];
	while (str2[j] != '\0')
		str[i++] = str2[j++];
	str[i] = '\0';
	free(str1);
	free(str2);
	return (str);
}