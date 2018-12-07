/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:23:29 by jthierce          #+#    #+#             */
/*   Updated: 2018/11/26 18:23:54 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putstr_itoa(size_t n, size_t puis, int neg)
{
	int		i;

	i = 0;
	if (neg == -1)
	{
		ft_putchar('-');
		i++;
	}
	while (puis != 0)
	{
		ft_putchar((n / puis) + 48);
		n = n % puis;
		if (puis == 1)
			puis = 0;
		puis /= 10;
		i++;
	}
}

static int	ft_intisneg(int n, size_t *save_n)
{
	if (n < 0)
	{
		*save_n = (size_t)n * -1;
		return (-1);
	}
	return (1);
}

void		ft_putnbr(int n)
{
	size_t	puis;
	int		neg;
	size_t	save_n;

	save_n = n;
	puis = 1;
	neg = ft_intisneg(n, &save_n);
	if (n == -2147483648)
		save_n = 2147483648;
	while ((puis * 10) <= save_n)
		puis *= 10;
	ft_putstr_itoa(save_n, puis, neg);
}
