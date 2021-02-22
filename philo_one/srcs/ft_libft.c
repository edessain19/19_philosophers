/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:29:15 by edessain          #+#    #+#             */
/*   Updated: 2021/02/19 12:54:33 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int		ft_isdigit(int c)
{
	if (c < '0' || '9' < c)
		return (0);
	return (1);
}

int    ft_atoi(const char *str)
{
    int                    i;
    int                    signe;
    unsigned long long    prev;
    unsigned long long    digit;

    i = 0;
    prev = 0;
    digit = 0;
    signe = 1;
    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
        || str[i] == '\v' || str[i] == '\f')
        i++;
    if (str[i] == '-' || str[i] == '+')
        signe = (str[i++] == '-') ? -1 : 1;
    while (str[i] > 47 && str[i] < 58)
    {
        digit = digit * 10 + (str[i++] - '0');
        if (digit < prev || digit >= 9223372036854775807)
            return ((signe == -1) ? 0 : -1);
        prev = digit;
    }
    return (digit * signe);
}

char	*ft_strdup(const char *s1)
{
	char	*new_s;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!(new_s = malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (NULL);
	while (s1 && *s1)
		new_s[i++] = *s1++;
	new_s[i] = '\0';
	return (new_s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dest;

	if (s2 == NULL || s1 == NULL)
		return (NULL);
	if (!(dest = malloc((ft_strlen((char*)s1) +
						ft_strlen((char*)s2)) * sizeof(char*))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin_free_all(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;
	if (s2 == NULL || s1 == NULL)
		return (NULL);
	if (!(dest = (char *)malloc((ft_strlen((char*)s1) +
		ft_strlen((char*)s2)) * sizeof(char*))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	free(s1);
	free(s2);
	return (dest);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;
	if (s2 == NULL || s1 == NULL)
		return (NULL);
	if (!(dest = malloc((ft_strlen((char*)s1) +
		ft_strlen((char*)s2)) * sizeof(char*))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	free(s1);
	return (dest);
}