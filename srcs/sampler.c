//max_amplitude = pow(2, BIT_DEPTH - 1) - 1;


//float	degree_offset;
//calculate this as soon as the frequency is known
//for a given beat:
//degree_offset = 2 * PI * freq * SAMPLE_RATE;
int	i;
i = 0;
while (i < SAMPLE_RATE * note_duration)
{
	sample = sine_oscillator(freq, amp, degree_offset); //call this a fucking load of times.
	sample * max_amplitude;
	i++;
}

float	sine_oscillator(freq, amp, degree_offset)
{
	sample = amp * sin(wave_angle);
	wave_angle += degree_offset;
	return sample;
}
