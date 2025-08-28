#include "minisynth.h"

int	parse_file(int fd, t_song *song)
{
	char	*line;

	line = "init";
	while (line)
	{
		line = get_next_line(fd);
		if (line[0] == '#' || line[0] == '\n')
		{
			free(line);
			continue ;
		}
		if (!song->tempo)
			song->tempo = ft_atoi(line + 6);
		else if (!song->track_mode_n)
		{
			if (ft_strncmp(line, "track_mode", 6) == SAME)
			{
				free(line);
				if (get_track_data(line, song, fd))
					return (ERROR);
			}
		}
		else
		{
			get_notation(line, song);
		}
		free(line);
	}
	return 0;
}

int	get_track_data(line, song, fd)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = get_next_line(fd);
	get_track_n(line, song);
	song->track_mode = (int *) malloc(sizeof(int) * song->track_n);
	if (!song->track_mode)
		return (ERROR);
	while (j < song->track_n)
	{
		if (line[i] == 't')
		{
			song->track_mode[j] = TRIANGLE;
			i += 9;
		}
		else if (line[i] == 's')
		{
			if (line[i + 1] == 'i')
			{
				song->track_mode[j] = SINE;
				i += 5;
			}
			else if (line[i + 1] == 'a')
			{
				song->track_mode[j] = SAW;
				i += 4;
			}
			else if (line[i + 1] == 'q')
			{
				song->track_mode[j] = SQUARE;
				i += 7;
			}
			else if (line[i + 1] == 'n')
				i += 6;
		}
		else if (line[i] == 'k')
			i += 5;
		j++;
	}
	return 0;
}

void	get_track_n(char *line, t_song *song)
{
	int		comma_count;

	comma_count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma_count++;
	}
	song->track_n = comma_count + 1;
}

// 0 is silence
// + 32 768 is max amplitude1 ?
// - 32 767 is max amplitude2 ?
// Need TWO CHANNELS! How?
void	get_notation(char *line, t_song *song)
{
	static int	track_nbr;
	double		sample_scale;
	int			i;
	int			beat_n;

	track_nbr = line[0];
	sample_scale = 
	song->sample_array[track_nbr][beat_n];
}
// sample rate 44100
// bit depth 16
// channel count 2
//need as many signed integers as there are (seconds * 44100) in the song
// essentially building Pulse Code Modulation (PCM) system able to generate WAV file compatible data (without the WAV file)
// basically build waves, arrays of signed integers 
// the signed integers values are calculated by mathematical functions
// the waveforms are inserted in the array in ranges which factor in BPM, sample rate, and note duration.
// The Pulse Code waveform 
