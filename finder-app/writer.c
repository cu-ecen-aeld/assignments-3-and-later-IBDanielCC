#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <writefile> <writestr>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    // Open the file for writing
    FILE *file = fopen(writefile, "w");
    
    // Check if the file was opened successfully
    if (file == NULL) {
        syslog(LOG_ERR, "Error: Could not open file %s for writing", writefile);
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Write content to the file
    fprintf(file, "%s\n", writestr);

    // Close the file
    fclose(file);

    // Log the write operation using syslog
    openlog("fwriter", LOG_PID, LOG_USER);
    syslog(LOG_DEBUG, "Writing '%s' to '%s'", writestr, writefile);
    closelog();

    return EXIT_SUCCESS;
}

