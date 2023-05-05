int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(r) * 8)
		return (-1);
	return (n >> index & 0x01);
}
