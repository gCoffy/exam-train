/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_epur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoffy <gauthier.coffy@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 10:31:05 by gcoffy            #+#    #+#             */
/*   Updated: 2026/10/01 11:36:48 by gcoffy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_sep(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\0')
		return (1);
	return (0);
}

int	is_first(char *str, int i)
{
	if (i < 0)
		return (1);
	while (is_sep(str[i - 1]) && i > 0)
		i--;
	if (!is_sep(str[i - 1]))
		return (0);
	return (1);
}

void	put_word(char *str, int i)
{
	int first = is_first(str, i - 1);

	while (!is_sep(str[i]))
		ft_putchar(str[i++]);
	if (first == 0)
		ft_putchar(' ');
}

void	rev_epur(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	while (i >= 0)
	{
		if (!is_sep(str[i]))
		{
			while (!is_sep(str[i - 1]))
				i--;
			put_word(str, i);
		}
		i--;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	rev_epur(argv[1]);
	ft_putchar('\n');
	return (0);
}
