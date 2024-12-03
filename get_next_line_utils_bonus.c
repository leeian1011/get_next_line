/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:48:06 by ialee             #+#    #+#             */
/*   Updated: 2024/11/19 13:27:31 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strtonl(char *str)
{
	char	*result;
	size_t	len;

	len = 0;
	while (str[len] != '\n' && str[len])
		len++;
	if (str[len] == '\n')
		len++;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len--)
		result[len] = str[len];
	return (result);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*result;
	size_t	index;

	index = 0;
	result = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!result)
		return (NULL);
	while (*str1)
		result[index++] = *str1++;
	while (*str2)
		result[index++] = *str2++;
	result[index] = '\0';
	return (result);
}

char	*ft_strchrnl(char *str)
{
	if (!*str)
		return (NULL);
	while (*str)
		if (*str++ == '\n')
			return (--str);
	return (NULL);
}