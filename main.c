#include "./includes/minishell.h"

int ft_write(char *str)
{
	int len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

// signal() 에 의해 SIGINT, SIGQUIT이 들어왔을 때 실행되는 함수
// 입력된 값이 SIGQUIT일 땐 아무것도 하지 않는다.
void sig_handle(int signo)
{
	if (signo == SIGINT)
		ft_write("\nbash-3.2$ ");
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

int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;
	char *line;
	char **lines;
	char init_str[20] = {"bash-3.2$ "};
	char *cmd;
	char *path_cmd;
	int state;
	pid_t pid;
//	int fd = open("test", O_RDONLY);

	signal(SIGINT, sig_handle);
	signal(SIGQUIT, sig_handle); 
	while (1)
    {
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