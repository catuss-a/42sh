/*
** main.c for 42sh in /u/all/serraj_y/rendu/c/proj/42sh/struct
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Tue Dec  7 16:27:30 2010 younes serraj
** Last update Sun Dec 19 22:55:44 2010 younes serraj
*/

#include <stdlib.h>
#include "my.h"
#include "config.h"
#include "shell.h"
#include "system.h"

static void		print_menu_help()
{
  my_putstr("Usage: ./42sh\n");
  my_putstr("\t--help: display this menu\n");
}

int			main(int argc, char **argv)
{
  t_config		*conf;

  if (argc == 2 && !my_strcmp(argv[1], "--help"))
    {
      print_menu_help();
      return (EXIT_SUCCESS);
    }
  conf = get_config();
  my_memset(conf, 0, sizeof(t_config));
  init_config(conf);
  conf->shell_pgid = getpid();
  tcgetattr(STDIN_FILENO, &conf->tmodes);
  signal_init();
  shell(conf);
  save_history(conf);
  free_config(conf);
  return (EXIT_SUCCESS);
}
