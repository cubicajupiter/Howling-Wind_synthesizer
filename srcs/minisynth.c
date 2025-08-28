#include "minisynth.h"

//you can use any library or tool for the actual playing of the sound, 
//BUT THE SOUND GENERATION (PULSE MODULATION) SYNTHESIS HAS TO BE DONE ENTIRELY YOURSELF

int	main(int ac, char **arv)
{
	int					fd;
	static t_song		song;

	fd = 0;
	if (ac == 2)
	{
		fd = open(ac[1]);
		init_song(&song); // no need maybe
		parse_file(fd, &song);
		play(&song);
		close(fd);
	}
	else
		write(1, "Run with one argument:	./minisynth [path/to/descriptor_file]\n", 50);
	return (0);
}

int	init_song(t_song song)
{
	
}
