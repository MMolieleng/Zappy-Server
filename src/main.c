/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoliele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 10:12:07 by mmoliele          #+#    #+#             */
/*   Updated: 2017/09/05 13:05:07 by mmoliele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

/*
** @params *clients - array of clients sockers
** @params master_sock master socket
** @params port char port number passed
*/

void	init_address_ip(int *clients, int master_sock, char *port)
{
	struct sockaddr_in address;

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(9090);
	if (bind(master_sock, (struct sockaddr *)&address, sizeof(address)) > 0)
		fatal_error("Socket Binding Failed");
	printf("Listining on port %d ", 9090);
	if (listen(master_sock, 3) < 0)
		fatal_error("Error Listening");
	printf("Done working...");
	//manage_connections(clients, master_sock, address);
}

void	init(char **argv)
{
	int	master_sock;
	int	clients[30];
	int	opt;
	int	i;

	i = 0;
	opt = 1;
	while (i < 30)
	{
		clients[i] = 0;
		i++;
	}
	if ((master_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0)
		fatal_error("Scoket Failed");
	if (setsockopt(master_sock, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,
				sizeof(int)) < 0)
		fatal_error("Set Sock Options Failed");
	init_address_ip(clients, master_sock, argv[1]);
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
