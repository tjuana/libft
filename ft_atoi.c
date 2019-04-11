/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nw_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:28:30 by tjuana            #+#    #+#             */
/*   Updated: 2019/04/11 14:25:21 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_return(unsigned long long res, int otr, const char *str)
{
	int	c;

	c = 0;
	while (!ft_isdigit(*str))
		str++;
	while (ft_isdigit(str[c]))
		c++;
	if (c > 19)
		return (otr == -1 ? 0 : -1);
	if (res > 9223372036854775807)
		return (otr == -1 ? 0 : -1);
	else
		return (res * otr);
}

int			ft_atoi(const char *str)
{
	unsigned long long	res;
	int					otr;
	int					ind;

	otr = 1;
	ind = 0;
	res = 0;
	while ((str[ind] == 32) || (str[ind] >= 9 && str[ind] <= 13))
		ind++;
	if (str[ind] == '-')
		otr = -1;
	if (str[ind] == '+' || str[ind] == '-')
		ind++;
	while (str[ind] != '\0' && ft_isdigit(str[ind]))
	{
		res = res * 10 + (str[ind] - 48);
		ind++;
	}
	return (check_return(res, otr, str));
}
int    main(void)
{
    int i1 = 5;
    int i2 = 2;
    int i3 = 0;
    int i4 = -32;
    int i5 = -84;
    int i6 = 45;
    int i7 = 44;
    char *str1 = "5";
    char *str2 = "2 087 561";
    char *str3 = "0";
    char *str4 = "-32";
    char *str5 = "-84    2    59 5 17";
    char *str6 = "45dd78z22-4d";
    char *str7 = "44-5";
    
    if (ft_atoi(str1) == i1)
    {
        if (ft_atoi(str2) == i2)
        {
            if (ft_atoi(str3) == i3)
            {
                if (ft_atoi(str4) == i4)
                {
                    if (ft_atoi(str5) == i5)
                    {
                        if (ft_atoi(str6) == i6)
                        {
                            if (ft_atoi(str7) == i7)
                            {
                                printf("OKAY! =D\n");
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("FAILED!\n");
}
