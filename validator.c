/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 20:25:28 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/18 18:32:53 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_get_stdin(char *buf, int *tot_char)
{
	int		ret;
	int		total_size;
	char	*final;
	char	tmp[100000];
	int		filedesc;

	filedesc = open(buf, O_RDONLY);
	total_size = 0;
	while ((ret = read(filedesc, buf, 1000)) > 0)
	{
		free(final);
		buf[ret] = '\0';
		total_size += ret;
		final = (char *)malloc(sizeof(char) * total_size);
		final = ft_strcat(tmp, buf);
	}
	*tot_char = total_size;
	return (final);
}

int		check_if_valid(char *final, int *tot_char)
{
	int tet_p_ln_d_pnd[5];

	tet_p_ln_d_pnd[0] = 0;
	tet_p_ln_d_pnd[1] = 0;
	tet_p_ln_d_pnd[3] = 0;
	tet_p_ln_d_pnd[4] = 0;
	while (tet_p_ln_d_pnd[1] < *tot_char)
	{
		tet_p_ln_d_pnd[2] = 0;
		while (tet_p_ln_d_pnd[2] <= 4 && tet_p_ln_d_pnd[1] < *tot_char)
		{
			if (final[tet_p_ln_d_pnd[1]] == '.')
				tet_p_ln_d_pnd[3]++;
			else if (final[tet_p_ln_d_pnd[1]] == '#')
				tet_p_ln_d_pnd[4]++;
			else if (final[tet_p_ln_d_pnd[1]] == '\n')
				tet_p_ln_d_pnd[2]++;
			tet_p_ln_d_pnd[1]++;
		}
		if (tet_p_ln_d_pnd[3] % 12 != 0 || tet_p_ln_d_pnd[4] % 4 != 0)
			return (0);
		tet_p_ln_d_pnd[0]++;
	}
	return (tet_p_ln_d_pnd[0]);
}

int		check_shape(char *shape_str)
{
	int i;
	int shared_sides;

	i = 0;
	shared_sides = 0;
	while (i < 19)
	{
		if (shape_str[i] == '#')
		{
			if (i + 1 <= 18 && shape_str[i + 1] == '#')
				shared_sides++;
			if (i - 1 >= 0 && shape_str[i - 1] == '#')
				shared_sides++;
			if (i + 5 <= 18 && shape_str[i + 5] == '#')
				shared_sides++;
			if (i - 5 >= 0 && shape_str[i - 5] == '#')
				shared_sides++;
		}
		i++;
	}
	return (shared_sides);
}

int		check_newlines(char *final)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (final[i] != '\0')
	{
		if (final[i] == '\n')
		{
			count++;
		}
		i++;
	}
	return (count);
}

char	**turn_into_2d(char *final, int *tot_char)
{
	char	**two_d_arr;
	int		i;
	int		j;
	int		tet_nubr_npie;

	j = 0;
	i = 0;
	tet_nubr_npie = check_if_valid(final, tot_char);
	if (tet_nubr_npie == 0 || (check_newlines(final) + 1) % tet_nubr_npie != 0)
		return (0);
	two_d_arr = (char**)malloc((tet_nubr_npie + 1) * sizeof(char*));
	two_d_arr[tet_nubr_npie] = 0;
	while (j < tet_nubr_npie)
	{
		two_d_arr[j] = ft_strsub(final, i, 21);
		two_d_arr[j++][20] = '\0';
		i += 21;
	}
	j = -1;
	while (++j < tet_nubr_npie)
	{
		if (check_shape(two_d_arr[j]) != 6 && check_shape(two_d_arr[j]) != 8)
			return (0);
	}
	return (two_d_arr);
}
