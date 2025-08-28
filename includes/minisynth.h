#ifndef MINISYNTH_H
# define MINISYNTH_H

# include <stdint.h>

# define ERROR		-1
# define INSTR_N	4
# define SAME		0
# define SINE		0
# define SAW		1
# define SQUARE		2
# define TRIANGLE	3

typedef struct s_song;
{
	int		tempo;
	int		track_n;
	int		*track_mode; //MALLOC'd!!!!!!!!! Remember to free once redundant
	int16_t	**sample_array;
}	t_song;

#endif
