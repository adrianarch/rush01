/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserrano <jserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:21:19 by jserrano          #+#    #+#             */
/*   Updated: 2020/02/15 13:13:23 by jserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_1(int *num, int i, int *val) //Pone un 4 en el lado más cercano
{
	int n;

	if (*(num + i) == 1 && i < 4)
		n = i;
	else if (*(num + i) == 1 && i > 3 && i < 8)
		n = i + 12;
	else if (*(num + i) == 1 && i > 7 && i < 12)
		n = (i - 8) * 4;
	else if (*(num + i) == 1 && i > 11)
		n = (i - 11) * 4 - 1;
	*(val + n) = 4;
}

void	check_4(int *num, int i, int *val) //Pone 1, 2 y 3 en toda la fila. El 4 no lo pone porque de eso se encarga el check_1
{
	int n;

	if (*(num + i) == 4 && i < 4)
	{
		n = i;
		*(val + n) = 1;
		*(val + n + 4) = 2;
		*(val + n + 8) = 3;
	}
	else if (*(num + i) == 4 && i > 3 && i < 8)
	{
		n = i + 12;
		*(val + n) = 1;
		*(val + n - 4) = 2;
		*(val + n - 8) = 3;
	}
	else if (*(num + i) == 4 && i > 7 && i < 12)
	{
		n = (i - 8) * 4;
		*(val + n) = 1;
		*(val + n + 1) = 2;
		*(val + n + 2) = 3;
	}
	else if (*(num + i) == 4 && i > 11)
	{
		n = (i - 11) * 4 - 1;
		*(val + n) = 1;
		*(val + n - 1) = 2;
		*(val + n - 2) = 3;
	}
}

void	check_3_2(int *num, int i, int *val) //Pone un 4 en la posicion correcta en el caso de que haya un 3 en la nuestra y un 2 en la contraria.
{
	int n;

	if (*(num + i) == 3 && *(num + i + 4) == 2 && i < 4)
		n = i + 8;
	else if (*(num + i) == 3 && *(num + i - 4) == 2 && 3 < i && i < 8)
		n = i - 8;
	else if (*(num + i) == 3 && *(num + i + 4) == 2 && 7 < i && i < 12)
		n = (i - 8) * 4 + 2;
	else if (*(num + i) == 3 && *(num + i - 4) == 2 && i > 11)
		n = (i - 11) * 4 - 3;
	*(val + n) = 4;
}

void	check_1_2(int *num, int i, int *val) //Pone un 3 en la ultima.
{
	int n;

	if (*(num + i) == 1 && *(num + i + 4) == 2 && i < 4)
		n = i + 12;
	else if (*(num + i) == 1 && *(num + i - 4) == 2 && 3 < i && i < 8)
		n = i - 12;
	else if (*(num + i) == 1 && *(num + i + 4) == 2 && 7 < i && i < 12)
		n = (i - 8) * 4 + 3;
	else if (*(num + i) == 1 && *(num + i - 4) == 2 && i > 11)
		n = (i - 11) * 4 - 1;
	*(val + n) = 3;
}

void	check_3_2_last_3(int *num, int i, int *val) //Pone un 4 en la posicion correcta en el caso de que haya un 3 en la nuestra y un 2 en la contraria.
{
	int n;

	if (*(num + i) == 3 && *(num + i + 4) == 2 && i < 4 && *(val + (i - 11) * 4 - 1) == 3)
	{
		n = i;
		*(val + n) = 1;
		*(val + n + 4) = 2;
	}
	else if (*(num + i) == 3 && *(num + i - 4) == 2 && 3 < i && i < 8 && *(val + i - 8) == 3)
		{
		n = i - 8;
		*(val + n) = 1;
		*(val + n - 4) = 2;
		}
	else if (*(num + i) == 3 && *(num + i + 4) == 2 && 7 < i && i < 12 && *(val + (i - 8) * 4) == 3)
		{
		n = (i - 8) * 4;
		*(val + n) = 1;
		*(val + n + 1) = 2;
		}
	else if (*(num + i) == 3 && *(num + i - 4) == 2 && i > 11 && *(val + (i - 11) * 4 - 1) == 3)
		{
		n = (i - 11) * 4 - 1;
		*(val + n) = 1;
		*(val + n - 1) = 2;
		}
}

int		check_repeat(int *val) //Busca repetidos en todas las filas y columnas comprobando que suman 10.
{
	if (10 == (*(val) + *(val + 1) + *(val + 2) + *(val + 3)))
		return (1);
	else if (10 == (*(val + 4) + *(val + 5) + *(val + 6) + *(val + 7)))
		return (1);
	else if (10 == (*(val + 8) + *(val + 9) + *(val + 10) + *(val + 11)))
		return (1);
	else if (10 == (*(val + 12) + *(val + 13) + *(val + 14) + *(val + 15)))
		return (1);
	else if (10 == (*(val) + *(val + 4) + *(val + 8) + *(val + 12)))
		return (1);
	else if (10 == (*(val + 1) + *(val + 5) + *(val + 9) + *(val + 13)))
		return (1);
	else if (10 == (*(val + 2) + *(val + 6) + *(val + 10) + *(val + 14)))
		return (1);
	else if (10 == (*(val + 3) + *(val + 7) + *(val + 11) + *(val + 15)))
		return (1);
	else
		return (0);
}

void	check_fill()
