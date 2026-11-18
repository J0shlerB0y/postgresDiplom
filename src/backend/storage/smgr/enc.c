#include "storage/enc.h"

#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

bool enc_signal_file_exists(const char *name){
    struct stat buffer;
    
    return ( stat(name, &buffer) == 0);
}

void enc_create_signal_file(const char *fname){
    int fd;
    if ((fd = creat(fname, 0600)) < 0){
        //elog(ERROR, 'File creation error')
    }else{
        close(fd);
    }
}