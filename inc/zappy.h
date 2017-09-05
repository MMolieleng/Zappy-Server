/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoliele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 10:16:11 by mmoliele          #+#    #+#             */
/*   Updated: 2017/09/05 14:57:35 by mmoliele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_H
# define ZAPPY_H
# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <errno.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <sys/fcntl.h>

void	init(char **argv);

void	warning(char *message);
void	fatal_error(char *message);
#endif
