
#include "../includes/libft.h"

int	main()
{
	char *str = "qwert";
	char *str2 = "qwert";
	ft_printf("%s", ft_strlcat(str, str2, 10));
	return (0);
}