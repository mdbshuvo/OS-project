#ifndef STRING_H
#define STRING_H

int streq(char * first, char * second){
    int i;
    
    for(i = 0; first[i] != '\0'; i++){
        if(first[i] != second[i]){
            return 0;
        }
    }
    if(second[i] != '\0') return 0;

    return 1;
}

#endif
