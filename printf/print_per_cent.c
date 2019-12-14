#include "header.h"

char *print_per_cent(t_list_flags flags)
{
    char	*string;
	int		size;

	string = ft_strdup("%");
	size = ft_strlen(string);
	if (flags.sign.active)
		apply_spaces(&string, flags.sign, size, 0);
	else if (flags.cero.active)
		string = apply_ceros(flags.cero, string);
	else if (flags.minimum.active)
		apply_spaces(&string, flags.minimum, size, 1);
	return (string);
}