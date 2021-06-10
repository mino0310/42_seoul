#include <unistd.h>


static void ft_union(const char *s1, const char *s2)
{
	unsigned int check[255];
	unsigned int i;

	i = 0;
	while (i < 255)
		check[i++] = 0;
	
	i = 0;
	while (s1[i]){
		if (check[s1[i]] == 0) {
			write(1, &s1[i], 1);
			check[s1[i]] = 1;
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (check[s2[i]] == 0) {
			write(1, &s2[i], 1);
			check[s2[i]] = 1;
		}
		i++;
	}
}




int main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_union(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return 0;
}