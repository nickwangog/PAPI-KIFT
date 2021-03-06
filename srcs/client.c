/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:57:00 by nwang             #+#    #+#             */
/*   Updated: 2018/04/02 23:09:07 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "papi.h"

int						establish_port(void)
{
	char				port_str[100];
	char				*ret_ptr;
	int					port;

	printf("Quiero un puerto, por favor: ");
	fgets(port_str, 100, stdin);
	port = strtol(port_str, &ret_ptr, 10);
	while (port == 0)
	{
		printf("Invalid input: %sInput as integer only try again: ", port_str);
		fgets(port_str, 100, stdin);
		port = strtol(port_str, &ret_ptr, 10);
	}
	while (port < 1024 || port > 65535)
	{
		printf("Invalid port #: %i\n", port);
		printf("Enter a port between 1024 and 65535: ");
		fgets(port_str, 100, stdin);
		port = strtol(port_str, &ret_ptr, 10);
	}
	printf("Muy Bien! Let's connect!\n");
	return (port);
}

void					kifte_client(int comm_fd)
{
	int					fd;
	int					fd2;
	char				send_str[100];
	char				recv_str[100];
	t_cmd				*cmd_d;

	cmd_d = initialize(&fd, &fd2);
	while (1)
	{
		parser(fd, cmd_d);
		cmd_d->quit == 1 ? quit_check(fd, cmd_d) : 0;
		if (cmd_d->cmdid > 0 && cmd_d->papi == 1)
		{
			bzero(send_str, 100);
			putcommand_insendstr(cmd_d->cmd, send_str);
			bzero(recv_str, 100);
			send(comm_fd, send_str, strlen(send_str), 0);
			recv(comm_fd, recv_str, 100, 0);
			commands(cmd_d->cmdid);
			ft_putstr_fd(cmd_d->cmd, fd2);
			write(fd2, "\n", 1);
			reset_papi(cmd_d);
		}
	}
	free(cmd_d);
}

int						main(void)
{
	int					comm_fd;
	struct sockaddr_in	info;
	int					port;
	int					success;
	pid_t				id2;

	comm_fd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&info, sizeof(info));
	info.sin_family = AF_INET;
	id2 = fork();
	if (id2 == 0)
		execvp("./listener", NULL);
	sleep(3);
	port = establish_port();
	info.sin_port = htons(port);
	inet_pton(AF_INET, "127.0.0.1", &(info.sin_addr));
	success = connect(comm_fd, (struct sockaddr*)&info, sizeof(info));
	if (success != 0)
		printf("Couldn't connect to server\n");
	kifte_client(comm_fd);
	return (0);
}
/*
** local: 127.0.0.1
** pi: 10.114.100.109
*/
