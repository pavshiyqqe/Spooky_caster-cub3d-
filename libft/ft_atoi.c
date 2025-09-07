/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:39:33 by abergman          #+#    #+#             */
/*   Updated: 2024/06/02 19:02:27 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_result(int n, int sign)
{
	if (sign == 0)
		return (n);
	else
		return (n * sign);
}

int	ft_atoi(const char *nptr)
{
	int				sign;
	int				result;
	unsigned int	index;

	index = 0;
	sign = 0;
	result = 0;
	while ((nptr[index] > 8 && nptr[index] <= 13) || nptr[index] == 32)
		index++;
	while ((nptr[index] == 43 || nptr[index] == 45) && (sign == 0))
	{
		if (nptr[index] == 45)
			sign = -1;
		else if (nptr[index] == 43)
			sign = 1;
		index++;
	}
	while (nptr[index] >= 48 && nptr[index] <= 57)
	{
		result = result * 10 + (nptr[index] - '0');
		index++;
	}
	return (ft_result(result, sign));
}
