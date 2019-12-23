#ifndef CMD_H
#define CMD_H

char * getCmd(char * buff){
    char * cmd = (char *) 0xb9000;
    int i = 0;

    for(; buff[i] != ' '; i++) cmd[i] = buff[i]; 
    cmd[i] = 0;

    return cmd;
}

char * getRest(char * buff){
    char * rest = (char *) 0xb9100;
    int i = 0, j = 0;

    for(; buff[i] != ' '; i++);
    i++;
    
    for(; buff[i] != '\0'; i++, j++) rest[j] = buff[i];
    rest[j] = 0;
    
    return rest;
}

#endif
