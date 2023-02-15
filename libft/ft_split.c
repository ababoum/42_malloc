/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:14:29 by mababou           #+#    #+#             */
/*   Updated: 2022/04/13 20:28:07 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_words(char const *s, char c)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] && s[i] != c)
			nb++;
		i++;
	}
	return (nb);
}

static int	strlen_sep(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*strdup_sep(char const *s, char c)
{
	char	*output;
	int		i;

	i = 0;
	output = malloc(strlen_sep(s, c) + 1);
	if (!output)
		return (0);
	while (s[i] && s[i] != c)
	{
		output[i] = s[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

static void	free_prec(char **tab, int w)
{
	int	i;

	i = 0;
	while (i < w)
		free(tab[i++]);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		w;
	int		i;

	tab = malloc(sizeof(char *) * (1 + nb_words(s, c)));
	if (!tab)
		return (0);
	w = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] && s[i] != c)
		{
			tab[w++] = strdup_sep(s + i, c);
			if (!tab[w - 1])
			{
				free_prec(tab, w - 1);
				free(tab);
				return (0);
			}
		}
		i++;
	}
	tab[w] = 0;
	return (tab);
}
