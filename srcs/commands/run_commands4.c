/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:38:43 by nwang             #+#    #+#             */
/*   Updated: 2018/04/02 21:34:37 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "papi.h"

void	google_dagoberto(void)
{
	system("say -v Juan Ay, Ay, Ay, Papi!");
	system("open https://www.google.com/search?q=dagoberto");
}

void	check_history(void)
{
	system("say -v Juan Dirty history, ay dios");
	system("sh srcs/commands/history");
}

void	quit(void)
{
	system("say -v Juan Adios, mi amigo");
	system("pkill pocketsphinx_continuous");
	exit(0);
}

void	butterhorn(void)
{
	system("say -v Juan BUTTTTERRRHOOOOORRRRRNNNNN!!!!!");
	system("open https://www.google.com/search?q=butterhorn&tbm=isch");
	system("play srcs/commands/butterhorn.mp3");
}

void	shrek(void)
{
	system("say -v Juan What are you doing, in my swamp!");
	system("open https://www.whatareyoudoinginmyswamp.com/");
}
