#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
    // Check that exactly one command line argument is provided
    if (argc != 2) { 
        fprintf(stderr, "Please provide the file path.\n");
        return 1;
    }
    
    // Retrieve file information
    struct stat fileInfo;
    if (stat(argv[1], &fileInfo) != 0) {
        fprintf(stderr, "Error: file '%s' does not exist or cannot be accessed.\n", argv[1]);
        return 1;
    }
    
    // Print the file size in bytes
    printf("%ld\n", fileInfo.st_size);
    return 0;
}
