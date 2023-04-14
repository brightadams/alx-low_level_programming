#include "main.h"

/**
 * read_textfile - this reads a text file and prints it to the standard output
 * @filename: this stores the name of the file to be read
 * @num_letters: this takes the number of letters to read and print
 * Return: the number of letters printed, or 0 if it failed
 */
ssize_t read_textfile(const char *filename, size_t num_letters)
{
    int fd;
    int read_len, write_len;
    char *buf;
    
    if (!filename)
        return (0);
    
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (0);
    
    buf = malloc(sizeof(char) * num_letters);
    if (!buf)
        return (0);
    
    read_len = read(fd, buf, num_letters);
    if (read_len < 0)
    {
        free(buf);
        return (0);
    }
    
    buf[read_len] = '\0';
    close(fd);
    
    write_len = write(STDOUT_FILENO, buf, read_len);
    if (write_len < 0)
    {
        free(buf);
        return (0);
    }
    
    free(buf);
    return (write_len);
}

