#ifndef IO_H
#define IO_H

unsigned short* videoMemory = (unsigned short*) 0xb8000;


unsigned char inportb(unsigned short port){
    unsigned char rv;

    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (port));

    return rv;
}

void outportb(unsigned short port, unsigned char data){
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (port), "a" (data));
}

int cw = 80, ch = 25, cd = 2;
int cursorX = 0, cursorY = 0;

void updateCursor(){
    unsigned temp;
    temp = cursorX + cursorY * cw;

    outportb(0x3D4, 14);
    outportb(0x3D5, temp >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D5, temp);
}

void newLine(){
    cursorX = 0;
    cursorY += 1;

    updateCursor();
}


void clear(){
    int end = cw * ch;

    for(int cursorPoint = 0; cursorPoint < end; cursorPoint++)
        videoMemory[cursorPoint] = (videoMemory[cursorPoint] & 0xFF00) | ' ';  

    cursorY = 0;
    cursorX = 0;
    
    updateCursor();
}

void scrollUp(int lines){
    for(int i = 0; i < cw * ch; i++){
        videoMemory[i] = videoMemory[i + cw * lines];        
    }
    cursorY -= lines;
    
    if(cursorY < 0) cursorY = 0;

    updateCursor();
}

void print(char* str)
{
    int cursorPoint = cursorX + cursorY * cw;
    for(int i = 0; str[i] != '\0'; i++, cursorPoint++) {
        if(str[i] == 10){
            newLine();
            cursorPoint = cursorX + cursorY * cw - 1;
            continue;
        }
        if(str[i] == 8){
            cursorPoint = cursorX + cursorY * cw - 1;
            videoMemory[cursorPoint] = (videoMemory[cursorPoint] & 0xFF00) | ' ';
            cursorPoint = cursorX + cursorY * cw - 2;
            continue;
        }
        videoMemory[cursorPoint] = (videoMemory[cursorPoint] & 0xFF00) | str[i];
    }

    cursorY = cursorPoint / cw;
    cursorX = cursorPoint % cw;

    if(cursorY >= ch) {
        scrollUp(1);
    }
}

#endif
