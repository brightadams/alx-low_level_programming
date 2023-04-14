#include "main.h"

/**
 * main - this  copies the content of a file to another file
 * @argc: number of arguments passed to the program.
 * @argv: array of arguments.
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
    int fd_read, fd_write, bytes_read, close_read, close_write;
    char buffer[BUFSIZ];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }
    fd_read = open(argv[1], O_RDONLY);
    if (fd_read < 0)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }
    fd_write = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    while ((bytes_read = read(fd_read, buffer, BUFSIZ)) > 0)
    {
        if (fd_write < 0 || write(fd_write, buffer, bytes_read) != bytes_read)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            close(fd_read);
            exit(99);
        }
    }
    if (bytes_read < 0)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }
    close_read = close(fd_read);
    close_write = close(fd_write);
    if (close_read < 0 || close_write < 0)
    {
        if (close_read < 0)
            dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_read);
        if (close_write < 0)
            dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_write);
        exit(100);
    }
    return (0);
}

