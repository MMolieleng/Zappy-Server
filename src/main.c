/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoliele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 10:12:07 by mmoliele          #+#    #+#             */
/*   Updated: 2017/09/05 14:58:28 by mmoliele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

#define MAX_CLIENTS 30

void	update_maxsd(int *max_sd, fd_set *readfds, int *master, int *clients)
{
	int	i;
	int	sd;

	i = 0;
	sd = 0;
	FD_ZERO(readfds);
	FD_SET(*master, readfds);
	*max_sd = *master;
	while (i < MAX_CLIENTS)
	{
		sd = clients[i];
		if (sd > 0)
			FD_SET(sd, readfds);
		if (sd > *max_sd)
			*max_sd = sd;
		i++;
	}

}

/*
** Accept new connection
*/
void	new_conn(int *master, struct sockaddr_in *addr, int *clients)
{
	int	new_socket;
	int	addrlen;
	int	i;

	i = 0;
	addrlen = 0;
	if ((new_socket = accept(*master, (struct sockaddr*)addr, 
				(socklen_t *)&addrlen)) < 0)
		fatal_error("\n->Failed to accept new connection\n");
	printf("\nNew Connection ,sockfd %d\n", new_socket);
	if (send(new_socket, "Hello!", ft_strlen("Hello!"), 0) != ft_strlen("Hello!"))
		warning("\n->Message sending failed\n");
	printf("Welcome Message sent successfully");
	while (i < MAX_CLIENTS)
	{
		if (clients[i] == 0)
		{
			clients[i] = new_socket;
			printf("\n*New client added successfully at %d\n", i);
			break;
		}
		i++;
	}
}

/*
 ** Manage Connections
 */
void	manage_connections(int *clients, int master_sock, 
		struct sockaddr_in addr)
{
	int		max_sd;
	int		activity;
	fd_set	readfds;

	max_sd = 0;
	while (1)
	{
		update_maxsd(&max_sd, &readfds, &master_sock, clients);
		activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
		if ((activity < 0) && (errorno != EINTR))
			printf("Select Error");
		if (FD_ISSET(master_sock, &readfds))
			new_conn(&master_sock, &addr, clients);
	}
}

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
	manage_connections(clients, master_sock, address);
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
