/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoliele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 12:53:29 by mmoliele          #+#    #+#             */
/*   Updated: 2017/09/05 14:58:20 by mmoliele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void	warning(char *message)
{
	printf("\n%s\n", message);
}

void	fatal_error(char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}
