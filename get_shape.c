/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:25:35 by kmckee            #+#    #+#             */
/*   Updated: 2017/10/08 17:07:18 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**get_shape(char **two_d_arr, int tet_nubr_npie)
{
	int		**arr;
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	arr = (int**)malloc(sizeof(int*) * tet_nubr_npie);
	while (i < tet_nubr_npie)
	{
		arr[i] = (int *)malloc(sizeof(int) * 3);
		i++;
	}
	i = 0;
	j = 0;
	k = 1;
	l = 0;
	while (two_d_arr[i] != 0)
	{
		while (two_d_arr[i][j] != '#')
			j++;
		while (two_d_arr[i][j] != '\0')
		{
			if (two_d_arr[i][j] == '#')
			{
				j++;
				while (two_d_arr[i][j] != '#')
				{
					j++;
					k++;
				}
				arr[i][l] = k;
				k = 1;
				l++;
			}
			if (l == 3)
				j++;
		}
		i++;
		j = 0;
		l = 0;
	}
	return (arr);
}

/*int		***get_3d_arr(char **two_d_arr, int tet_nubr_npie)
{
	int***arr;
	int i;
	int j;

	arr = (int***)malloc(sizeof(int**) * tet_nubr_npie);
	i = 0;
	j = 0;
	while (tet_nubr_npie--)
	{
		arr[i] = (int**)malloc(sizeof(int*) * 5);
		while (j < 4)
		{
			arr[i][j] = (int*)malloc(sizeof(int) * 2);
			j++;
		}
		arr[i][4] = (int*)malloc(sizeof(int));
		j = 0;
		i++;
	}
	while (i--)
	{
		if (two_d_arr[i][0] == 1)
			one_first(arr, two_d_arr);
		else if (two_d_arr[i][0] == 3 || two_d_arr[i]

	}
	}*/



















