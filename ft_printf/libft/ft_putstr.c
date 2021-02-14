#include "libft.h"

int		ft_putstr(char *s)
{
	if (!(s))
		return (0);
	return (write(1, s, ft_strlen(s)));

}