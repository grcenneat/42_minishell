/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:51:05 by hjung             #+#    #+#             */
/*   Updated: 2021/01/03 23:07:27 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_write(char *str)
{
	int len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

void	prompt_msg(void)
{
	ft_putstr_fd("MINISHELL$ ", 1);
}

char	*get_cmd(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		    break;
        i++;
	}
	if (i > 0)
		return (ft_strndup(str, i));
	return (ft_strdup(""));
}

/*
** 환경변수와 shell의 실제 path를 초기화하고 prompt 대기
*/
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	char *line;
	char **lines;
	char init_str[20] = {"minishell$ "};
	char *cmd;
	char *path_cmd;
	int state;
	pid_t pid;
    t_minishell minishell;

	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
    init_env(&minishell, envp);

    g_name = argv[0];
	while (1)
    {
        prompt_msg();
        if(!read_line(&minishell))
            continue;
        while (ft_write(init_str) && (get_next_line(0, &line) > 0))
        {
            // | ; > " '
            // remove ' ' before string to parse command without option
            cmd = get_cmd(line);
            if (!strcmp(cmd, "exit"))
                exit(0);
            pid = fork();
            if (pid == 0)
            {
                path_cmd = ft_strjoin("/bin/", cmd);
                lines = ft_split(line, ' ');
                if (execve(path_cmd, lines, envp) == -1)
                {
                    ft_write("bash: command not found: ");
                    ft_write(cmd);
                    ft_write("\n");
                }
                free(cmd);
                free(path_cmd);
                free(lines);
                free(line);
                exit(0);
            }
            else if (pid > 0)
            {
                waitpid(pid, &state, 0);
                free(cmd);
                free(line);
            }
            else if (pid == -1)
            {
                //printf("%s\n", strerror(errno));
                ft_write(strerror(errno));
                ft_write("\n");
                exit(1);
            }
        }
    }
	return (0);
}