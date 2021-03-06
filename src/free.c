#include "../lem_in.h"

void    freeroom(char **str)
{
    free(str[0]);
    free(str[1]);
    free(str[2]);
    free(str);
}

void    freelink(char **str)
{
    free(str[0]);
    free(str[1]);
    free(str);
}

void    freemain(char *file, t_valid *vals)
{
    free(file);
    free(vals);
}

int		popcomments(t_comments **head)
{
	t_comments		*next_node;

	next_node = NULL;
	if (head == NULL)
		return (-1);
	next_node = (*head)->next;
    free((*head)->command);
	free(*head);
	*head = next_node;
    return (0);
}

void     freecommands(t_comments **comments){
    while(*comments){
        popcomments(comments);
    }
}

int		poplinks(t_links **head)
{
	t_links		*next_node;

	next_node = NULL;
	if (*head == NULL)
		return (-1);
	next_node = (*head)->next;
    free((*head)->first);
    free((*head)->second);
	free(*head);
	*head = next_node;
    return (0);
}


void     freelinks(t_links **links){
    while(*links){
        poplinks(links);
    }
}

int		poplink(t_room *head)
{
	t_room		*next_node;

	next_node = NULL;
	if (head == NULL)
		return (-1);
	next_node = head->next;
	free(head);
	head = next_node;
    return (0);
}

int		pop(t_room **head)
{
	t_room		*next_node;

	next_node = NULL;
	if (*head == NULL)
		return (-1);
    // while ((*head)->links){
    //     poplink((*head)->links);
    // }
	next_node = (*head)->next;
    if ((*head)->name){
        free((*head)->name);
    }
    if ((*head)->links){
        free((*head)->links);
    }
    if (*head){
	    free(*head);
	    *head = next_node;
    }
    return (0);
}

void    freerooms(t_room **rooms)
{
    while(*rooms)
    {
        if (*rooms){
            pop(rooms);
        }
    }
    *rooms = NULL;
}
void	free_time(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}