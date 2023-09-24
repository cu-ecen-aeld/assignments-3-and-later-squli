#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

extern int errno;

int writer(const char * full_path_to_file, const char * s) {
    
    openlog(NULL, 0, LOG_USER);
    
    if (full_path_to_file == NULL || s == NULL) {
        syslog(LOG_ERR, "Arguments are incorrect: dir=%s, s=%s\n", full_path_to_file, s);
        return 1;
    }
    
    int outputFd = open(full_path_to_file, O_WRONLY | O_CREAT, 0777);
    if(outputFd == -1) {
        syslog(LOG_ERR, "Cant open file: dir=%s\n", full_path_to_file);
        return 1;
    }
    
    int return_value = 0;
    int err = write(outputFd, s, strlen(s));
    if (-1 == err) {
        syslog(LOG_ERR, "Cant write to file: dir=%s, err=%d\n", full_path_to_file, err);
        return_value = 1;
    } else if (err == strlen(s)) {
        syslog(LOG_DEBUG, "Writing %s to %s", s, full_path_to_file);
    } else {
        syslog(LOG_ERR, "Cant write to file all data: dir=%s, written=%d\n", full_path_to_file, err);
        return_value = 1;
    }
    
    if (0 != close(outputFd)) {
        syslog(LOG_ERR, "Cant close file: dir=%s\n", full_path_to_file);
        return_value = 1;
    }
    
    return return_value;
}

/* main.c */
int main(int argc, char *argv[]) {
    return writer(argv[1], argv[2]);
}

