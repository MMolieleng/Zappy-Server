/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoliele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 10:12:07 by mmoliele          #+#    #+#             */
/*   Updated: 2017/09/05 10:22:55 by mmoliele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void	init(char **argv)
{
	printf("%s\n", argv[1]);
}

void	usage()
{
	printf("<./server> <PORT>\n");
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		init(argv);
	else
		usage();
	return (0);
}
